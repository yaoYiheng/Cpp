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
    }
    Parent(int a)
    {
        this->a = a;
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
    
    Child()
    {
        this->a = 0;
        this->b = 0;
    }
    Child(int a, int b)
    {
        this->a = a;
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
        cout << "父类是否能调用" << endl;
    }
};

void myFunc(Parent * pp)
{
    pp->func();
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
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


    return 0;
}
