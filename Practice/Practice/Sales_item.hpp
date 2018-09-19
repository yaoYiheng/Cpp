//
//  Sales_item.hpp
//  Practice
//
//  Created by 姚懿恒 on 2018/9/19.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef Sales_item_hpp
#define Sales_item_hpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

/*
 搞清楚了两个之前遗留的问题:
 问题1: 时常在.cpp文件中无法重写 >><< 操作符, 是因为没有包含iostream头文件!
 问题2: 重写了+运算符, 但是无法通过直接相加打印出相加后的结果?
 答: 是因为在重写<<运算符是时, 没有在第二个参数上加const关键字, 虽然也不知道为什么不加关键字会导致的问题, 至少解决了个问题.
 
 再次回顾inline 函数跟friend函数
 
 很奇怪的地方: 不知道是编译器的问题还是语法的问题,
 当我把!=的声明跟定义分开写时,是无法通过编译器的
 但是如果将声明更定义都写在.h文件中, 就能够成功的运行.
 */

class Sales_item
{
private:
    string bookNo;
    unsigned units_sold;
    double revenue;
    
public:
    Sales_item(){};
    ~Sales_item(){};
    Sales_item(const string &book): bookNo(book), units_sold(0), revenue(0.0){}
    
    string getBookNo() const;
    double averangePrice() const;
    
    //重载操作运算符
    
    //输入输出
    friend istream& operator>>(istream &, Sales_item &);
    friend ostream& operator<<(ostream &,const Sales_item &);
    

    //相等相加相加等
    Sales_item& operator+=(const Sales_item&);
    friend Sales_item operator+(const Sales_item&, const Sales_item&);
    
    //全等不等
    friend bool operator==(const Sales_item &, const Sales_item&);
    
    
    
};

//inline bool operator!=(const Sales_item &lhs, const Sales_item &rhs)
inline bool operator!=(const Sales_item &item1, const Sales_item item2)
{
    return !(item1 == item2);
}

#endif /* Sales_item_hpp */
