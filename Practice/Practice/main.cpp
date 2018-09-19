//
//  main.cpp
//  Practice
//
//  Created by 姚懿恒 on 2018/9/19.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include "Sales_item.hpp"
#include <string>
using namespace std;

void testOne()
{
    cout << "请输入两个数字:" << endl;
    
    int v1, v2;
    
    cin >> v1 >> v2;
    
    if (v1 >= v2)
    {
        cout << "两个数字之间的整数为: " ;
        for (int i = v2 + 1; i < v1; i++)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "两个数字之间的整数为: ";
        for (int i = v1 + 1; i < v2; i++)
        {
            cout << i << " ";
        }
        
        cout << endl;
    }
}
//计算一组数的和
void testTwo()
{
    cout << "请输入一组数, 以control + z结束输入" << endl;
    int total = 0, temp;
    while (cin >> temp)
    {
        total += temp;
    }
    
    cout << "结果为: "<< total << endl;
}
void testThree()
{
    cout << "请输入一组数, 以control + d结束输入" << endl;
    int current = 0, temp = 0;
    
    if (cin >> temp)
    {
        int count = 1;
        while (cin >> temp)
        {
            if (temp == current)
            {
                ++count;
            }
            else
            {
                cout << temp << "出现了" << count <<"次" <<endl;
                current = temp;
                count = 1;
            }
        }
        
        
        
        cout << temp << "出现了" << count <<"次." <<endl;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    Sales_item item1, item2;
    
    cin >> item1>>item2;
    
    
    if (item2 != item1)
    {
        cout << "两本书Bu一样" << endl;
    }

    
    return 0;
}
