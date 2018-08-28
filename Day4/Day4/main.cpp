//
//  main.cpp
//  Day4
//
//  Created by 姚懿恒 on 2018/8/28.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
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
    
public:
    A()
    {
        m_x = 0;
    }
    A(int x)
    {
        m_x = x;
    }
    
    void setX(int x)
    {
        m_x = x;
    }
    
    int getX() const //成员函数尾部出现的const, 是用来修饰this指针. 使其为只读属性.从而无法被修改
    {
        //因为const的修饰, 所以不能进行修改.
//        this->m_x = 10;
        return this->m_x;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    return 0;
}
