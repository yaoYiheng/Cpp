//
//  Person.hpp
//  Chapter7
//
//  Created by 姚懿恒 on 2018/9/30.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <iostream>

class Person {
private:
    std::string name;
    std::string address;
    
public:
    Person(){};
    Person(std:: string name, std:: string add);

    friend std::istream & operator>>(std::istream &in, Person &);
    friend std::ostream& operator<<(std::ostream &os, const Person &);
    
    std::string getName() const{return this->name;}
    std::string getAddress() const{return this->address;}
};


#endif /* Person_hpp */
