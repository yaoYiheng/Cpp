//
//  main.cpp
//  Day10
//
//  Created by 姚懿恒 on 2018/10/8.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;


/**
 标准输入流 cin.get()
 */
void practise1()
{
//    char ch;
//
//    while ((ch = cin.get()) != EOF)
//    {
//        cout << ch <<endl;
//    }
//
//    cin.get(ch);//读取一个字符
//
    char buff[256] = {0};
//    cin.get(buff, ch);//从缓冲区读取一个字符串
    
    cin.get(buff,256);//读取一行数据, 不读换行符
    
    cout << buff;
    
}


/**
 cin.ignore() 用于忽略当前字符，即从缓冲区清楚掉
 */
void practise2()
{
    
    char ch;
    cin.get(ch);
    cout << ch <<endl;

    /*  如果不传入参数，则默认为1，忽略掉当前的字符
        例如：当向缓冲区中输入string时，调用cin.get(ch),将会执行从缓冲区取出第一个字符，然后输入
     此时缓冲区内还剩tring，执行cin.ignore(), 则会忽略't'此时缓冲区还剩ring。
     
     如果执行的是带参数的cin.ignore(2， '\n')则会
     
     */
    /*
     cin.ignore(int char); 如果在第一个参数制定的大小之前出现了第二个参数的字符，则忽略
     包含该字符之前的所有内容。
     如果在第二个参数出现之前，已经达到了第一个参数制定的大小，则忽略第一个参数个数的字符
     */
    
    
    
    cin.ignore(2, 'a');
    cin.get(ch);
    cout << ch <<endl;
}


/**
 cin.peek 偷窥第一个字符
 */
void practise3()
{
    cout << "请输入数字或字符串："<<endl;
    
    char ch;
    ch = cin.peek();//从缓冲区拿出第一个字符 ，并返回，但并不会清除该字符
    
    if (ch >= '0' && ch <= '9')
    {
        int num;
        cin >>num;
        cout << "输入的数字是：" << num << endl;
    }
    else
    {
        char buf[256] = {0};
        cin >> buf;
        
        cout << "输入的字符串是："<<buf <<endl;
    }
}


/**
 cin.putback(ch);//将从cin.get()取回的字符在放回原位。
 */
void practise4()
{
    cout << "请输入数字或字符串："<<endl;
    
    char ch;
    cin.get(ch);//从缓冲区拿出第一个字符
    
    if (ch >= '0' && ch <= '9')
    {
        cin.putback(ch);
        int num;
        cin >>num;
        cout << "输入的数字是：" << num << endl;
    }
    else
    {
        cin.putback(ch);//将从cin.get()取回的字符在放回原位。
        char buf[256] = {0};
        cin >> buf;
        
        cout << "输入的字符串是："<<buf <<endl;
    }
}

/**
 格式化输出
 */
void practise5()
{
    
    int num = 15;
#if 0   //通过成员方法的方式完成格式化输出
    
    cout.width(4);  //长度为4位
    cout.fill('%'); //多余位数以参数填充
    cout.setf(ios::left);//默认先输出填充符，在输出数字，该为left后先输出数字
    cout << num <<endl;
    cout.unsetf(ios::dec); //卸载当前默认的10进制
    cout.setf(ios::oct);//设置为8进制输出
    cout.setf(ios::showbase);//加上8进制的关键字
    cout << num <<endl;
    
    cout.unsetf(ios::oct);//卸载8进制
    cout.setf(ios::hex);//设置为16进制
    cout.setf(ios::showpoint);
    cout << num <<endl;
#endif
    
    cout << hex //16进制
        << setiosflags(ios::showbase) //表示符
        << setiosflags(ios::left)   //数字在左
        << setw(10)     //设置宽度
        << setfill('$')  //设置填充
    << num << endl;     //输出
    
}
int main(int argc, const char * argv[]) {
    
    
//    practise1();
    
//    practise2();
//    practise3();

    practise5();
    return 0;
}
