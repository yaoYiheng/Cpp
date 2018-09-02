//
//  MyString.hpp
//  Day5
//
//  Created by 姚懿恒 on 2018/9/1.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef MyString_hpp
#define MyString_hpp
#include <ostream>
#include <stdio.h>

using namespace std;

class MyString {
private:
    int len;
    char *str;
    
public:
    //有参无参拷贝构造析构
    MyString();
    MyString(int len);//->用于创建一个长度为len的字符串数组.
    MyString(const char *str);//->以实现 Mystring a = "123"的效果.
    MyString(const MyString &newString); //->以实现 Mystring a = b的效果.
    ~MyString();
    friend ostream &operator<<(ostream &os, MyString &string);
    friend istream &operator>>(istream &is, MyString &string);
    //重载[]
    char & operator[](int index);

    //重载== !=
    bool operator==(const MyString &mystring);
    bool operator!=(const MyString &mystring);
    //重载=
    MyString& operator=(const MyString &str1);
    
    
};

#endif /* MyString_hpp */
