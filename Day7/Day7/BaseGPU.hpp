//
//  BaseGPU.hpp
//  Day7
//
//  Created by 姚懿恒 on 2018/9/5.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef BaseGPU_hpp
#define BaseGPU_hpp

#include <stdio.h>
#include <istream>
using namespace std;
class BaseGPU
{
    
private:
    string brand;
public:
    
    virtual void display() = 0;
    
    void setBrand(string brand);
    string getBrand();
    BaseGPU(string brand);
    BaseGPU();
};

#endif /* BaseGPU_hpp */
