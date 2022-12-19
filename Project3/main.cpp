#include <iostream>
#include <opencv.hpp>

//для сокращения записи подключим пространства имен cv и std 
using namespace cv;
using namespace std;

//для удосбтва будем использовать собственную структуру линии
struct my_line {
    double rho, theta;      //параметры линии в полярной системе
    double k, b;            //параметры линии в декартовой системе
    Point p1, p2;           //ориентировочные точки отрезка лежащего на линии
    Point zeroPoint;        //нулевая точка в полярных координатах (представлена в декартовой системе)
    Point vec;              //условный направляющий вектор линии


    //конструктор получающий параметры в полярной системе
    my_line(Vec2f v) {
        rho = v[0];                                 //радиус
        theta = v[1];                               //угол
        getPoints(2000);                            //определяем точки отрезка линии
        vec = p2 - p1;                              //определяем направляющий вектор

        k = 1.0 * (p1.y - p2.y) / (p1.x - p2.x);    //считаем коэффициент угла наклона
        b = 1.0 * p1.y - k * p1.x;                  //считаем сдвиг по оси ОY
    }

    //функция получения услвной нулевой точки
    Point getZeroPoint() {
        return  Point(cvRound(cos(theta) * rho), cvRound(sin(theta) * rho));
    }

    //функция получения точек отрезка, принадлежащего линии
    pair<Point, Point> getPoints(int k) {
        double a = cos(theta), b = sin(theta);
        double x0 = a * rho, y0 = b * rho;
        p1 = Point(cvRound(x0 + k * (-b)), cvRound(y0 + k * (a)));
        p2 = Point(cvRound(x0 - k * (-b)), cvRound(y0 - k * (a)));
        return make_pair(p1, p2);
    }

    //функция отрисовки линии на изображении img
    void draw(Mat& img) {
        auto ps = getPoints(2000);
        line(img, ps.first, ps.second, Scalar(0, 255, 0, 0.2), 2, LINE_4);
    }
};

//функция получения точки пересечения двух линий
Point line_crossing(my_line l1, my_line l2) {
    Point answer(-1, -1);
    if (l1.k == 0 || l2.k == 0) {
        answer.y = (l1.k==0? l1.p1.y: l2.p1.y);
    }
    if (isinf(l1.k) || isinf(l2.k)) {
        answer.x = (isinf(l1.k) ? l1.p1.x : l2.p1.x);
    }

    my_line& l = isinf(l1.k)? l2: l1;

    if (answer.y != -1) {
        answer.x = answer.y - l.b / l.k;
    }
    else if (answer.x != -1) {
        answer.y = l.k * answer.x + l.b;
    }
    else {
        answer.x = (l2.b - l1.b) / (l1.k - l2.k);
        answer.y = l1.k * answer.x + l1.b;
    }
    return answer;
}


//функция решающая задачу о нахождении перекрестия на изображении img
void draw_lines(Mat& img) {
    Mat hsv, red, edges;

    //сначала нужно отсечь лишнее на фото и оставить только лазер 
    cvtColor(img, hsv, COLOR_BGR2HSV, 0);
    inRange(hsv, Scalar(143, 60, 200), Scalar(179, 256, 256), red);


    //далее получаем массив линий
    vector<Vec2f> lines;
    HoughLines(red, lines, 1, CV_PI / 180, 300, 0, 0);


    //обозначаем первую линию как одну из нужных
    my_line main_line(lines[0]);

    
    int min_eps = -1;
    int second_line_ind = -1;

    //далее рассматриваем все остальные точки и находим номер линии, наиболее перпендикулярной к первой
    for (int i = 1; i < lines.size(); ++i) {
        my_line l(lines[i]);
                
        int eps = abs(main_line.vec.x * l.vec.x + main_line.vec.y * l.vec.y);
        if (eps == 0) {break;}
        if (eps  < min_eps || min_eps == -1) {
            second_line_ind = i;
            min_eps = eps;
        }
    }

    //после этого определяем юту линию
    my_line second_line(lines[second_line_ind]);

    //рисуем их
    main_line.draw(img);
    second_line.draw(img);

    //определяем точку пересечения, и рисуем точку тоже
    Point cross_point = line_crossing(main_line, second_line);
    circle(img, cross_point, 15, Scalar(255, 255, 0));

}

//функция по обработки изображения с камеры
void proc_vid(string streamURL) {
    VideoCapture vid(streamURL);

    Mat frame;

    char key = 'a';

    while (true) {
        vid.grab();
        vid.retrieve(frame);
        draw_lines(frame);
        imshow("Image", frame);
        key = waitKey(10);
    }
}

//функция для обработки одного изображения
void proc_img(string imgName) {
    Mat new_img;
    Mat img = imread(imgName);
    draw_lines(img);
    imshow("Image", img);
    waitKey();
}

int main() {
    //для теста обработаем изображение
    //proc_img("images/test5.jpg");
    
    //зная адрес для получения видео с камеры, обрабатываем изображение с камеры
    proc_vid("rtsp://192.168.1.249:554/user=admin_password=tlJwpbo6_channel=1_stream=0.sdp?real_stream");
}
