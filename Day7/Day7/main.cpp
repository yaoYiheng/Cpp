//
//  main.cpp
//  Day7
//
//  Created by 姚懿恒 on 2018/9/4.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 验证vptr的存在,
 写两个不存在继承关系的类, 初始化两个对象, 并使用sizeof确定其大小, 应该就是其中含有的成员变量所
 占的大小.
 在其中一个类中添加一个虚函数, 再次打印,会发现, 添加了虚函数的大小会多出一个指针的大小, 再往其中添加虚函数, 并不会该变打下, 因为只是一个指向虚函数列表的指针而已,
 
 */

class A
{
    int a;
    virtual void func(){}
    virtual void func1(){}
};

class B
{
    int a;
    void func(){}
};
class Parent
{
    
public:
    Parent()
    {
        this->a = 0;
        func();
    }
    Parent(int a)
    {
        cout << "父类Parent(int a)被调用" << endl;
        this->a = a;
        
        func();
    }
    //
    virtual void testInChild()
    {
        cout << "在testInChild父类 调用" << endl;
    }
    
    virtual void func()
    {
        cout << "父类func被调用" << endl;
    }
    virtual void f() { cout << "Base::f" << endl; }
    
    virtual void g() { cout << "Base::g" << endl; }
    
    virtual void h() { cout << "Base::h" << endl; }
    
    int a;
};
typedef void(*Func)(void);
class Child : public Parent
{
    
public:
    
    Child():Parent()
    {
        
        this->b = 0;
    }
    Child(int a, int b):Parent(a)
    {
        func();
        cout << "子类Child(int a, int b):Parent(a)被调用" << endl;
        this->b = b;
    }
    int a;
    int b;
    
    void func()
    {
        cout << "子类func被调用" << endl;
    }
    void testInChild()
    {
        cout << "这是在子类中调用" << endl;
    }
};

void myFunc(Parent * pp)
{
    pp->func();
}

void TestOne()
{
    A a;
    B b;
    
    cout << "sizeA = " << sizeof(a) << endl;
    cout << "sizeb = " << sizeof(b) << endl;
    
    
    Parent *pp = new Child(12, 23);
    cout << "sizePP = " << sizeof(pp) << endl;
    
    Child *cp = new Child();
    pp->func();//如果调用的是一个不再虚函数列表内的普通函数, 那么编译器根本不会去查找虚函数列表, 只有当调用的是虚函数时, 才会去查找虚函数列表
    
    pp->testInChild();// 指向子类对象的父类指针, 不能够调用子类中, 不存在与父类的函数.
    //如果想通过指向子类对象的父类指针调用在子类中与父类完全相同的函数, 则需要在父类中, 给那个函数添加virtual
}

class Father {
   
    
private:
public:
    int a;
    
    
    Father(){}
    
    Father(int a)
    {
        this->a = a;
    }
    
    virtual void info()
    {
        cout << "Father:: info a = " << a << endl;
    }
};

class Son:public Father
{
public:
    int b;
    int c;
    Son():Father(){}
    Son(int a):Father(a)
    {
        
    }
    void info()
    {
        cout << "Son:: info a = " << a << endl;
    }
};

void TestTwo()
{
    // insert code here...
    
    Son array[] = {Son(0), Son(1), Son(2)};
    cout << "sizeof = "<< sizeof(array) << endl;
    Father *fp = &array[0];
    Son *cp = &array[0];
    
#if 0
    fp->info();
    cp->info();
    fp++; //fp+sizeof(Parent)
    cp++;//cp+sizeof(Child)
    fp->info();
    cp->info();
#endif
    
    int i = 0;
    for (cp = &array[0], i = 0; i< 3; i ++, cp++)
    {
        cp->info();
    }
    
}
//如果一个类中含有纯虚函数, 那么这个类就是抽象类, 抽象类是不能被实例化的.
//继承了抽象类却没有实现纯虚函数的类也是抽象类
class Shape
{
public:
    virtual double getArea() = 0;
};

class Rect: public Shape
{
private:
    int a;
public:
    Rect(int a)
    {
        this->a = a;
    }
    
    double getArea()
    {
        return a * a;
    }
};

class Circle: public Shape
{
private:
    int r;
    
public:
    Circle()
    {
        this->r = 0;
    }
    Circle(int r)
    {
        this->r = r;
    }
    double getArea()
    {
        return 3.14 * 2 * r;
    }
};

class Triangle:public Shape
{
private:
    int w;
    int h;
    
public:
    Triangle()
    {
        this->w = 0;
        this->h = 0;
    }
    Triangle(int w, int h)
    {
        this->w = w;
        this->h = h;
    }
    double getArea()
    {
        return 0.5 * w * h;
    }
};

void TestThree()
{
    Shape *sp1 = new Rect(10);
    cout << "Rect的面积为:" << sp1->getArea() <<endl;
    
    Shape *sp2 = new Circle(12);
    cout << "Circle的面积为:" << sp2->getArea() <<endl;
    
    Shape *sp3 = new Triangle(4, 5);
    cout << "Triangle的面积为:" << sp3->getArea() <<endl;
    
}

class Gangster {
public:
    virtual void fight() = 0;
};

class NinJa:virtual public Gangster
{
    
public:
    virtual void useNingu() = 0;
    
//    void fight()
//    {
//        cout << "using NinJuTsu" <<endl;
//    }
};

class Samurai:virtual public Gangster
{
    
public:
    virtual void useKnife() = 0;
//    void fight()
//    {
//        cout << "使用武士刀" <<endl;
//    }
};
class Killer: public NinJa, public Samurai
{
public:
    void fight()
    {
        cout << "AnSatsu" << endl;
    }
    void useNingu()
    {
        cout << "使用了忍具" << endl;
    }
    
    void useKnife()
    {
        cout << "使用了武士刀" << endl;
    }
};
int main(int argc, const char * argv[]) {

    //父类指针指向子类对象
    Samurai *ganster = new Killer;
    
    //可以通过父类指针, 调用子类中实现的虚函数的方法.
    //该父类指针, 只能实现其自身的被继承的虚函数, 却无法实现由其他父类继承的虚函数
    ganster->fight();
    ganster->useKnife();
    
    NinJa *ganster1 = new Killer;
    ganster1->fight();
    ganster1->useNingu();
    
    //Base类, 指向孙子类.
    //只能调用Base类中被孙子类实现的Base类中的纯虚函数.
    //其他继承自该Base类的父类的纯虚函数, 也是无法调用的!
    Gangster *ganster0 = new Killer;
    ganster0->fight();
//    ganster0->useKnife();
//    ganster0->useNingu();
    return 0;
}
