//
//  main.cpp
//  chapter5
//
//  Created by 姚懿恒 on 2018/9/27.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include "Sales_item.h"

using namespace std;


/**
 当一个单词连续两次出现时, 使用break终止循环.
 */
void practise5_20()
{
    string current, preString;
    bool isTwice = false;
    while (cin >> current)
    {
        
        if (current == preString)
        {
            cout << current << "出现了两次" << endl;
            isTwice = true;
            break;
        }
        preString = current;
    }
    
    if (!isTwice)
    {
        cout << "没有任何单词是重复的"<<endl;
    }
    
}

/**
 找到的重复单词必须是以大写字母开头
 */
void practise5_21()
{
    string current, preString;
    bool bl = true;
    
    cout << "请输入:" <<endl;
    
    while (cin>>current)
    {
        if (!isupper(current[0]))
        {
            continue;
        }
        if (current == preString)
        {
            bl = false;
            cout <<"连续输入:"<< current<<endl;
            break;
        }
        preString = current;
    }
    if (bl)
    {
        cout <<"没有连续的"<<endl;
    }
}
void Test1()
{
    Sales_item item1, item2;
    
    while (cin >> item1 >> item2)
    {
        try
        {
            if (item2.isbn() != item1.isbn())
            {
                throw runtime_error("必须输入相同的ISBN号码");
            }
            
            cout << item1 + item2<<endl;
        }
        catch
        (runtime_error err)
        {
            cout << err.what()
            <<"\nTry again?Enter y or n"<<endl;
            
            char c;
            cin >> c;
            if (!cin || c == 'n')
            {
                break;
            }
        }
    }
    
}


/**
使用try捕获异常, catch子语句应该为用户输出一条提示信息, 询问其是否输入新数并重新执行try语句.
 */
void practise5_23()
{
    int a, b;
    
    
#if 0

    if (b == 0)
    {
        throw runtime_error("除数为0");
    }
#endif
    
    while (cin >>a >> b)
    {
        try
        {
            if (b == 0)
            {
                //抛出错误
                throw runtime_error("除数为0");
            }
            cout << "a / b = " << a / b <<endl;
            
        }
        catch (runtime_error err)
        {
            cout << err.what()<< "\n是否重新输入 y or n" <<endl;
            
            char c;
            cin >> c;
            
            if (!cin || c == 'n')
            {
                break;
            }
        }
    }

    
}
int main(int argc, const char * argv[])
{
    // insert code here...
//    practise5_20();
//    practise5_21();
//    practise5_23();
    
//    Test1();
    

    
    return 0;
}
