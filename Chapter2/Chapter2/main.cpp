//
//  main.cpp
//  Chapter2
//
//  Created by 姚懿恒 on 2018/9/20.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
#if 0
    int i = 42;
    int &r = i;
    
    int *p;
    
    p = &i;
    int *&rep = p;
    
    cout << *p<< endl;
    cout << "rep = "<<rep<< endl;
    int &r2 = *p; // 等价于int &r2 = i?
    
    cout << r2<<endl;
    
    
    if (*p == r2)
    {
        cout<<"指向的地址相同"<<endl;
        cout << *p * *p<<endl;
    }
    int  *p1 = 0;
    p1 = &r2;
    
    cout <<*p1<<endl;
    
    p = nullptr;
    
    cout <<p<<endl;
#endif
    //curerr指向的 上一个一般的非常量整数, 那么完全可以用curerr去修改errnum的值
    //但因为 curerr是一个用const修饰的指针,
    // 这就意味着: curerr将始终指向errnum, 不能够将别的地址赋给这个指针
    int errnum = 0;
    int *const curerr = &errnum;
    *curerr = 10;
    cout << *curerr <<endl;
    
    
    int i = 110;
    int *p;
    int *ppr = nullptr;
    const int c1 = 42;
    const int *p2 = &c1;    //p2是一个指向常量整型的指针, 它可以在指向别的地址, 但只能读, 不能修改
    int *const p3 = p;  //p3是一个常量指针, 指向int* 类型.
    p2 = &i;
    cout << *p2<<endl;
    constexpr int *p4 = nullptr;
    
    return 0;
}
