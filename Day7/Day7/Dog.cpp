//
//  Dog.cpp
//  Day7
//
//  Created by 姚懿恒 on 2018/9/5.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include "Dog.hpp"

void Dog::Howling()
{
    cout << "汪汪汪" << endl;
}
Dog::Dog()
{
    
}
Dog::~Dog()
{
    cout << "~Dog析构"<< endl;
}
