//
//  main.cpp
//  Day1
//
//  Created by 姚懿恒 on 2018/9/7.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include <istream>

using namespace std;

template<typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
template<typename T>
void info(T &a, T &b)
{
    cout << "a = " << a<<", "<<"b = " << b << endl;
}
template<class T>
/*
 1. 函数模板可以像普通函数那样被重载.
 2. 编译器会优先调用普通函数.
 3.可以通过空模板实参列表的语法限定编译器只能通过模板匹配
 如: myAdd<>(a, b), 将强制调用模板函数.
 
 */

//函数模板必须严格类型匹配
int myAdd(T a, T b)
{
    return a + b;
}
//普通函数可以进行自动类型转换
int myAdd(int a, int b)
{
    return a + b;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    string a = "123";
//    string b = "1111";
//
//    mySwap(a, b);
//
//    info(a, b);
    int a = 10;
    int b = 11;

    cout << myAdd<>(a, b) << endl;
    
    
    return 0;
}
