//
//  Animal.cpp
//  Day7
//
//  Created by 姚懿恒 on 2018/9/5.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <stdio.h>
#include "Animal.h"

Animal::~Animal()
{
    cout << "Animal析构"<< endl;
}
Animal::Animal()
{
    cout << "Animal构造" << endl;
}
void makeAnimalHowl(Animal *animal)
{
    animal->Howling();
    
    if(animal != NULL)
    {
        delete animal;
    }
}
