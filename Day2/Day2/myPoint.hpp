//
//  myPoint.hpp
//  Day2
//
//  Created by 姚懿恒 on 2018/8/24.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef myPoint_hpp
#define myPoint_hpp

#include <stdio.h>
class myPoint
{
private:
    float m_X;
    float m_Y;
    
public:
    void setXandY(float x, float y);
    float getX();
    float getY();
};

#endif /* myPoint_hpp */

