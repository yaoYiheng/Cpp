//
//  Hero.hpp
//  Day9
//
//  Created by 姚懿恒 on 2018/10/3.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef Hero_hpp
#define Hero_hpp

#include <stdio.h>
#include <iostream>

template <class T>
class Hero
{
    
public:
    static int count;
private:
    T mAge;
    
public:
    Hero() = default;
    
    Hero(T age);
    
    template<class Sclass>
    friend std::ostream &operator<<(std::ostream &, const Hero<Sclass> &);
    
    void show();
};

#endif /* Hero_hpp */
