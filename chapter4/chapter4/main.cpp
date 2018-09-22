//
//  main.cpp
//  chapter4
//
//  Created by 姚懿恒 on 2018/9/22.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


/**
 关于取模与商的正负, 与如何取整.
 */
void test1()
{
    //取模的运算, 结果的商跟第一个数的符号一致.
    cout << -21 % 6<< endl; // 结果为 -3
    cout << 21 % -6<< endl; //结果为 3
    
    //商一律向0取证, 即去掉小数部分
    cout << -21 / 6<< endl;
    cout << 21 / -6<< endl;
}


/**
 关于溢出与环绕的分析
 */
void test2()
{
    //short类型占16位, 其中有15会用来计数, 有一位用来表示符号
    //所以能表示的数字范围是-32767~32767,
    //当最大值32767时,
    //其内存表示为 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
    //再加一后会  1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0,
    //但同时最高位表示符号, 所以为打印出 -32768
    short value = 32767;
    value += 32769;
    
    cout << value <<endl;
    

}

int main(int argc, const char * argv[])
{


    
    return 0;
}
