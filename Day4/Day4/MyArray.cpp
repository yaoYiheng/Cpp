//
//  MyArray.cpp
//  Day4
//
//  Created by 姚懿恒 on 2018/8/30.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include "MyArray.hpp"
MyArray::MyArray()
{
    m_length = 0;
    m_space = NULL;
}

MyArray:: MyArray(int len)
{
    //因为是要创建数值, 所以需要考虑输入的len的值是否合法
    if (len <= 0 )
    {
        m_length = 0;
        return;
    }
    else
    {
        m_length = len;
//        m_space = (int *)malloc(sizeof(int) * len);
        m_space = new int[m_length];
    }
    
    
}
MyArray::~MyArray()
{
    if (m_space != NULL) {
        
        delete[] m_space;
        
        m_space = NULL;
        
        m_length = 0;
    }
}
MyArray::MyArray(const MyArray &array)
{
    ////需要对index进行判断
    if (array.m_length >= 0) {
        m_length = array.m_length;
//        m_space = (int *)malloc(sizeof(int ) * array.m_length);
        m_space = new int[m_length];
        //如果之夜操作就相当于是两个指针指向了同一个地址, 在进行重新开辟内存空间之后, 只需要给新的重新赋值即可
//        m_space = array.m_space;
        for (int i = 0; i < m_length; i ++)
        {
            m_space[i] = array.m_space[i];
        }
    }
    
}
void MyArray::operator = (const MyArray &array)
{
    //先判断是否合法
    if (array.m_length >= 0)
    {
        this->m_length = array.m_length;
        this->m_space = new int[m_length];
        for (int i = 0; i < m_length; i++) {
            this->m_space[i] = array.m_space[i];
        }
    }
}
 int MyArray::getLength()
{
     return m_length;
}

void MyArray::setData(int index, int data)
{
    //需要对index进行判断
    if (m_space != NULL)
    {
        m_space[index] = data;
    }
    
}

int MyArray::getData(int index)
{
    //需要对index进行判断
    return m_space[index];
}
