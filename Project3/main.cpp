
#include "MyForm.h"
#include <Windows.h>
using namespace Project3;

int main() {
	Application::Run(gcnew MyForm ());

	return 0;
}


/*
#include <iostream>
#include <opencv.hpp>
OPENCV_ALL_HPP

using namespace cv;
using namespace cv::cuda;

int main() {
    std::string image_path = samples::findFile("test_image.jpg");
    Mat img = imread(image_path, IMREAD_COLOR);
    if (img.empty())
    {
        printf("Could not read the image: %s\n", image_path.c_str());
        return 1;
    }
    imshow("Display window", img);
    int k = waitKey(0); // Wait for a keystroke in the window
    if (k == 's')
    {
        imwrite("test_image_save.png", img);
    }

    
	return 0;
}
*/