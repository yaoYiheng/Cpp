//
//  BaseMemory.hpp
//  Day7
//
//  Created by 姚懿恒 on 2018/9/5.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef BaseMemory_hpp
#define BaseMemory_hpp
#include <stdio.h>
#include <istream>
using namespace std;

class BaseMemory
{
    string brand;
public:
    BaseMemory();
    BaseMemory(string brand);
    virtual ~BaseMemory();
    virtual void storage() = 0;
    
    void setBrand(string brand);
    string getBrand();
};

#endif /* BaseMemory_hpp */
