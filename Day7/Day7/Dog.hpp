//
//  Dog.hpp
//  Day7
//
//  Created by 姚懿恒 on 2018/9/5.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef Dog_hpp
#define Dog_hpp

#include <stdio.h>
#include "Animal.h"

class Dog:public Animal
{
public:
    void Howling();
    Dog();
    ~Dog();

};
#endif /* Dog_hpp */
