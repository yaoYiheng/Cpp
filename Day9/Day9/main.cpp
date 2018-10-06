//
//  main.cpp
//  Day9
//
//  Created by 姚懿恒 on 2018/10/3.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>

#include "Hero.cpp"
#include "MyArray.cpp"
#include <stdio.h>

using namespace std;



template<class T>
class Person
{
private:
    T mAge;
    T mID;
    
public:
    
    Person(T age, T id);
    
//    template <typename sT>
    template <class SclassT>
    friend std::ostream& operator<<(std::ostream &cout, const Person<SclassT> &);
    
    void show();
    
    //普通友元函数
    template <class SclassT>
    friend void printPerson(Person<SclassT> &p);

};

//书写模版声明的时候，
/*
 如果将类模版定义与声明分开写的话
 格式：
 template <class T>
 类名<T>::具体函数实现
 {
    ....
 }
 */
template <class T>
Person<T>::Person(T age, T id)
{
    this->mAge = age;
    this->mID = id;
}


template <class SclassT>
void printPerson(Person<SclassT> &p)
{
    cout << p.mAge << " " << p.mID << endl;
}



template <class T>
void Person<T>::show()
{
    std::cout << this->mAge << " " << this->mID << std::endl;
}

template <class SclassT>
std::ostream& operator<<(std::ostream &os, const Person<SclassT> &person)
{
    os << person.mAge << " " << person.mID << std::endl;
    
    return os;
}


void practise1()
{
    Person<int> person(20, 10003);
    cout << person;
    printPerson(person);
    Person<double> person2(11.23, 220.5);
    
    Person<string> person3("hello", "world");
    person3.show();
    person2.show();
    
    person.show();
}



/**
 类模版中含有static
 */
void practise2()
{
    Hero<string> s1, s2, s3;
    
    Hero<int> i1, i2, i3;
    
    s1.count = 10;
    
    i1.count = 200;
    
    
    cout << s1.count <<" " << s2.count << " " << s3.count << endl;
    
    cout << i1.count <<" " << i2.count << " " << i3.count << endl;
    
}

void practise3()
{
    MyArray<int> myarray1(10);
    

    myarray1.pushBack(10);
    int a = 0;
    for (int i = 0; i < myarray1.mSize; ++i)
    {

        myarray1.pushBack(++a);
    }

    for (int i = 0; i < myarray1.mSize; ++i)
    {
        cout << myarray1[i] << " " ;
    }
    
    cout << endl;
    
}

/**
 static_cast用于内置的数据类型
 以及具有继承关系的指针或引用
 */
void practise4()
{
    int a = 97;
    
    char b = static_cast<char>(a);
    
    cout << b << endl;
    
    
}

//    dynamic_cast 只能转换具有继承关系的指针或者引用，并且只能由子类型转换成基类型
void practise5()
{

}
//定义了一个返回值为空，参数为空的函数类型，并将这种类型命名为Func。
//如何使用？

/*
同一般变量一般：
 int *a = &b;
 Func *s = 具有相同类型的函数名。不需要加（）。
 然后就可以通过s调用那个函数。
 
 
 */
typedef void Func();
void practise6()
{
    int a = 10;
    
    const int&b = a;

    //const_cast：去除（）中变量的const
    int &c = const_cast<int &>(b);
    a = 20;
    
    cout << b <<endl;
    
    c = 100;
    cout << b <<endl;
    
    int aa = 10;
    
    //此时的const修饰的是 *pa,即不能通过 *pa来更改值。
    //但pa本身不是固定的，它还可以指向其他的地址
    const int* pa = &aa;
    
    //与上面的情况正好相反。
    //可以通过 *cpa修改其所指向的值。
    //但无法修改cpa所指向的地址。
    int * const cpa = &aa;
    
    
    Func *s = practise4;
    s();
    
    
    int *pp3 = NULL;
    
    //为pp3变量添加const属性。
    const int *pp4 = const_cast<const int *>(pp3);
    
    
}

class Anima{};

class Building{};

/**
 reinterpret_cast：强制类型转换。
 无关的指针类型都可以进行转换
 也可以进行函数指针转换
 */
void practise7()
{
    
    Anima *ani = NULL;
    //强制将Anima类型转换成Building类型
    Building *build = reinterpret_cast<Building *>(ani);
    
    Hero<int> *intHero = NULL;
    
    MyArray<int> *intArray = reinterpret_cast<MyArray<int> *>(intHero);
    
}


/**
 抛出异常
throw()括号内的，可声明所抛出的异常的类型
throw()内如果没有任何类型，则不能抛出任何异常，但xcode会有这样提示：
 has a non-throwing exception specification but can still throw
 
 */
void practise8() throw()
{
    throw "expression";
}



class MyException
{
public:
    char *error;
    
public:
    MyException() = default;
    MyException(char *err){
        cout << "构造函数" <<endl;
        this->error = new char[strlen(err) + 1];
        strcpy(error, err);
    };
    ~MyException(){
        
        cout << "xi造函数" <<endl;
        if (this->error != NULL)
        {
            delete [] this->error;
            this->error = NULL;
        }
    };
    //拷贝构造函数
    MyException(const MyException &myExc)
    {
        cout << "拷贝构造函数" <<endl;
        this->error = new char[strlen(myExc.error) + 1];
        strcpy(this->error, myExc.error);
    }
    
    void what()
    {
        cout << this->error;
    }
};

int divided(int a, int b)
{
    try {
        if (b == 0)
        {
            
            throw MyException("除数为0\n");
//            throw new MyException();
        }
    }
    /*
     //普通元素 MyException exc 值传递 异常对象catch处理完之后就析构
       引用 MyException &exc 引用传递 并不会调用拷贝构造函数。异常对象在catch处理完之后就会析够
     
     
     */
    catch (MyException exc)
    {
        exc.what();
        
        int temp;
        cout << "请输入非0除数：" <<endl;
        while (cin >>temp)
        {
            if (temp == 0)
            {
                cout << "请输入非0除数：" <<endl;
                continue;
            }
            else
            {
                break;
            }
        }
        
        
        return a / temp;
    }
    
    return a/b;
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    practise1();
    

//    practise2();
    
//    practise3();
    
//    practise4();
    
//    practise6();
    
    cout << divided(10, 0) << endl;
    
    return 0;
}
