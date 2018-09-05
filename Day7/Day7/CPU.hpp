//
//  CPU.hpp
//  Day7
//
//  Created by 姚懿恒 on 2018/9/5.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef CPU_hpp
#define CPU_hpp
#include "BaseCPU.hpp"
#include <stdio.h>
#include <iostream>
using namespace std;

class CPU: public BaseCPU
{
    string brand;
public:
    void calculate();
    CPU();
    CPU(string brand);
};
#endif /* CPU_hpp */
