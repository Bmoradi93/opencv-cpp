/**
 * @file modules.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <sys/types.h>
#include <dirent.h>
#include "../include/modules.hpp"

// #include <opencv4/opencv2/opencv.hpp>
// #include <opencv4/opencv2/imgproc.hpp>
// #include <opencv4/opencv2/highgui.hpp>
// #include <opencv4/opencv2/imgcodecs.hpp>

// using namespace cv;

namespace ns
{
    myClass::myClass()
    {
        std::cout << "An object is constructed!" <<std::endl;
    }

    myClass::~myClass()
    {
        std::cout << "An object is distructed!" <<std::endl;
    }

    void myClass::read_dataset(const std::string path2files, std::vector<std::string>& files)
    {
        DIR* dirp = opendir(path2files.c_str());
        struct dirent * dp;
        while ((dp = readdir(dirp)) != NULL)
        {
            files.push_back(path2files + dp -> d_name);
            std::cout << path2files + dp -> d_name << std::endl;
        }
        closedir(dirp);
    }

    void myClass::get_pixel_value(cv::Mat& image, int i, int j)
    {
        cv::Vec3b pixelValue = image.at<cv::Vec3b>(i, j);
        std::cout << "Pixel Value: " << pixelValue << std::endl;
    }

    void myClass::show_dataset(const std::string path2files, std::vector<std::string>& files)
    {
        cv::Mat img;
        for (std::vector<std::string>::iterator itr = files.begin(); itr != files.end(); itr++)
        {
            std::sort (files.begin(), files.end());
            std::cout << *itr << std::endl;
            // std::cout << *itr << std::endl;
            std::string image_name = *itr;

            if (std::string::npos == image_name.find(".jpg"))
            {
                continue;
            }

            img = cv::imread(image_name);
            // std::cout << img << std::endl;
            myClass::canny_edge_detection(img, 10, 13);
            cv::imshow("img", img);
            int ch = cv::waitKey(0);
        }
    }

    void myClass::read_camera()
    {
        cv::Mat image;
        std::cout << "An attempt was made to read the camera!" << std::endl;
        cv::VideoCapture video_stream = cv::VideoCapture(-1);

        while (video_stream.grab())
        {
            video_stream.read(image);
            imshow("image", image);
            int ch = cv::waitKey(10);

            if (char(ch) == 'q')
            {
                break;
            }
        }
    }

    void myClass::canny_edge_detection(cv::Mat& image, int threshold1, int threshold2)
    {
        cv::Mat gray;
        cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
        cv::blur(gray, gray, cv::Size(5,5));
        cv::Mat edge_image;
        cv::Canny(gray, edge_image, threshold1, threshold2);
        cv::imshow("edge_image", edge_image);
        cv::waitKey(10);
        
    }
}
