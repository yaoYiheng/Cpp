//
//  Screen.cpp
//  Chapter7
//
//  Created by 姚懿恒 on 2018/10/1.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include "Screen.hpp"

Screen &Screen::move(unsigned r, unsigned c)
{
    
    cursor = r * width + c;
    
    return *this;
}
char Screen::get(unsigned ht, unsigned wd) const
{
    pos row = ht * width;
    
    return contents[row + ht];
}

void Screen:: some_member() const
{
    ++access_ctr;
}

Screen &Screen::set(char c)
{
    this->contents[cursor] = c;
    
    return *this;
}

Screen &Screen::set(unsigned row, unsigned col, char ch)
{
    contents[row * width + col] = ch;
    
    return *this;
}

Screen::pos Screen::size() const
{
    return height * width;
}
