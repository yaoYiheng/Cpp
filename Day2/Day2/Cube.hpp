//
//  Cube.hpp
//  Day2
//
//  Created by 姚懿恒 on 2018/8/24.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef Cube_hpp
#define Cube_hpp

#include <stdio.h>
#include "Point.hpp"


class Cube
{
private:
    Point m_Center;
    float m_Length;
    float m_Width;
    float m_Height;
    float m_Area;
    float m_Volume;
    
public:

    bool isEqual(Cube &newCube);
    float getVolume(float len, float wid, float height);
    float getArea(float len, float wid, float height);
    void setLWH(float len, float wid, float height);
    
};
#endif /* Cube_hpp */
