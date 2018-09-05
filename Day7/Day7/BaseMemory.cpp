//
//  BaseMemory.cpp
//  Day7
//
//  Created by 姚懿恒 on 2018/9/5.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include "BaseMemory.hpp"


BaseMemory:: BaseMemory()
{
    
}
BaseMemory:: ~BaseMemory()
{
    
}
void BaseMemory::setBrand(string brand)
{
    this->brand = brand;
}

string BaseMemory:: getBrand()
{
    return this->brand;
}

BaseMemory:: BaseMemory(string brand)
{
    this->brand = brand;
}
