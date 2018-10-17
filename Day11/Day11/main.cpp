//
//  main.cpp
//  Day11
//
//  Created by 姚懿恒 on 2018/10/17.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include <deque>

using namespace std;



void printDeque(deque<int> &dequ)
{
    for (auto begin = dequ.begin(); begin != dequ.end(); ++begin)
    {
        cout << *begin << " ";
    }
    
    cout << endl;
}
/**
 deque的初始化
 */
void practise1()
{
    deque<int> d1;
    deque<int> d2(10, 5); //deque(n, elem), 初始化n个elem元素
    deque<int> d3(d2.begin(), d2.end()); //通过迭代器初始化
    deque<int> d4(d3);  //拷贝构造
    
    printDeque(d4);
}


/**
 deque赋值 大小操作
 */
void practise2()
{
    deque<int> d1(10, 4);
    deque<int > d2;
    
    d2.assign(d1.begin(), d1.end());//将[begin, end)区间中的数据拷贝赋值给本身
    d2.assign(4, 10);//将n个elem拷贝赋值给本身
    d2 = d1;//重载等号操作符
    deque<int>(3, 3).swap(d2);//将元素互换
    
    printDeque(d2);
    
    cout << "deque中的元素个数为:" << d2.size() << endl;
    
    d2.empty()? cout << "为空" << endl: cout << "不为空" <<endl;
    
    d2.resize(6, 100); //重新制定容器长度为num, 如果变长, 则以elem值填充新位置, 如果变短,则删除超出长度元素
    
    printDeque(d2);
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
//    practise1();
    
    practise2();
    
    return 0;
}
