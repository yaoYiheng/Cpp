//
//  main.cpp
//  HelloWorld
//
//  Created by 姚懿恒 on 2018/8/19.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
using namespace std;
struct Student
{
    int id;
    char name[64];
};

struct typeA
{
    int &a;
};
struct typeB
{
    int *a;
};
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


/**
 通过引用来改变值
 */
void valueChange(int & ref)
{
    ref = 30;
}


/**
 值拷贝, 因为结构体是能完全赋值的, 有内存拷贝的动作
不建议这样写, 因为内存消耗很大当结构体内容很多时
 @param s1 传入的结构体, 拷贝整个结构体
 */
void my_printf(struct Student s1)
{
    cout << "id = " << s1.id <<  " " << " name = "<<s1.name << endl;
}

/**
 比上一种方式好, 不涉及结构体的拷贝, 只是地址的赋值

 @param s1 结构体的地址
 */
void my_printf1(struct Student *s1)
{
    cout << "id = " << s1->id <<  " " << " name = "<<s1->name << endl;
}


/**
 传递引用, 通过.访问结构体的成员,更易操作

 @param s1 结构体的引用, 对别名的赋值
 */
void my_printf2(struct Student &s1)
{
    cout << "id = " << s1.id <<  " " << " name = "<<s1.name << endl;
}

/**
 相当于是将Main函数中的a取地址
 int *const a = main::&a

 @param a 常指针
 */
void motify(int *const a)
{
    *a = 100;
}

/**
 当我们将引用作为函数参数传递的时候, 编译器会替我们将实参取地址给引用
 int &a = main:: &a

 */
void motify2(int &a)
{
    a = 100;//对一个引用操作 赋值的时候, 编译器替我们隐藏了*操作
}
//引用作为返回值, 不要返回局部变量的引用
int& getA()
{
    int a = 10;
    
    return a;
}
int & getAA()
{
    static int a = 10;
    return a;
}

/**
 清屏, 之前的测试代码
 */
void Learn()
{
    // insert code here...
    
    //    test1();
    
    //引用所占用的大小, 跟指针是相等的
    cout << "sizeof(TypeA) = " << sizeof(typeA) << endl;
    cout << "sizeof(TypeA) = " << sizeof(typeB) << endl;
    
    //    int a = 10;
    //    int &ref = a; //常量需要初始化, 引用也要初始化, ->引用可能是一个常量(常指针)
    //
    //    int *const p = &a;
    
    int main_a = 0;
    
    main_a = getA();
    cout << "main_a = " << main_a <<endl;
#if 0
    int& main_a_re = getA();//这里相当于将局部变量里的a传入出来, 该引用指向一个已经出栈的变量, 打印错误值
    
    cout << "main_a_re  = " << main_a_re <<endl;
    
    getA() = 100;
    
    cout << "getA = " << getA()<< endl;
#endif
    
    int main_a_re = getAA();
    
    cout << "main_a_re = " << main_a_re << endl;
    //函数作为左值
    //引用如果当函数返回值的话, 函数可以当左值.
    getAA() = 1000;
    cout << "getAA() = " << getAA() << endl;
}

namespace Pointer {
    //指向结构体引用的别名.
    int get_mem1(struct Student *& stu)
    {
        stu = (struct Student *)malloc(sizeof(struct Student));
        if (stu == NULL) {
            return -1;
        }
        stu->id = 200;
        strcpy(stu->name, "Wangwu");
        
        return 0;
    }
    
    /**
     传入二级指针, 分配结构体并返回

     @param stu <#stu description#>
     @return <#return value description#>
     */
    int get_mem(struct Student **stu)
    {
        //声明一个指向结构体的指针, 并初始化..
        struct Student *st = NULL;
        //在堆中为该结构体分配内存, 并让指针指向这片内存
        st =(struct Student *) malloc(sizeof(struct Student));
        
        //如果内存分配不成功吗返回-1
        if(st == NULL)
        {
            return -1;
        }
        
        //通过指针操作赋值
        st->id = 100;
        strcpy(st->name, "zhangsan");
        
        //赋值
        *stu = st;
        
        return 0;
        
    }
    /**
     通过引用来进行内存释放

     @param stu 结构体指针的引用
     */
    void free_men1(struct Student* &stu)
    {
        if (stu != NULL) {
            free(stu);
            stu = NULL;
        }
        
        
    }
    
    /**
     二级指针释放内存

     @param stu 指向结构体指针的指针
     */
    void free_men(struct Student **stu)
    {
        if (stu == NULL) {
            return;
        }
        
        struct Student *st = *stu;
        if (st != NULL) {
            free(st);
            *stu = NULL;
        }
    }
    void pointerTest1()
    {
        struct Student *s = NULL;
        
        get_mem(&s);
        
        cout << "id = " << s->id << "name = " << s->name <<endl;
        
        free(s);
        
        cout << "--------------------------"<<endl;
        
        get_mem1(s);
        cout << "id = " << s->id << "name = " << s->name <<endl;
        free_men1(s);
    }
}
using namespace Pointer;
int main(int argc, const char * argv[]) {
    


    return 0;
}


