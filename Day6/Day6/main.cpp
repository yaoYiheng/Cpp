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
    void info()
    {
        cout << "info" <<endl;
    }
};
class Student: protected Human
{
private:
    int id;
    
public:
    string name;
    
    Student()
    {
        info();
        
    }
    Student(int love, int money, string name, int id):Human(love, money, name)
    {
        this->id = id;
        
    }
    
    void info()
    {
        
        //如果子类和父类出现同名变量, 访问子类可加this, 访问父类可加父类名称::访问
        cout << Human::name <<endl;
        cout << this->name;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    
    
    Student s1;
//    s1.info();
    return 0;
}
