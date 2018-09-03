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

    Human(string name)
    {
        this->name = name;
    }
    virtual void eat(string food)
    {
        cout << this->name << "吃了"<< food <<endl;
    }
    
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
public:
    Male(){}
    Male(string name)
    {
        this->name = name;
    }
    void eat(string food)
    {
        
    }
};

class Female: virtual public Human
{

public:
    Female()
    {
        
    }
    Female(string name)
    {
        this->name = name;
    }
    void eat(string food)
    {
        
    }
};

class LadyBoy: public Male, public Female
{
public:
    LadyBoy(string name)
    {
        this->name = name;
    }
    
    void eat(string food)
    {
        cout << this->name <<"吃了" << food << endl;
    }
public:
    void info()
    {
        cout << name << endl;
    }
};

void HumanEat(Human *human, string food)
{
    human->eat(food);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    Male m("bob");
    Female h("hilary");
    LadyBoy l("ladybody");
    
    HumanEat(&m, "香蕉");
    HumanEat(&h, "苹果");
    HumanEat(&l, "kiwi");
    return 0;
}
