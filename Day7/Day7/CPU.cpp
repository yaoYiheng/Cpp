//
//  CPU.cpp
//  Day7
//
//  Created by 姚懿恒 on 2018/9/5.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include "CPU.hpp"
void CPU:: calculate()
{
    cout << "CPU开始显示" << endl;
}

CPU::CPU()
{
    
}
CPU::CPU(string brand):BaseCPU(brand)
{
    this->brand = brand;
}
