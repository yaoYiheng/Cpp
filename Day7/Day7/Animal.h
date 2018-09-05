//
//  Animal.h
//  Day7
//
//  Created by 姚懿恒 on 2018/9/5.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef Animal_h
#define Animal_h
#include <iostream>
using namespace std;
class Animal
{
public:
    virtual void Howling() = 0;
    Animal();
    virtual ~Animal();
};
//架构函数
void makeAnimalHowl(Animal *animal);
#endif /* Animal_h */
