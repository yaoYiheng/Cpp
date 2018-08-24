//
//  Circle.hpp
//  Day2
//
//  Created by 姚懿恒 on 2018/8/24.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>

#endif /* Circle_hpp */

class Circle {
private:
    double m_Radius;
    double m_Perimeter;
    double m_Area;
    
public:
    void setRaius(double newRadius);
    
    double getRaius();
    
    double getPerimeter();
    
    double getArea();
    
    void showInfo();

    
};
