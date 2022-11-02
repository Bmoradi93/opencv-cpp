/**
 * @file mmodules.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <list>

#include "modules.h"

namespace ns
{
    CoreFuncClass::CoreFuncClass()
    {
        std::cout << "The CoreFuncClass is constructed." << std::endl;
    }

    CoreFuncClass::~CoreFuncClass()
    {
        std::cout << "The CoreFuncClass is distructed." << std::endl;
    }

    const cv::Mat CoreFuncClass::readImage(std::string image_path)
    {
        std::cout << "Reading imnage from the disk..." << std::endl;
    }
}