//
//  MyArray.cpp
//  Day9
//
//  Created by 姚懿恒 on 2018/10/4.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include "MyArray.hpp"

template <class T>
MyArray<T>::MyArray(int capacity)
{
    this->mCapacity = capacity;
    this->mSize = 0;
    this->pAddress = new T[capacity];
}



template <class T>
void MyArray<T>:: pushBack(const T& data)
{
    if (this->mSize >= this->mCapacity)
    {
        return;
    }
    
    this->pAddress[this->mSize] = data;
    this->mSize++;
}
//上面的函数的重写，以便接受作为右值的形参。
template <class T>
void MyArray<T>:: pushBack(const T&& data)
{
    if (this->mSize >= this->mCapacity)
    {
        return;
    }
    
    this->pAddress[this->mSize] = data;
    this->mSize++;
}

//拷贝构造
template<class T>
MyArray<T>::MyArray(const MyArray<T> &array)
{
    this->mCapacity = array.mCapacity;
    this->mSize = array.mSize;
    
    this->pAddress = new T[this->mCapacity];
    for (int i = 0; i < this->mSize; ++i)
    {
        //需要注意的是，这里不是取array里的元素，而是array.pAddress里的元素
        this->pAddress[i] = array.pAddress[i];
    }
}
//析构函数
template<class T>
MyArray<T>::~MyArray()
{
    if (this->pAddress != NULL)
    {
        delete [] this->pAddress;
        this->pAddress = NULL;
    }
}
template <class T>
T& MyArray<T>::operator[](int index)
{
    return this->pAddress[index];
}


template<class T>
MyArray<T> MyArray<T>::operator=(const MyArray<T> &array)
{
    //如果在赋值前有值，将之前指向对空间清零
    if (this->pAddress != NULL)
    {
        delete [] this->pAddress;
    }
    
    this->mCapacity = array.mCapacity;
    this->mSize = array.mSize;
    //分配与形参大小一样的内存
    this->pAddress = new T[this->mCapacity];
    
    //将形参内的数据复制到新数组中
    for (int i = 0; i < array.mSize; ++i)
    {
        this->pAddress[i] = array.pAddress[i];
    }
    
    return *this;
    
}
