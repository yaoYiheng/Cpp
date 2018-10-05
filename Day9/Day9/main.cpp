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
int main(int argc, const char * argv[]) {
    // insert code here...
//    practise1();
    

//    practise2();
    
//    practise3();
    
    practise4();
    
    return 0;
}
