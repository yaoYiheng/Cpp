//
//  MyString.cpp
//  Day5
//
//  Created by 姚懿恒 on 2018/9/1.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include "MyString.hpp"
#include <iostream>
using namespace std;

MyString::MyString()
{
    this->len = 0;
    this->str = NULL;
}
//->用于创建一个长度为len的字符串数组.
MyString::MyString(int len)
{
    this->len = len;
    this->str = new char[len + 1];
    
}

//MyString s1("123")
MyString::MyString(const char *str)
{

    //如果传入的是一个NULL, 则返回一个为""的字符串
    if (str == NULL)
    {
        this->len = 0;
        this->str = new char[0 + 1];
        strcpy(this->str, "");
    }
    else
    {
        this->len = (int)strlen(str);
        this->str = new char(strlen(str) + 1);
        strcpy(this->str, str);
    }
}
//拷贝构造函数. MyString s1 = s2;
MyString::MyString(const MyString &newString)
{
    this->len = newString.len;
    this->str = new char(newString.len + 1);
    
    strcpy(this->str, newString.str);
    
}
//析构函数
MyString::~MyString()
{
    
    cout << "调用析构" <<endl;
    if (this->str != NULL)
    {
        
        delete[] this->str;
        this->str = NULL;
        this->len = 0;
    }
}

MyString& MyString::operator=(const MyString &str1)
{
    //如果传入的相当, 在这里的&str1指的是str1的地址
    if (this == &str1)
    {
        return *this;
    }
    //this之前指向的内存需要释放
    if (str1.str  != NULL)
    {
        delete this->str;
        this->str = NULL;
        this->len = 0;
    }
    //开辟新空间
    if (str1.len >= 0)
    {
        this->len = str1.len;
        this->str = new char(str1.len + 1);
        strcpy(this->str, str1.str);
    }
    return *this;
    
    
}
//重载<< >>
ostream &operator<<(ostream &os, MyString &string)
{

    os << string.str <<endl;
    return os;
}
istream &operator>>(istream &is, MyString &string)
{
    cin >> string.str;
    return is;
}
