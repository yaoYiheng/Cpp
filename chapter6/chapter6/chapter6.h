//
//  chapter6.h
//  chapter6
//
//  Created by 姚懿恒 on 2018/9/27.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef chapter6_h
#define chapter6_h


int fact(int value);

/**
 交互实现阶乘
 */
void practise6_4();

double practise6_5(double value);


/**
 理解形参, 局部变量和局部静态变量
 
 @param value1 形参, 相对于函数是局部的, 尽在函数的作用域内可见.
 @param value2 同上
 @return 返回和
 局部静态变量的生命周期贯穿函数调用及之后的时间, 直到程序结束.
 */
double practise6_6(double value1, double value2);

/**
 当第一次被调用时返回0, 以后每次被调用返回值增加1
 */
size_t practise6_7();


/**
 判断string对象中是否含有大写字母

 @param  一般在头文件中不应包含using 声明, 所以使用std::string
 
 */
bool hasUpper(const std::string &s);


/**
 该为小写字母

 @param s <#s description#>
 */
void changeToLower(std::string &s);


/**
 返回较短string对象

 @param s1 <#s1 description#>
 @param s2 <#s2 description#>
 @return <#return value description#>
 */
const std::string & shorterString(const std::string &s1, const std::string &s2);
#endif /* chapter6_h */
