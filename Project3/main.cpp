#include <iostream>
#include <opencv.hpp>
#include <math.h>
#include <vector>
#include <format>
#include <string>

OPENCV_ALL_HPP

using namespace cv;
using namespace cv::cuda;
using namespace std;

struct my_line {
    double rho, theta;
    double k, b;
    Point p1, p2;
    Point zeroPoint;
    Point vec;

    my_line(Vec2f v) {
        rho = v[0];
        theta = v[1];
        getPoints(2000);
        vec = p2 - p1;

        k = 1.0 * (p1.y - p2.y) / (p1.x - p2.x);
        b = 1.0 * p1.y - k * p1.x;
    }

    Point getZeroPoint() {
        return  Point(cvRound(cos(theta) * rho), cvRound(sin(theta) * rho));
    }

    pair<Point, Point> getPoints(int k) {
        double a = cos(theta), b = sin(theta);
        double x0 = a * rho, y0 = b * rho;
        p1 = Point(cvRound(x0 + k * (-b)), cvRound(y0 + k * (a)));
        p2 = Point(cvRound(x0 - k * (-b)), cvRound(y0 - k * (a)));
        return make_pair(p1, p2);
    }

    void draw(Mat& img) {
        auto ps = getPoints(2000);
        line(img, ps.first, ps.second, Scalar(0, 255, 0, 0.2), 2, LINE_4);
    }
};

Point line_crossing(my_line l1, my_line l2) {
    Point answer;
    if (l1.k == 0 || l2.k == 0) {
        answer.y = (l1.k==0? l1.p1.y: l2.p1.y);
    }
    if (isinf(l1.k) || isinf(l2.k)) {
        answer.x = (isinf(l1.k) ? l1.p1.x : l2.p1.x);
    }

    answer.x = (l2.b - l1.b) / (l1.k - l2.k);
    answer.y = l1.k*answer.x + l1.b;
    return answer;
}

void draw_lines_new(Mat& img) {
    Mat hsv, red, edges;

    cvtColor(img, hsv, COLOR_BGR2HSV, 0);
    inRange(hsv, Scalar(143, 60, 200), Scalar(179, 256, 256), red);

    vector<Vec2f> lines;
    HoughLines(red, lines, 1, CV_PI / 180, 300, 0, 0);

    //red.copyTo(img);

    Point pCenter(10, 10);
    my_line main_line(lines[0]);

    int min_eps = -1;
    int second_line_ind;

    for (int i = 1; i < lines.size(); ++i) {
        my_line l(lines[i]);
                
        int eps = abs(main_line.vec.x * l.vec.x + main_line.vec.y * l.vec.y);
        if (eps == 0) {break;}
        if (eps  < min_eps || min_eps == -1) {
            second_line_ind = i;
            min_eps = eps;
        }
    }
    my_line second_line(lines[second_line_ind]);

    //main_line.draw(img);
    //second_line.draw(img);

    Point cross_point = line_crossing(main_line, second_line);
    //circle(img, cross_point, 15, Scalar(255, 255, 0));

}

void proc_vid(string streamURL) {
    VideoCapture vid(streamURL);

    Mat frame;

    char key = 'a';

    while (true)
    {
        vid.grab();
        vid.retrieve(frame);
        draw_lines_new(frame);
        imshow("Image", frame);
        key = waitKey(10);
    }
}

void proc_img(string imgName) {
    Mat new_img;
    Mat img = imread(imgName);
    draw_lines_new(img);
    imshow("Image", img);
    waitKey();
}

int main() {
    //proc_img("images/test2.jpg");
    proc_vid("rtsp://192.168.1.249:554/user=admin_password=tlJwpbo6_channel=1_stream=0.sdp?real_stream");
}
