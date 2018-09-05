//
//  GPU.hpp
//  Day7
//
//  Created by 姚懿恒 on 2018/9/5.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef GPU_hpp
#define GPU_hpp
#include "BaseGPU.hpp"
#include <stdio.h>
#include <iostream>
using namespace std;

class GPU: public BaseGPU
{
    string brand;
public:
    void display();
    GPU();
    GPU(string brand);
};
#endif /* GPU_hpp */
