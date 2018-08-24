//
//  Circle.cpp
//  Day2
//
//  Created by 姚懿恒 on 2018/8/24.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//
#include <iostream>
#include "Circle.hpp"
using namespace std;


void Circle::setRaius(double newRadius)
{
    m_Radius = newRadius;
}
double Circle:: getRaius()
{
    return m_Radius;
}

double Circle::getPerimeter()
{
    m_Perimeter = 2 * m_Radius * 3.14;
    return m_Perimeter;
}

double Circle:: getArea()
{
    m_Area = 3.14 * m_Radius * m_Radius;
    return m_Area;
}
void Circle:: showInfo()
{
    cout << "半径 = " << m_Radius << endl;
    cout << "周长 = " << getPerimeter() << endl;
    cout << "面积 = " << getArea() << endl;
}


