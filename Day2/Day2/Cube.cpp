//
//  Cube.cpp
//  Day2
//
//  Created by 姚懿恒 on 2018/8/24.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include "Cube.hpp"


bool Cube:: isEqual(Cube &newCube)
{
    if (m_Volume == newCube.m_Volume)
    {
        return true;
    }
    else
    {
        return false;
    }
}

float Cube:: getVolume(float len, float wid, float height)
{
    m_Volume = len * wid *height;
    return m_Volume;
}
void Cube:: setLWH(float len, float wid, float height)
{
    m_Length = len;
    m_Width = wid;
    m_Height = height;
}
float Cube::getArea(float len, float wid, float height)
{
    m_Area = (len * wid) * 2 + (len * height) * 2 + (wid * height) * 2;
    
    return m_Area;
}

