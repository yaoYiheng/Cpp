//
//  main.cpp
//  Day2
//
//  Created by 姚懿恒 on 2018/8/22.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#define MAX(a, b) ((a) > (b)? (a):(b))


using namespace std;


/**
 1. 内联函数声明时inline关键字必须和函数定义结合在一起, 否则编译器会直接忽略内联请求
 2. C++编译器直接将函数体插在函数调用的地方.
 3. 内联函数没有普通函数调用时的额外开销(如: 压栈, 跳转, 返回)
 4. 内联函数是一种特殊的函数, 具有普通函数的特征(参数检查返回类型等)
 5 内联函数有编译器处理, 直接将编译后的函数体插入调用的的地方
 宏代码片段 有预处理器处理, 进行简单的文本替换, 没有任何编译过程
 6. C++中内联编译的限制:
    不能存在任何形式的循环语句
    不能存在过多的条件判断语句
    函数体不能过于庞大
    不能对函数进行取址操作
    函数内联声明必须在调用语句之前
 7. 编译器对于内联函数的限制并不是绝对的, 内联函数相当于普通函数的优势只是省去了函数调用时的压栈, 跳转和返回的开销.
 因此, 当函数体的执行开销远大于压栈, 跳转和返回所用的开销时, 那么内联将无意义.
 
 适用场景: 函数体很小, 且被频繁调用
 */
inline void printAB(int a, int b);


/*

 函数的重载:
 
 1. 函数名相同
 2. 参数个数不同, 参数的类型不同, 参数的顺序不同, 均可构成重载
 3. 返回值类型不同, 则不可构成重载
 顺序:
 1. 如果能严格匹配 ,调用完全匹配的.
 2. 如果没没有完全匹配, 调用隐式转换
 3. 都匹配不到, 则调用失败.
 
 void func(int a);
 void func(float a); OK
 void func(int a, float b); OK
 void func(float a, int b);OK
 int func(int a); 与一相冲突.
 */
int func1(void){
    
    cout << "xxx" << endl;
    return 2;
}
int func1(int a)
{
    cout << "int a" <<endl;
    return a;
}
int func1(int a, int b)
{
    cout << "int a, int b" <<endl;
    return a + b;
}
//实现函数指针的方法1.
//定义一个 返回值为int, 有两个为int的参数的参数列表的 函数类型名为 MY_FUNC
typedef int(MY_FUNC)(int, int);

typedef int (*MY_FUNC_P) (int);

class myDate {
    
    //根据封装, 成员一般定义为私有变量, 只是给外界暴露接口即可
    //C++中Struct与Class一样, 但Struct的默认权限为public, Class为private
private:
    short year;
    short month;
    short day;
    
public:
    //getter
    short getYear()
    {
        return year;
    }
    //setter
    void setYear(short newYear)
    {
        year = newYear;
    }
    void initMyDate()
    {
        cin >> year;
        cin >> month;
        cin >> day;
    }
    void printDate()
    {
        cout << year <<"year" <<month << "month" << day <<"day" << endl;
    }
    
    bool isLeapYear()
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            return true;
        }
        
        return false;
    }
};

class Circle {
private:
    double m_Radius;
    double m_Perimeter;
    double m_Area;
    
public:
    void setRaius(double newRadius)
    {
        m_Radius = newRadius;
    }
    double getRaius()
    {
        return m_Radius;
    }
    
    double getPerimeter()
    {
        m_Perimeter = 2 * m_Radius * 3.14;
        return m_Perimeter;
    }
    
    double getArea()
    {
        m_Area = 3.14 * m_Radius * m_Radius;
        return m_Area;
    }
    void showInfo()
    {
        cout << "半径 = " << m_Radius << endl;
        cout << "周长 = " << getPerimeter() << endl;
        cout << "面积 = " << getArea() << endl;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Circle cir;
    cir.setRaius(10);
    
    cir.showInfo();
    
    
    
    return 0;
}

/**
 函数的实现.
 简单且调用频繁的函数, 使用inline
 */
inline void printAB(int a, int b)
{
    cout << "a = " << a << ", b = " << b <<endl;
}

void practise()
{
    
    // 方法1
    //初始化一个MY_FUNC类型的指针
    MY_FUNC *fun1 = NULL;
    //将函数指针指向类型相匹配的函数
    //发送函数名即可, 不需要添加()
    fun1 = func1;
    cout << fun1(10, 20) << endl;
    
    
    ////方法二:
    MY_FUNC_P fun_p = NULL;
    fun_p = func1;
    cout << fun_p(10) << endl;
    
    
    //方式三:
    int(*p)(void) = NULL;
    p = func1;
    
    //当使用函数指针执行函数的时候, 需要加括号额..
    cout << p() <<endl;
    
    
}

void practise1()
{
    myDate date;
    date.initMyDate();
    date.printDate();
    if (date.isLeapYear()) {
        cout << "是闰年" << endl;
    }
    else
    {
        cout << "不是闰年" <<endl;
    }

}
