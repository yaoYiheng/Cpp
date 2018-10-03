//
//  Hero.cpp
//  Day9
//
//  Created by 姚懿恒 on 2018/10/3.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include "Hero.hpp"

template <class T>
Hero<T>::Hero(T age)
{
    this->mAge = age;
}
//
template<class Sclass>
std::ostream &operator<<(std::ostream &os, const Hero<Sclass> &hero)
{
    os << hero.mAge << std::endl;
    return os;
}

template <class T>
void Hero<T>:: show()
{
    std::cout << this->mAge << std::endl;
}

template<class T>
int Hero<T>::count = 0;
