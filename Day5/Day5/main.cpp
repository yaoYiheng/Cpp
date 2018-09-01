//
//  main.cpp
//  Day5
//
//  Created by 姚懿恒 on 2018/8/31.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include "MyString.hpp"
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
void TestTwo()
{
    //    Sqrt s(10);
    //    Sqrt w(10);
    //    int value = w(10, 230);
    //    cout << s;
    //    cout << value << endl;
    //
    //    Sqrt *sq = new Sqrt(100);//等价于 sq->operator new(sizeof(A));
    //
    //    //等价于sq_array_p->operator new[](sizeof(Sqrt[20]));
    //    Sqrt *sq_array_p = new Sqrt[10];
    //    delete[] sq_array_p;
    //    delete sq;
    //    cout << *sq <<endl;
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
    Sqrt()
    {
        cout << "无参构造函数" <<endl;
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
    
    void * operator new[](size_t size)
    {
        cout << "调用重载new[]"<< endl;
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
            p = NULL;
        }
    }
    void operator delete[](void *p)
    {
        if (p != NULL)
        {
            free(p);
            p = NULL;
        }
    }
        
    /**
     &&操作符重载
     */
    bool operator&&(const Sqrt &sq)
    {
        if(this->a && sq.a)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /**
     ||操作符重载
    */
    bool operator||(const Sqrt &sq)
    {
        if(this->a || sq.a)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Sqrt operator+(Sqrt &sq)
    {
        cout << "执行了+" <<endl;
        Sqrt temp(this->a + sq.a);
        
        return temp;
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
void TestEight()
{
    
    Sqrt s1(0);
    Sqrt s2(20);
    
    //    int a = 0;
    //    int b = 10;
    //等价于s1.operator&&(s1.oprator+(s2))
    //如果调用了+函数, 则说明没有进行短路, 与原始的&&操作不一样.
    if(s1 && (s1+s2))
    {
        cout << "为真"<< endl;
    }
    else
    {
        cout << "假的" <<endl;
    }

}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    MyString s1("123");
    cout <<s1 << endl;
    s1 = "1234";
    cout <<s1 << endl;

    return 0;
}
