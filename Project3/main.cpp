#include <iostream>
#include <opencv.hpp>
#include <math.h>
#include <vector>
#include <format>

OPENCV_ALL_HPP

using namespace cv;
using namespace cv::cuda;
using namespace std;

Mat draw_lines(string image_input_name) {
    std::string image_path = samples::findFile(image_input_name);
    Mat img, gray, edges;

    img = imread(image_path);
    cvtColor(img, gray, COLOR_BGR2GRAY, 0);
    Canny(gray, edges, 50, 150, 3);

    vector<Vec2f> lines;
    HoughLines(edges, lines, 1, CV_PI / 180, 150, 0, 0);

    Mat new_img;
    img.copyTo(new_img);

    for (int i = 0; i < lines.size(); ++i) {
        float rho = lines[i][0], theta = lines[i][1];
        double a = cos(theta), b = sin(theta);
        double x0 = a * rho, y0 = b * rho;
        Point p1(cvRound(x0 + 2000 * (-b)), cvRound(y0 + 2000 * (a)));
        Point p2(cvRound(x0 - 2000 * (-b)), cvRound(y0 - 2000 * (a)));
        printf("p1: (%d, %d)\tp2: (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);
        line(new_img, p1, p2, Scalar(0, 255, 0, 0.2), 2, LINE_4);
    }
    return new_img;
}

int main() {

    vector<Mat> imgs;
    int n = 18;

    for (int i = 0; i < n; ++i) {
        imgs.push_back(draw_lines(format("images/old/image%d.jpg", i)));
        imwrite(format("images/new/image%d.jpg", i), imgs.back());
    }
   
    waitKey();
	return 0;
}
