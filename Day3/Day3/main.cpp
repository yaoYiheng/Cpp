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

int main(int argc, const char * argv[]) {
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
    
    return 0;
}
