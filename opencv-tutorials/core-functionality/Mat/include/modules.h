/**
 * @file modules.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <cmath>
#include <vector>
#include <list>

namespace ns
{
    // cf: Stands for core functionality of opencv library
    class CoreFuncClass
    {
    public:

        CoreFuncClass();

        ~CoreFuncClass();

        const cv::Mat readImage(std::string image_path);

    };
}