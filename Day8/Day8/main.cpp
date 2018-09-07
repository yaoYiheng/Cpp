//
//  main.cpp
//  Day8
//
//  Created by 姚懿恒 on 2018/9/6.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>

#include <istream>
using namespace std;
//方法一:定义了一种名为Array_Int_10, 能容纳10个int数组的数据类型
typedef int(Array_Int_10)[10];

//方法二: 定义了一种名为Array_Int_10_P, 指向1-个int数组的指针数据类型
typedef int(* Array_Int_10_P)[10];

void testOne()
{
    
    int array[10] = {1,2,3,4,5,6,7,8,9,0};
    
    
    //方式一:
    Array_Int_10 *ap = NULL;
    
    ap = &array;
    
    for (int i = 0; i< 10; i++)
    {
        cout << (*ap)[i] << " "  ;
    }
    
    cout << endl;
    
    //方式二:
    Array_Int_10_P arr_p = NULL;
    arr_p = &array;
    
    for (int i = 0; i< 10; i++)
    {
        cout << (*arr_p)[i] << " "  ;
    }
    
    cout << endl;
    
    
    //方式三: 直接定义数组类型的指针
    int(*p)[10];
    
    p = &array;
    for (int i = 0; i< 10; i++)
    {
        cout << (*p)[i] << " "  ;
    }
    
    cout << endl;
    
    
}

int funcOne(int a, int b){
    return a + b;
}
int funcTwo(int a, int b){
    return a - b;
}
int funcThree(int a, int b){
    return a * b;
}
int funcFour(int a, int b){
    return a / b;
}
//定义一个统一的接口, 将他们全部调用起来
void executeFun(int(*p)(int, int), int a, int b)
{
    cout <<  p(a, b) << endl;
}
//定义一种返回值为int, 并接受两个int参数的函数
typedef int(FUNC) (int, int);
//定义函数指针
typedef void(Tip) (void);
//定义结构体
typedef struct Tips
{
    char from[64];
    char to[64];
    Tip *tp;
} TIP;


void tipOne()
{
    cout << "拜见.." <<endl;
}
void tipTwo()
{
    cout << "说谎.." <<endl;
}
void tipThree()
{
    cout << "跑.." <<endl;
}

void useTip(TIP *tip)
{
    cout << "这是"<<tip->from << "给" <<tip->to<<"的锦囊"<<endl;
    //
    tip->tp();
}

TIP *creat(char *from, char *to, Tip *tip)
{
    TIP *temp = (TIP *)malloc(sizeof(TIP));
    
    if (temp == NULL)
    {
        return NULL;
    }
    
    strcpy(temp->from, from);
    strcpy(temp->to, to);
    temp->tp = tip;
    
    return temp;
}
void deleteTip(TIP *tip)
{
    if (tip != NULL)
    {
        free(tip);
        tip = NULL;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TIP *tip1 = creat("诸葛亮", "赵云", tipOne);
    
    
    useTip(tip1);
    
    
    deleteTip(tip1);
    
    return 0;
}
