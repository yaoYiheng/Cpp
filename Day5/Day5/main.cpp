//
//  main.cpp
//  Day5
//
//  Created by 姚懿恒 on 2018/8/31.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
using namespace std;

class Student {
private:
    int id;
    char *name;
    
public:
    
    //无参构造
    Student()
    {
        this->id = 0;
        this->name = NULL;
    }
//    有参构造函数
    Student(int id, char *name)
    {
        this->id = id;
        //根据字符串长度, 来开辟新空间
        this->name = new char[strlen(name) + 1];
        
        //赋值
        strcpy(this->name, name);
        
    }
    void info()
    {
        cout << "id = " << this->id <<", name = " << this->name <<endl;
    }
    
    Student (const Student &stu)
    {
        this->id = stu.id;
        //根据字符串长度, 来开辟新空间
        this->name = new char[strlen(stu.name) + 1];
        
        //赋值
        strcpy(this->name, stu.name);
    }
    ~Student()
    {
        if (this->name != NULL)
        {
            delete [] this->name;
            this->name = NULL;
            this->id = 0;
        }
        
        
    }
    Student & operator=(const Student &stu)
    {
        //1. 判断, 排除自身与自身的赋值情况
        //两边的地址是否一样
        if (this == &stu)
        {
            return *this;
        }
        
        //2.先将自身目前指向的地址释放掉
        if (this->name != NULL)
        {
            delete [] this->name;
            this->name = NULL;
            this->id = 0;
        }
        
        
        //3. 赋值
        this->name = new char[strlen(stu.name) + 1];
        strcpy(this->name, stu.name);
        this->id = stu.id;
        
        return *this;
    }
    
};

void TestOne()
{
    Student st1(1, "zhangsan");
    //拷贝构造. 会发生浅拷贝问题, 需要提供一个拷贝构造函数
    Student st2 = st1;
    
    Student st3(2, "lis5");
    
    /*
     默认情况下,会执行默认的赋值操作, 这样会造成st3与st2共同指向同一片地址, 从而造成
     st2所指向的地址无法被回收, 后来st2新指向的空间被提前释放;
     所以需要重新属性等号赋值操作符
     */
    st2 = st3;
    
}

class Sqrt
{
private:
    int a;
public:
    Sqrt(int a)
    {
        cout << "构造函数" <<endl;
        this->a = a;
    }
    
    //重写()操作符, 可以将一个对象, 当成一个普通函数来调用.
    //称这种对象是仿函数, 伪函数
    int operator()(int value)
    {
        return value * value;
    }
    
    /**
     函数重载 + ()操作符重载
     */
    int operator()(int value1, int value2)
    {
        return value1 * value2;
    }
    friend ostream &operator<<(ostream &os,const Sqrt &s);
    
    
    /**
     void *为万能指针, 可以指向任何数据类型的指针,
    虽然是使用malloc创建的, 但是依旧会触发对象的构造函数.
     @param size <#size description#>
     @return <#return value description#>
     */
    void * operator new(size_t size)
    {
        cout << "调用重载new"<< endl;
        return malloc(size);
    }
    
    
    /**
     重载delete方法.调用重载的delete操作符, 可以触发析构函数.
     @param p <#p description#>
     */
    void operator delete(void *p)
    {
        if (p != NULL)
        {
            free(p);
        }
    }
    
    ~Sqrt()
    {
        cout << "析构" <<endl;
    }
};
ostream &operator<<(ostream &os, const Sqrt &s)
{
    os << s.a <<endl;
    return os;
}
int main(int argc, const char * argv[]) {
    // insert code here...

//    Sqrt s(10);
//    Sqrt w(10);
//    int value = w(10, 230);
//    cout << s;
//    cout << value << endl;
//
    Sqrt *sq = new Sqrt(100);
    
    delete sq;
    cout << *sq <<endl;
    
    return 0;
}
