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

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    int a = 10;
    int b = 20;
    int c = 0;
    
    c = MAX(a, b);
    
    cout << "c = " << c <<endl;
    
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
