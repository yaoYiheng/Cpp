//
//  Screen.cpp
//  Chapter7
//
//  Created by 姚懿恒 on 2018/10/1.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include "Screen.hpp"

inline Screen &Screen::move(Screen::pos r, Screen::pos c)
{
    pos row = r * width;
    cursor = row + c;
    
    return *this;
}
char Screen::get(Screen::pos ht, Screen::pos wd) const
{
    pos row = ht * width;
    
    return contents[row + ht];
}
