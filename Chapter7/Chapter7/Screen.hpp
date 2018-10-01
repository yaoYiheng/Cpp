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

    friend class WindowManger;
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
    unsigned cursor = 0;
    unsigned height = 0, width = 0;
    
    std::string contents;
    
    //一个可变数据成员，永远不会是const，即使他是const对象的成员。因此一个const成员函数可以改变一个可变成员函数的值。
    mutable size_t access_ctr;
    
public:
    //必须显示声明该构造函数因为该类中含有其他构造函数
    Screen() = default;
    Screen(unsigned ht, unsigned wd, char c):height(ht), width(wd), contents(ht * wd, c){}
    
    char get() const {return contents[cursor];} //隐式内联
    inline char get(unsigned ht, unsigned wd) const;//显示内敛
    
    Screen& move(unsigned r, unsigned c); //能在之后被设为内联
    
    void some_member() const;
    
    Screen &set(char);
    Screen &set(unsigned, unsigned, char);
    
    
    const Screen& display(std::ostream &os) const {do_display(os); return *this;}
    Screen& display(std:: ostream &os) {do_display(os); return *this;}
    
    Screen& display(){std::cout << contents; return *this;}
    
private:
    //定义为私有成员，有它负责打印的实际工作，所有的display函数都会调用这个
    void do_display(std::ostream &os) const {os << contents;}
    
};

#endif /* Screen_hpp */
