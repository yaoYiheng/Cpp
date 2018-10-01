//
//  Screen.hpp
//  Chapter7
//
//  Created by 姚懿恒 on 2018/10/1.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef Screen_hpp
#define Screen_hpp

#include <stdio.h>
#include <iostream>

class Screen
{
public:
    
    /*
     string::size_type从本质上来说，是一个整型数
     
     string抽象意义是字符串， size（）的抽象意义是字符串的尺寸
     string::size_type抽象意义是尺寸单位类型
     
　　  string::size_type它在不同的机器上，长度是可以不同的，并非固定的长度。但只要你使用了这个类型，就使得你的程序适合这个机器。与实际机器匹配。
    
     */
//    typedef std::string::size_type pos;
    //使用别名，与上面的表述一样
    //必须先定义 后使用
    using pos = std::string ::size_type;
    
    
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    
    std::string contents;
    
    
public:
    //必须显示声明该构造函数因为该类中嗨哟其他构造函数
    Screen() = default;
    Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht * wd, c){}
    
    char get() const {return contents[cursor];} //隐式内联
    inline char get(pos ht, pos wd) const;//显示内敛
    
    Screen& move(pos r, pos c); //能在之后被设为内联
};

#endif /* Screen_hpp */
