//
//  main.cpp
//  Day3
//
//  Created by 姚懿恒 on 2018/8/26.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
using namespace std;
class Test {
private:
    int m_x;
    int m_y;
    
public:

    //在类中会有个默认的午餐构造函数
    /*
        当没有任何***显示的构造函数(显示的无构造, 显示有参, 显示拷贝构造)***的时候, 默认无参构造函数就会出现
        当没有***显示的拷贝构造***的函数, 那么默认的拷贝构造就会出现.
     
        会有默认的析构函数
     当没有 ***显示的析构函数***的时候, 默认的析构函数就会出现
     */
    Test()
    {
        cout << "无参构造函数被调用" << endl;
        m_x = 0;
        m_y = 0;
    }
    Test(int x, int y)
    {
        cout << "有参构造函数被调用" << endl;
        setXAndY(x, y);
    }
    
    void setXAndY(int x, int y)
    {
        m_x = x;
        m_y = y;
    }
    //拷贝构造函数的实现
    Test(const Test &newTest)
    {
        cout << "拷贝构造函数被调用" << endl; 
        m_x = newTest.m_x;
        m_y = newTest.m_y;
    }
    
    /**
     赋值操作符函数
     */
    void operator = (const Test & newTest)
    {
        cout << "赋值操作符函数被调用" << endl;
        m_x = newTest.m_x;
        m_y = newTest.m_y;
    }
    
    void info()
    {
        cout << "x = " << m_x <<endl;
        cout << "y = " << m_y <<endl;
    }
    
    //析构函数
    ~Test()
    {
        cout << "~Test被调用" << endl;
    }
};

Test func1()
{
    cout << "function1开始" << endl;
    Test temp(12, 23);
    temp.info();
    
    
    cout << "function1结束" << endl;
    
    return temp;
}//会有一个匿名对象来接受返回值
void test0()
{
    // insert code here...
    
    Test test1(100, 200);
    test1.info();
    
    //拷贝构造函数
    Test test2(test1);
    test2.info();
    
    //同样是拷贝构造函数
    Test test3 = test1;
    
    Test test4;
    test4 = test1;//这里调用的不是拷贝构造函数, 而是赋值操作符函数
    
}
void test1()
{
    cout << "test1开始" << endl;
    Test t1 = func1(); //并不会触发拷贝构造操作, 而是将匿名对象转正为t1
    
    Test t2;
    t2 = func1(); // 这种情况会调用赋值操作符函数, 不会将匿名对象转正, 而是马上被编译器回收
    cout << "test1结束" << endl;
}
void test()
{
    cout << "test开始" << endl;
    func1();//当一个函数返回一个匿名对象的时候, 如果函数外部没有任何变量去接受它, 这个匿名对象将不会再被使用(找不到), 编译器会将这个匿名对象回收掉 ,而不是等待整个函数执行完毕再回收
    
    
    cout << "test结束" << endl;
}
class Teacher {
    int m_id;
    char *m_name;
    
public:
    Teacher(int id, char* name)
    {
        m_id = id;
        
        m_name = (char *)malloc(strlen(name) + 1);
        strcpy(m_name, name);

    }
    //显示的提供一个拷贝函数, 完成深拷贝动作.
    //各自
    Teacher(const Teacher &newTeacher)
    {
        m_id = newTeacher.m_id;
        
        //深拷贝
        m_name = (char *)malloc(strlen(m_name) + 1);
        strcpy(m_name, newTeacher.m_name);
        
        
    }
    void showInfo()
    {
        cout << "id = " << m_id <<", name = " << m_name <<endl;
    }
    ~Teacher()
    {
        cout << "调用析构函数" << endl;
        if (m_name != NULL)
        {
            free(m_name);
            m_name = NULL;
        }
    }
};

void Test3()
{
    Teacher t1(1, "zhangsan");
    t1.showInfo();
    
    //调用拷贝构造函数, 同样也为t2分配一片内存空间, 当被销毁时, 他们销毁各自的空间.
    Teacher t2(t1);
    t2.showInfo();
}

class A {
private:
    int m_id;
    
public:
    A(int id)
    {
        m_id = id;
    }
    
    void info()
    {
        cout << m_id<<endl;
    }
};

class B {
private:
    const int m_number;
    A m_aa;
    A m_aaa;
    
public:
    //B的构造函数
    //构造对象成员的顺序跟初始化列表的顺序无关.
    //而是跟成员对象的定义顺序有关.
    //在初始化列表中, 调用A的构造函数, 完成对B类中的类成员A的初始化
    //如果成员变量有const的常量, 则必须在初始化列表中进行赋值!
    B(int num, A &a2, A &a3):m_number(num), m_aa(a2), m_aaa(a3)
    {
        
    }
    
    //也可以将成员变量写到初始化列表当中.注意上下的 m_number的初始化过程.
    B(int num, int a1, int a2): m_number(num), m_aa(a1), m_aaa(a2)
    {
//        m_number = num;
    }
    
    void info()
    {
        cout << m_number <<endl;
        m_aa.info();
        m_aaa.info();
        
    }
};
int main(int argc, const char * argv[]) {

//    test();
//    test1();
//    Teacher t1(1, "zhangsan");
    
//    Test3();

    A a(0), b(12);
    B bb(20, 111, 222);
    
    bb.info();
    
    return 0;
}
