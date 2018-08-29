//
//  main.cpp
//  Day4
//
//  Created by 姚懿恒 on 2018/8/28.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include "MyArray.hpp"
using namespace std;

class Goods {
private:
    float m_weight;
    static float m_totalWeight;
    
    
public:
    
    Goods *m_head;
    
    //静态方法, 返回静态成员变量的值.
    //static成员函数, 只能返回static成员变量
    static float getTotalWeight()
    {
        return m_totalWeight;
    }
    
    
    Goods(float weight)
    {
        m_weight = weight;
        m_totalWeight += weight;
        m_head = NULL;
        cout << "创建了一个重量为" << this <<"的货物" << endl;
    }
    Goods()
    {
        m_weight = 0;
        m_head = NULL;
    }
    
    Goods(const Goods &goods)
    {
        m_weight = goods.m_weight;
        
        
    }
    
    void operator= (const Goods &goods)
    {
        m_weight = goods.m_weight;
    }
    ~Goods()
    {
        cout << "删除一箱重量为"<<m_weight<<"的货物" << endl;
        m_totalWeight -= m_weight;
    }
    float getWeight(Goods &goods);
};
float Goods:: m_totalWeight = 0;
void buy(Goods * &head, float weight)
{
    //创建一个货物,. 重量是weight
    Goods *newGood = new Goods(weight);
    if (head == NULL)
    {
        head = newGood;
    }
    else
    {
        newGood->m_head = head;
        head = newGood;
        
    }
    
}
void sale(Goods * &head)
{
    if (head == NULL)
    {
        cout << "仓库中已没有货物" << endl;
        return;
    }
    //创造临时变量以接受
    Goods *temp = head;
    head = temp->m_head;
    //调用delete, 触发析构函数.
    cout << "卖出" <<endl;
    delete temp;
}
int TestOne()
{

    int choice = 0;
    Goods *head = NULL;
    int weight;
    do {
        cout << "1 进货" << endl;
        cout << "2 出货" << endl;
        cout << "0 退出" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "请输入要创建货物的重量" <<endl;
                cin >> weight;
                buy(head, weight);
                break;
            case 2:
                sale(head);
                break;
                
            case 0:
                return 0;
                
            default:
                break;
        }
        cout << "当仓库的总重量是" << Goods:: getTotalWeight() << endl;
    } while (1);
}

class A {
private:
    int m_x;
    int m_y;
    
public:
    A()
    {
        m_x = 0;
        m_y = 0;
    }
    A(int x, int y)
    {
        m_x = x;
        m_y = y;
    }
    
    void setX(int x, int y)
    {
        m_x = x;
        m_y = y;
    }
    
    int getX() const //成员函数尾部出现的const, 是用来修饰this指针. 使其为只读属性.从而无法被修改
    {
        //因为const的修饰, 所以不能进行修改.
//        this->m_x = 10;
        return this->m_x;
    }
    
    A& plusEqual(A &newA)
    {
        this->m_x += newA.m_x;
        this->m_y += newA.m_y;
        
        return *this; //如果想要返回一个对象本身, 在成员方法中,用  *this返回
    }
    
    void add(A &newA)
    {
        this->m_x += newA.m_x;
        this->m_y += newA.m_y;
        
    }
    void show()
    {
        cout << this->m_x <<" "<< this->m_y << endl;
    }
};
void TestTwo()
{
    A a1(10, 20), a2(100, 200);
    
    //    a1.add(a2);
    a1.show();
    //如果想对一个对象连续调用成员方法, 每次都会改变对象本身, 成员方法需要返回引用 (*this)
    a1.plusEqual(a2).plusEqual(a2);
    
    a1.show();
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    MyArray array1(10);
    
    for (int i = 0; i < array1.getLength(); i++)
    {
        array1.setData(i, i+ 10);
    }

    MyArray array2 = array1;
    
    for (int i = 0; i < array2.getLength(); i++) {
        cout << array2.getData(i) << " " ;
    }
    cout << endl;
    
    MyArray array3;
    array3 = array1;
    for (int i = 0; i < array3.getLength(); i++) {
        cout << "array3 = " << array3.getData(i) << " " ;
    }
    
    return 0;
}
