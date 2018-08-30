//
//  MyArray.hpp
//  Day4
//
//  Created by 姚懿恒 on 2018/8/30.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef MyArray_hpp
#define MyArray_hpp
#include <stdio.h>
#include <iostream>
using namespace std;
class MyArray
{
private:
    int m_length;
    int *m_space;

public:
    MyArray();

    MyArray(int len);
    MyArray(const MyArray &array);
    ~MyArray();
    
    void setData(int index, int data);
    int getData(int index);
    int getLength();
    MyArray& operator=(const MyArray &array);
    bool operator==(const MyArray &array);
    int& operator[](int index);
    friend ostream &operator<<(ostream &os, MyArray &array);
    friend istream &operator>>(istream &is, MyArray &array);
};


#endif /* MyArray_hpp */
