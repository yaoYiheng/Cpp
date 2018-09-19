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

void TestOne()
{
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
    
    
}

template <class T>

/**
 冒泡排序, 升序

 @param target 给定数组
 @param len 数组长度
 */
void sort(T *target, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            //
            if (target[i] > target[j])
            {
                T temp = target[i];
                target[i] = target[j];
                target[j] = temp;
            }
        }
    }
}

template <class T>
void info(T *target, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << target[i] << " ";
    }
}


void TestTwo()
{
    
    char mychar[] = {'z','a', 'g','c', 'p', 't', 'w','b'};
    
    int len = sizeof(mychar) / sizeof(char);
    
    cout << "原数组: " <<endl;
    
    info(mychar, len);
    
    
    cout <<  endl;
    sort(mychar, len);
    
    cout << "冒泡后: " <<endl;
    
    info(mychar, len);
    cout << endl;
    
    int myArray[] = {12, 32, 100, -1, 31, 0};
    
    int arrLen = sizeof(myArray) / sizeof(int);
    
    sort(myArray, arrLen);
    
    info(myArray, arrLen);
    cout << endl;
    
}


int main(int argc, const char * argv[]) {

    string line;
    //getline()函数只要一遇到换行符就结束读取操作并返回结果.
    while (getline(cin, line))
    {
        //遇到空行跳过.
        if(!line.empty())
        {
            cout << line << endl;
        }
        
        //每次读入一整行, 输出其中超过80个字符的行
        if (line.size() > 80)
        {
            cout << line << endl;
        }
    }

    return 0;
}
