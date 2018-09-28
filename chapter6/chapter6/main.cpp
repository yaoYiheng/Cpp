//
//  main.cpp
//  chapter6
//
//  Created by 姚懿恒 on 2018/9/27.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include "chapter6.h"
#include <initializer_list>
using namespace std;


/**
 计算列表中所有元素的和

 @param il <#il description#>
 */
void practise6_27(initializer_list<int> il)
{
    int result = 0;
    for (auto beg = il.begin(); beg != il.end(); ++beg)
    {
        result += *beg;
    }
    
    
    cout << result << endl;
}

/*
 可以按照以下的顺序来逐层理解该声明的含义:
 * func(int i) 表示调用名为func的函数时, 需要一个int类型的实参
 * (*func(int i))意味着我们可以对函数调用的结果执行解引用操作
 * (*func(int i))[10]表示解引用func的调用将得到一个大小是10的数组
 * int (*fun(int i))[10]表示数组中的元素是int类型.
 */
int (*func(int i))[10];


/**
 使用尾置返回类型
 为了边上函数真正的返回类型跟在形参列表之后, 我们在本应该出现返回类型的地方放置一个auto

 @param i int类型的实参
 @return 返回一个指针, 该指针指向含有10个整数的数组.
 */
auto func1(int i) -> int(*)[10];

int main(int argc, const char * argv[]) {
    
    
//    practise6_4();
    
//    cout <<practise6_5(-11.2)<< endl;
    
//    for (int i = 0; i < 4; i++)
    
//    {
//        cout <<practise6_6(i, i+2)<<endl;
//    }
    
//    for (int i = 0; i < 4; i++)
//    {
//        cout <<practise6_7()<<endl;
//    }

//    string temp;
//
//    cin >>temp;
//
//    changeToLower(temp);
//
    
    
    initializer_list<int> lst{1,2,3};
    
    practise6_27(lst);
    
    
    
    return 0;
    
}


/**
 for循环实现阶乘
 */
int fact(int value)
{
    
    if (value < 0)
    {
        return 0;
    }
    
    int result = 1;
    
    for (int i = 1; i <= value; ++i)
    {
        result *= i;
    }
    
    return result;
}

/**
 交互实现阶乘
 */
void practise6_4()
{
    
    int i;
    cout << "请输入一个数字:" <<endl;
    
    cin >> i;
    
    cout << i << "的阶乘为:" << fact(i)<<endl;
}

double practise6_5(double value)
{
    double i;
    cout << "请输入一个数字:" <<endl;
    
    cin >> i;
    
    if (i >= 0)
    {
        return i;
    }
    else
    {
        return -i;
    }
}


/**
 理解形参, 局部变量和局部静态变量
 
 @param value1 形参, 相对于函数是局部的, 尽在函数的作用域内可见.
 @param value2 同上
 @return 返回和
 局部静态变量的生命周期贯穿函数调用及之后的时间, 直到程序结束.
 */
double practise6_6(double value1, double value2)
{
    //局部静态变量, 直到程序结束
    static size_t cnt = 0;
    
    cnt += 1;
    
    cout <<"该函数已经累计执行了"<<cnt << "次"<<endl;
    
    return  value1 + value2;
}
size_t practise6_7()
{
    static size_t cnt = 0;
    return cnt++;
}

/**
 判断string对象中是否含有大写字母
 
 一般在头文件中不应包含using 声明, 所以使用std::string
 
 */
bool hasUpper(const std::string &s)
{
    
    for (decltype(s.size()) index = 0; index != s.size(); ++index)
    {
        if (isupper(s[index]))
        {
            return true;
        }
    }
    
    return false;
}

/**
 该为小写字母
 
 @param s 因为需要修改字符串s, 所以不能将其声明为const, 所以在传入实参的时候, 不能用字符串的字面量,
 而是得用一个string对象作为参数传入, 否则报错.
 */
void changeToLower(std::string &s)
{
    for (auto &c : s)
    {
        c = tolower(c);
    }
    
    for (auto c : s)
    {
        cout << c;
    }
    cout << endl;
}
