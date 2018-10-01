//
//  Person.cpp
//  Chapter7
//
//  Created by 姚懿恒 on 2018/9/30.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include "Person.hpp"


Person::Person(std:: string name, std:: string add)
{
    this->name = name;
    this->address = add;
}
std::istream & operator>>(std::istream &in, Person &person)
{
    in >> person.name >> person.address;
    
    return in;
}
std::ostream& operator<<(std::ostream &os, const Person &person)
{
    os << "姓名："<<person.name<<"地址："<< person.address<<std::endl;
    
    return os;
}
