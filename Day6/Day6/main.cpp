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
        cout << this->name << "吃了" << food << endl;
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

void TestOne()
{
    
    Male m("bob");
    Female h("hilary");
    LadyBoy l("ladybody");
    
    HumanEat(&m, "香蕉");
    HumanEat(&h, "苹果");
    HumanEat(&l, "kiwi");
}
class A
{
public:
    A()
    {
        cout << "A无参构造"<< endl;
        this->p = new char[64];
        memset(this->p, 0, 64);
        strcpy(this->p, "A");
    }
    
    virtual void info()
    {
        cout << "A" << this->p <<endl;
    }
    
    /**
     在父类的析构函数前加上virtual关键字以实现析构函数的多态, 当子类的析构函数被触发时,
     就能达到析构父类的效果.
     */
    virtual ~A()
    {
        cout << "A析构" << endl;

        if (this->p != NULL)
        {
            delete[] this->p;
            this->p = NULL;
        }
    }
private:
    
    char *p;
};

class B:public A
{
private:
    char *p;
    
public:
    B()//因为是继承自A类, 所以说在构造函数B触发时, 会先触发A的构造函数
    {
        cout << "B无参构造"<< endl;
        this->p = new char[64];
        memset(this->p, 0, 64);
        strcpy(this->p, "B");
    }
    
    void info()
    {
        cout << "B" << this->p <<endl;
    }
    ~B()
    {
        cout << "B析构" << endl;
        if (this->p != NULL)
        {
            delete[] this->p;
            this->p = NULL;
        }
    }
};

/**
 在这里发生了多台

 @param ap 父类对象的指针
 */
void func(A *ap)
{
    ap->info();
    delete ap;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

//    A aobj;
//    A *a = new A;
//    func(a);
    B *bobj = new B;
    func(bobj);
//    B aobj;
    
    TestOne();
    return 0;
}
