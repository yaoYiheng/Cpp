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
        this->str = new char[this->len + 1];
        strcpy(this->str, str);
    }
}
//拷贝构造函数. MyString s1 = s2;
MyString::MyString(const MyString &newString)
{
    this->len = newString.len;
    this->str = new char[newString.len + 1];
    
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
        delete[] this->str;
        this->str = NULL;
        this->len = 0;
    }
    //开辟新空间
    if (str1.len >= 0)
    {
        this->len = str1.len;
        this->str = new char[str1.len + 1];
        strcpy(this->str, str1.str);
    }
    return *this;
    
    
}
//重载== !=
bool MyString::operator==(const MyString &mystring)
{
    //如果两个字符串的长度不等, 那么不等
    if (this->str != mystring.str)
    {
        return false;
    }
    //遍历每一个元素, 如果有元素不同, 则不相等
    for (int i = 0;i < mystring.len; i++)
    {
        if (this->str[i] != mystring.str[i])
        {
            return false;
        }
    }
    //排除以上两种可能性,能来到这里就是相等的.
    return true;
}
bool MyString::operator!=(const MyString &mystring)
{
    return !(*this == mystring);
}
//重载[]
char & MyString::operator[](int index)
{
    //未做越界判断
    return this->str[index];
}

//重载+
MyString MyString::operator+(MyString &string)
{
    //临时temp
    MyString temp;
    //计算新开辟的string的长度
    int len = this->len + string.len;
    temp.len = len;
    temp.str = new char[len + 1];
    
    //清空temp之前的内存内容
    
    
    //字符串拼接
    strcpy(temp.str, this->str);
    strcat(temp.str, string.str);
    
    return temp;
}
//重载<< >>
ostream &operator<<(ostream &os, MyString &string)
{

    os << string.str <<endl;
    return os;
}
istream &operator>>(istream &is, MyString &string)
{
    cout<< "请输入:" <<endl;
//    cin >> string.str;
    //1. 清除之前的内存空间,
    if (string.str != NULL)
    {
        delete[] string.str;
        string.str = NULL;
        string.len = 0;
    }
    
    //2. 开辟临时空间, 保存传入的字符串, 在赋值
    char temp[4096] = {0};
    //往新开辟的空间内写入数据
    cin >> temp;
    
    string.len = (int)strlen(temp);
    //开辟与传入字符串相同长度的空间 + 1for \0
    string.str = new char[strlen(temp) + 1];
    strcpy(string.str, temp);

    return is;
}
