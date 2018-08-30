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
        
        //2. 如果不一样, 先将自身目前指向的地址释放掉
        delete [] this->name;
        this->name = NULL;
        this->id = 0;
        
        //3. 赋值
        this->name = new char[strlen(stu.name) + 1];
        strcpy(this->name, stu.name);
        this->id = stu.id;
        
        return *this;
    }
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
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
    
    return 0;
}
