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
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
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
    
    
    return 0;
}
