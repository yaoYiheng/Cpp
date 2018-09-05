//
//  Memeory.hpp
//  Day7
//
//  Created by 姚懿恒 on 2018/9/5.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef Memeory_hpp
#define Memeory_hpp
#include "BaseMemory.hpp"
#include <stdio.h>
#include <iostream>
using namespace std;

class Memeory: public BaseMemory
{
private:
    string name;
    
    
public:
    void storage();
    Memeory();
    Memeory(string brand);
    ~Memeory();
    
};
#endif /* Memeory_hpp */
