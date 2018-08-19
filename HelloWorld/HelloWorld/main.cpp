//
//  main.cpp
//  HelloWorld
//
//  Created by 姚懿恒 on 2018/8/19.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 引用的规则:
 1. 引用没有定义, 是一种关系型声明. 声明它和原有某一变量(实体)的关系.
 故 类型与原类型保持一致. 且不分配内存. 与被引用的变量有相同的地址.
 2. 声明的时候必须初始化, 一经声明, 不可变更.
 3. 可对引用, 再次引用. 多次引用的而结果是某一变量具有多个别名
 4. &符号前又是哭类型时, 是引用, 其他皆为取地址.
 */
void test1()
{
    int a = 10;
    //设置a的引用为ref
    int &ref = a;
    //对引用再次引用. 但都是指向a
    int &refer = ref;
    
    refer = 100;
    
    cout << "a = " <<a<<endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    test1();
    return 0;
}
