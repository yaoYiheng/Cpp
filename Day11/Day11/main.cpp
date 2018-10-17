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

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    practise1();
    
    return 0;
}
