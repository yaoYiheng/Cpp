//
//  main.cpp
//  chapter6
//
//  Created by 姚懿恒 on 2018/9/27.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include "chapter6.h"

using namespace std;

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

    string temp;

    cin >>temp;

    changeToLower(temp);
    
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
