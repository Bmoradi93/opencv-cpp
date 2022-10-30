/**
 * @file main.cpp
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

#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>

int main(int argc, char const *argv[])
{
    // Path to the dataset
    std::string path = "/home/behnam/git/opencv-cpp/dataset/baseline/highway/input/";
    //vector of images
    std::vector<std::string> files;

    ns::myClass my_class;
    my_class.read_dataset(path, files);
    my_class.show_dataset(path, files);
    // my_class.read_camera();
    return 0;
}
