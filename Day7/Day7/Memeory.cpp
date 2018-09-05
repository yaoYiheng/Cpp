//
//  Memeory.cpp
//  Day7
//
//  Created by 姚懿恒 on 2018/9/5.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include "Memeory.hpp"
void Memeory:: storage()
{
    cout << "内存开始存储..." << endl;
}
Memeory::Memeory()
{
    cout << "Memory构造" <<endl;
}
Memeory::~Memeory()
{
    cout << "Memory析构" <<endl;
}
Memeory::Memeory(string brand):BaseMemory(brand)
{
    this->setBrand(brand);
}
