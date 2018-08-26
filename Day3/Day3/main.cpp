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
int main(int argc, const char * argv[]) {

//    test();
    test1();

    return 0;
}
