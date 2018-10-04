//
//  MyArray.hpp
//  Day9
//
//  Created by 姚懿恒 on 2018/10/4.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef MyArray_hpp
#define MyArray_hpp

#include <stdio.h>
#include <iostream>

template <class T>
class MyArray {
public:
    int mCapacity;
    int mSize;
    T* pAddress;
    
public:
    MyArray() = default;
    MyArray(int capacity);
    MyArray(const MyArray<T> &array); //拷贝构造函数
    
    T& operator[](int index); //根据index返回在数组中对应对象的引用
    MyArray<T> operator=(const MyArray<T> &array);
    
    
    void pushBack(const T& data);
    
    
};

#endif /* MyArray_hpp */
