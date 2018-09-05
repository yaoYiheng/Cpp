//
//  BaseCPU.hpp
//  Day7
//
//  Created by 姚懿恒 on 2018/9/5.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef BaseCPU_hpp
#define BaseCPU_hpp

#include <stdio.h>
#include <istream>
using namespace std;
class BaseCPU
{
private:
    string brand;
public:
    virtual void calculate() = 0;
    
    void setBrand(string brand);
    string getBrand();
    BaseCPU();
    BaseCPU(string brand);
};

#endif /* BaseCPU_hpp */
