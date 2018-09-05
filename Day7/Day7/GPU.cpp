//
//  GPU.cpp
//  Day7
//
//  Created by 姚懿恒 on 2018/9/5.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include "GPU.hpp"
void GPU:: display()
{
    cout << "GPU开始显示" << endl;
}

GPU::GPU()
{
    
}
GPU::GPU(string brand):BaseGPU(brand)
{
    this->brand = brand;
}

