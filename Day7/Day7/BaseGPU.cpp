//
//  BaseGPU.cpp
//  Day7
//
//  Created by 姚懿恒 on 2018/9/5.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include "BaseGPU.hpp"

void BaseGPU:: setBrand(string brand)
{
    this->brand = brand;
}
string BaseGPU:: getBrand()
{
    return this->brand;
}
BaseGPU::BaseGPU(string brand)
{
    this->brand = brand;
}
BaseGPU::BaseGPU()
{
    
}
