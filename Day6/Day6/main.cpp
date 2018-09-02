//
//  main.cpp
//  Day6
//
//  Created by 姚懿恒 on 2018/9/2.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Human
{
private:
    int love;
protected:
    int money;
public:
    string name;
    Human()
    {
        
    }
    Human(int love, int money, string name)
    {
        this->love = love;
        this->money = money;
        this->name = name;
    }
    
};
class Student: protected Human
{
private:
    int id;
    
public:
    Student()
    {
        
    }
    Student(int love, int money, string name, int id):Human(love, money, name)
    {
        this->id = id;
    }
    
    void info()
    {
        cout << name;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Student s1;
    
    return 0;
}
