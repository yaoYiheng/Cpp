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
    static int amout;
protected:
    int money;
public:
    string name;
    
    
    
    static int &getAmout()
    {
        return amout;
    }
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
int Human:: amout = 100;
class Student: public Human
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

class Male: virtual public Human
{
    
};

class Female: virtual public Human
{
    
};

class LadyBoy: public Male, public Female
{
    
    
public:
    void info()
    {
        cout << name << endl;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    Human h1;
    Student s1;
    cout << h1.getAmout();
    cout << Human::getAmout();
    cout << s1.getAmout();
//    s1.info();
    return 0;
}
