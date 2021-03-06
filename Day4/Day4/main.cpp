//
//  main.cpp
//  Day4
//
//  Created by 姚懿恒 on 2018/8/28.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include "MyArray.hpp"
#include <cmath>
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

void TestThree()
{
    
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
}


class Point {
private:
    float x;
    float y;
    
public:
    float friend friendDistancePoints(Point &p1, Point &p2);
    Point(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    void setXandY(float newX, float newY)
    {
        this->x = newX;
        this->y = newY;
    }
    
    float getX()
    {
        return this->x;
    }
    float getY()
    {
        return this->y;
    }
    friend float friendDistancePoints(Point &p1, Point &p2);
    
};
float distancePoints(Point &p1, Point &p2)
{
    float dis;
    
    float x = p1.getX() - p2.getX();
    float y = p2.getY() - p2.getY();
    
    dis = sqrt(x * x + y * y);
    
    return dis;
}
void TestFour()
{
    Point p1(0, 2), p2(1, 0);
    
    cout << "distance = " <<distancePoints(p1, p2) <<endl;
    
}
/**
 友元函数: 当一个函数需要频繁调用到某一个类的get, set方法时, 可以通过使用友元函数
 来直接访问类的成员变量, 减少存取方法的调用以节省开销. 但会破坏封装及安全.
 
 在类中声明欲使用的友元函数, 使用 friend 关键字

 @param p1 <#p1 description#>
 @param p2 <#p2 description#>
 @return 两点的距离差
 
 友元类:
    如果两个类想要有友元类, 则需要在类中声明
 friend class ClassName;
 才能在 在本类中访问其他类的私有成员.
 
 友元类关系不能被继承, 不具有交换性. 不具有传递性.
 */
float friendDistancePoints(Point &p1, Point &p2)
{
    float dis;
    
    float x = p1.x - p2.x;
    float y = p2.y - p2.y;
    
    dis = sqrt(x * x + y * y);
    
    return dis;
}

class Complex {
private:
    int a;
    int b;
    
public:
    Complex()
    {
        a = 0;
        b = 0;
    }
    Complex(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
//    Complex(const Complex &com)
//    {
//        this->a = com.a;
//        this->b = com.b;
//    }
    void info()
    {
        cout << "("<<this->a<<", "<<this->b <<"i)" <<endl;
    }
    
    //友元函数
    friend Complex complexAdd(Complex &p1, Complex &p2);

    
    //在类的内部实现自定义类的操作运输
    Complex complexAdd(Complex &p2)
    {
        Complex temp(this->a + p2.a, this->b + p2.b);
        
        return temp;
    }
    //    friend Complex operator+(Complex &p1, Complex &p2);
    //于上面的函数相冲突
    //重写加法运算操作符
    Complex operator+(Complex &p2)
    {
        Complex temp(this->a + p2.a, this->b + p2.b);
        
        return temp;
    }
    //重写减法运算操作符
    Complex operator-(Complex &p2)
    {
        Complex temp(this->a - p2.a, this->b - p2.b);
        return temp;
    }
    //重写双目加法运算操作符 在类的内部
//    Complex& operator+=(Complex &p2)
//    {
//        this->a += p2.a; this->b += p2.b;
//        return *this;
//    }
    friend Complex& operator+=(Complex &p1, Complex &p2);
    
    //重写双目加法运算操作符 在类的内部
        Complex& operator-=(Complex &p2)
        {
            this->a -= p2.a; this->b -= p2.b;
            
            return *this;
        }
    
    //在类中重写前++(++在类前)
    Complex& operator++()
    {
        this->a++;
        this->b++;
        
        return  *this;
    }
    //后++
    const Complex operator++(int)
    {
        //临时
        Complex temp(this->a, this->b);
        this->a++;
        this->b++;
        
        return temp;
    }
    
    //左移操作符只能写在全局, 不能写在成员方法中, 否则调用的顺序会变反, c1 <<cout
    friend ostream & operator<< (ostream &os, Complex &c1);
    
    //声明 右移操作符
    friend istream & operator>> (istream &is, Complex &c1);
    
};
//在类的外部实现双目运算符
Complex& operator+=(Complex &p1, Complex &p2)
{
    p1.a += p2.a;
    p1.b += p2.b;
    
    return p1;
}
//先是编写全局函数, 实现两个自定义的类相加
Complex complexAdd(Complex &p1, Complex &p2)
{
    Complex temp(p1.a + p2.a, p1.b + p2.b);
    
    return temp;
}
//在全局编写操作运算符
//Complex operator+(Complex &p1, Complex &p2)
//{
//    Complex temp(p1.a + p2.a, p1.b + p2.b);
//
//    return temp;
//}
void TestFive()
{
    Complex c1(1, 2);
    Complex c2(2, 3);
    c1.info();
    c2.info();
    //    Complex c3 = complexAdd(c1, c2);
    
    //以下写法均有效.
    //    Complex c3 = c1.complexAdd(c2);
    //    Complex c3 = c1 + c2;
    Complex c3 = c1.operator+(c2);
    //等价于👆的写法
    //    Complex c3 = operator+(c1, c2);
    
    c3.info();
    
    //减法操作.
    Complex c4 = c1 - c3;
    c4.info();
}

//类的左移操作符, 为了正常调用, 只能写在类的外部 .
ostream & operator<< (ostream &os, Complex &c1)
{
    os <<"("<<c1.a<<", "<<c1.b <<"i)" <<endl;
    
    return os;
}

istream & operator>> (istream &is, Complex &c1)
{
    cout << "a = ";
    cin >>c1.a;
    
    cout << "b = ";
    cin >> c1.b;
    
    return is;
}

void TestSix()
{
    Complex c1(1, 2);
    Complex c2(2, 3);
    
    //    c1 += c1 -=c2;
    
    c1 += c1 -= c2;//从右往左
    ++c1;
    //    c1.info();
    cout << c1;
    
    cin >> c1;
    
    
    cout << c1;
}

void TestSeven()
{
    MyArray array1(10);
    MyArray array2(5);
    
    for (int i = 0; i < 10; i++) {
        //作为左值, 返回的是一个m_space[index]的引用.
        //所以在重写[]操作符时, 返回值是 int&
        array1[i] = i + 4 ; 
        
    }
    
    for (int i = 0; i < 5; i++) {
        
        array2.setData(i, i + 4);
    }
    if (array1 == array2)
    {
        cout << "两个相等" <<endl;
    }
    else
    {
        cout << "两个不相等" <<endl;
    }
    
    
    cout << array1 <<endl;
    cout << array2 <<endl;
    
//    cin >> array1;
    
    cout << array1 << endl;
    
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    TestSeven();
    return 0;
}
