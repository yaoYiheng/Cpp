//
//  BaseCPU.cpp
//  Day7
//
//  Created by 姚懿恒 on 2018/9/5.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include "BaseCPU.hpp"


void BaseCPU::setBrand(string brand)
{
    this->brand = brand;
}
string BaseCPU:: getBrand()
{
    return this->brand;
}
BaseCPU::BaseCPU()
{
    
}
BaseCPU::BaseCPU(string brand)
{
    this->brand = brand;
}
