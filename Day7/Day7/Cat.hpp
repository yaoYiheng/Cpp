//
//  Cat.hpp
//  Day7
//
//  Created by 姚懿恒 on 2018/9/5.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef Cat_hpp
#define Cat_hpp
#include "Animal.h"
#include <stdio.h>

class Cat:public Animal
{
public:
    void Howling();
    Cat();
    ~Cat();
    
};
#endif /* Cat_hpp */
