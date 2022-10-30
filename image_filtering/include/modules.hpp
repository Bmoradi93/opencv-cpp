/**
 * @file modules.hpp
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

#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>

#pragma once

namespace ns
{
    class myClass
    {
        public:
            myClass();
            ~myClass();

            void read_dataset(const std::string path2files, std::vector<std::string>& files);
            void read_camera();
            void show_dataset(const std::string path2files, std::vector<std::string>& files);
            void get_pixel_value(cv::Mat& image, int i, int j);
            void canny_edge_detection(cv::Mat& image, int threshold1, int threshold2);
            void filter_image(cv::Mat& image, cv::Scalar lower_threshold, cv::Scalar higher_threshold);

            private:
                cv::Scalar filtering_lower_threshold = cv::Scalar(0,0,200);
                cv::Scalar filtering_higher_threshold = cv::Scalar(170, 110, 255);
    };
}