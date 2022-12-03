#include <iostream>
#include <opencv.hpp>
#include <math.h>
#include <vector>
#include <format>

OPENCV_ALL_HPP

using namespace cv;
using namespace cv::cuda;
using namespace std;

void draw_lines(Mat& img, Mat& new_img) {
    Mat gray, edges;

    cvtColor(img, gray, COLOR_BGR2GRAY, 0);
    Canny(gray, edges, 50, 150, 3);

    vector<Vec2f> lines;
    HoughLines(edges, lines, 1, CV_PI / 180, 250, 0, 0);

    img.copyTo(new_img);

    for (int i = 0; i < lines.size(); ++i) {
        float rho = lines[i][0], theta = lines[i][1];
        double a = cos(theta), b = sin(theta);
        double x0 = a * rho, y0 = b * rho;
        Point p1(cvRound(x0 + 2000 * (-b)), cvRound(y0 + 2000 * (a)));
        Point p2(cvRound(x0 - 2000 * (-b)), cvRound(y0 - 2000 * (a)));
        line(new_img, p1, p2, Scalar(0, 255, 0, 0.2), 2, LINE_4);
    }
}

int main() {
    VideoCapture vid("rtsp://192.168.1.249:554/user=admin_password=tlJwpbo6_channel=1_stream=0.sdp?real_stream");
    {
        cout << "\ncould not capture\n";
    }

    Mat frame, proc_frame;
    char key = 'a';

    while (true)
    {
        vid.grab();
        vid.retrieve(frame);
        draw_lines(frame, proc_frame);
        imshow("Image", frame);
        imshow("Processed image", proc_frame);
        key = waitKey(10);
    }
	return 0;
}
