//
//  Circle.cpp
//  Day2
//
//  Created by 姚懿恒 on 2018/8/24.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//
#include <iostream>
#include "Circle.hpp"
#include <math.h>
using namespace std;


bool Circle::isInCirle(myPoint &myPoint)
{
    
    float offset =
    (myPoint.getX() - m_Center.getX()) * (myPoint.getX() - m_Center.getX()) + (myPoint.getY() - m_Center.getY()) * (myPoint.getY() - m_Center.getY());
    
    offset = sqrt(offset);

    if (m_Radius  >= offset)
    {
        return true;
    }
    else
    {
        
        return false;
    }
}

void Circle:: setCenter(myPoint &center)
{
    m_Center = center;
}
myPoint Circle:: getCenter()
{
    return m_Center;
}
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


