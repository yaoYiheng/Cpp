//
//  main.cpp
//  Day11
//
//  Created by 姚懿恒 on 2018/10/17.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include <deque>
#include <vector>
#include <stack>
#include <list>
#include <queue>

#include <set>
using namespace std;



void printDeque(deque<int> &dequ)
{
    for (auto begin = dequ.begin(); begin != dequ.end(); ++begin)
    {
        cout << *begin << " ";
    }
    
    cout << endl;
}
/**
 deque的初始化
 */
void practise1()
{
    deque<int> d1;
    deque<int> d2(10, 5); //deque(n, elem), 初始化n个elem元素
    deque<int> d3(d2.begin(), d2.end()); //通过迭代器初始化
    deque<int> d4(d3);  //拷贝构造
    
    printDeque(d4);
}


/**
 deque赋值 大小操作
 */
void practise2()
{
    deque<int> d1(10, 4);
    deque<int > d2;
    
    d2.assign(d1.begin(), d1.end());//将[begin, end)区间中的数据拷贝赋值给本身
    d2.assign(4, 10);//将n个elem拷贝赋值给本身
    d2 = d1;//重载等号操作符
    deque<int>(3, 3).swap(d2);//将元素互换
    
    printDeque(d2);
    
    cout << "deque中的元素个数为:" << d2.size() << endl;
    
    d2.empty()? cout << "为空" << endl: cout << "不为空" <<endl;
    
    d2.resize(6, 100); //重新制定容器长度为num, 如果变长, 则以elem值填充新位置, 如果变短,则删除超出长度元素
    
    printDeque(d2);
    
}



/**
 deque双端插入和删除
 */
void practise3()
{
    deque<int> d1(10, 5);
    
    cout << "原始:" <<endl;
    printDeque(d1);
    
    d1.push_front(100); // 在容器头部插入一个数据
    d1.push_front(1001);
    cout <<"头部插入后:"<<endl;
    printDeque(d1);
    
    cout <<"删除头一个后:"<<endl;
    d1.pop_front(); //删除容器的第一个数据
    d1.pop_back();  //删除容器的最后一个数据
    printDeque(d1);
    
    
    //通过[]索引修改对应index的值. 也可以访问, 如果idx越界不抛出异常, 直接出错
    d1[4] = 10000;
    printDeque(d1);
    
    //返回索引所指的数据, 如果idx越界吗就会抛出out_of_range.
    cout << "从0开始的第3个下标是: " << d1.at(3) << endl;
    
    
    //返回第一个数据
    cout << "第一个元素是:" <<d1.front() << endl;
    //返回最后一个数据
    cout << "最后一个元素是:" <<d1.back() << endl;
    
    
}

class Player
{
public:
    string m_name;
    int m_score;
    
public:
    Player() = default;
    Player(string name, int score): m_name(name), m_score(score){};
    
    friend void showInfo(Player *player);
};

void showInfo(Player *player)
{
    cout << "姓名: "<< player->m_name << ", 分数: " << player->m_score << endl;
}

void creatPlayer(vector<Player> &playerVec)
{
    string nameSeed = "ABCDE";
    
    Player temp;
    
    //通过nameSeed创建选手
    for (int i = 0; i < nameSeed.size(); ++i)
    {
        temp.m_name = "选手";
        temp.m_name += nameSeed[i];
        
        temp.m_score = 0;
        
        playerVec.push_back(temp);
    }
}

bool myCompare(Player &p1, Player &p2)
{
    return p1.m_score > p2.m_score;
}

void printScore(int val)
{
    cout << val << " ";
}
void setScore(vector<Player> &playerVec)
{

    for (auto &player : playerVec)
    {
        
        
        //创建一个deque以保存所有的随机分数, 选择该容器的原因是因为他可以从两头进行删除数据
        deque<int> scores;
        for (int i = 0; i < 10 ; ++i)
        {
            //随机打分
            int tempScore = rand() % 41 + 60;
            
            scores.push_back(tempScore);
        }
            //对随机的打分进行排序
        sort(scores.begin(), scores.end());
        
        //掐头去尾
        scores.pop_front();
        scores.pop_back();
        
        int totalScore = 0;
        
        for (auto &score : scores)
        {
            totalScore += score;
        }
        
            
        player.m_score = totalScore / scores.size();
        
        cout <<player.m_name << "的得分为:" <<player.m_score << endl;
        
    }
}

void ranking(vector<Player> &platerVec)
{
    sort(platerVec.begin(), platerVec.end(), myCompare);
}


/**
 通过deque实现打分的案例
 */
void practise4()
{
    vector<Player> pList;
    
    creatPlayer(pList);
    
    setScore(pList);
    
    ranking(pList);
    
    
    cout << "从高到低的排序为:" <<endl;
    for (auto &player: pList)
    {
        
        cout << player.m_name << ": " <<player.m_score << endl;
    }
    
}


/**
 stack
 
 栈 先进后出
 */
void practise5()
{
    //stack初始化
    stack<Player *> s1;
    Player* p1, *p2, p3, p4;
    p3.m_score = 60;
    p3.m_name = "小强";
    
    p4.m_score = 77;
    p4.m_name = "小黄";
    
    p1 = &p3;
    p2 = &p4;
    
    //向栈中添加元素
    s1.push(p1);
    s1.push(p2);
    
    while (!s1.empty())
    {
        //返回最顶层元素
        showInfo(s1.top());
        //弹出最顶层元素.
        s1.pop();
    }
    
    
}


/**
 队列, 先进先出
 */
void practise6()
{
    queue<int> qInt;
    for (int i = 0; i < 5 ; ++i)
    {
        qInt.push(10 * i);
    }
    
    while (qInt.size() > 0)
    {
        cout << qInt.front() << " ";
        qInt.pop();
    }
    
    cout << endl;
}


void printStack(stack<int> &sInt)
{
    while (sInt.size() > 0)
    {
        cout << sInt.top() << " ";
        sInt.pop();
    }
}

/**
 queue存放stack容器并输出
 */
void practise7()
{
    //初始化栈 跟队列
    stack<int> sInt1, sInt2, sInt3, sInt4;
    queue<stack<int>> qInts;
    
    //初始化可变数组
    vector<stack<int>> vInts;
    
    //将int类型的栈 放到可变数组中
    vInts.push_back(sInt1);
    vInts.push_back(sInt2);
    vInts.push_back(sInt3);
    vInts.push_back(sInt4);
    
    
    cout << vInts.size() << endl;
    
    //遍历可变数组的每一个元素
    for (auto &sInt : vInts)
    {
        //为数组中的每一个元素 赋值
        for (int i = 0; i < 5 ; ++i)
        {
            sInt.push(10 * i);
        }
        cout << sInt.size() << endl;
        
        //将符完值得stack<int>类型的元素, 添加到队列中
        qInts.push(sInt);
    }

    
    
    //不清楚为什么在for循环外面push就没有值, 而当放到循环当中时, 则有值.
//    qInts.push(sInt1);
//    qInts.push(sInt2);
//    qInts.push(sInt3);
//    qInts.push(sInt4);
    

    cout << qInts.size() << endl;
    
    while (qInts.size() > 0)
    {
        //拿到队列中的第一个元素
        auto temp = qInts.front();
        
        //输出该元素的内容
        while (temp.size() > 0)
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
        
        //从头部删除掉第一个元素
        qInts.pop();
    }
}
void printList(list<int> &list)
{
    for (auto &mL2 : list)
    {
        cout << mL2 <<" ";
    }
    
    cout << endl;
    
}

bool myCompare(int val1, int val2)
{
    return val1 > val2;
}
/**
 list相关
 */
void practise8()
{
    list<int> mList1;//默认构造函数
    list<int> mList2(10, 10); // 有参y构造函数
    
    list<int> mList3 = mList2; //拷贝构造函数
    list<int> mList4(mList2.begin(), mList2.end());
    
    printList(mList4);
    
    
    mList1 = {1, 2, 3, 4, 5};
    
    mList1.reverse();//反转链表
    
    printList(mList1);
    
    
    for (int i = 0 ; i < 20 ; ++i)
    {
        mList1.push_back(rand() % 100);
    }
    
    cout << "随机数据是:" <<endl;
    printList(mList1);
    
    mList1.sort();//默认从小到大
    cout << "排序后:" <<endl;
    printList(mList1);
    
    mList1.reverse();
    //sort算法支持可随机访问的容器
//    sort(mList1.begin(), mList1.end(), myCompare);
    
    cout << "倒序:" <<endl;
    printList(mList1);
    
}

void printSet(set<int> &set)
{
    for (auto &ref : set)
    {
        cout << ref <<" ";
    }
    cout <<endl;
}


/**
 set相关
 会对容器内的值自动进行排序. 默认从小到大.
 
 
 */
void practise9()
{
    set<int> s1; //会对容器内的值自动进行排序. 默认从小到大.
    
    for (int i = 0; i < 8; ++i)
    {
        s1.insert(rand() % 1000);
    }
    
    printSet(s1);
    
    //删除
    //传入一个位置. 刚刚试了下传入end()d,但报错, 是因为end()是s指向最后一个元素的下一位.
    s1.erase(s1.begin());
    
    printSet(s1);
    //查找加删除
    //find(key), 查找键lkey是否存在, 若存在, 返回该键的元素的迭代器, 若不存在, 返回map.end()
    auto value = s1.find(249);
    
    
    if (value == s1.end())
    {
        cout << "没有找到!" << endl;
    }
    else
    {
        cout << *value << endl;
    }
    
    //lower_bound(s1.beign(), s1.end(), keyElem)返回第一个 >= keyElem元素的迭代器
    //upper_bound(s1.beign(), s1.end(), keyElem)返回第一个 > keyElem元素的迭代器
    auto val = upper_bound(s1.begin(), s1.end(), 544);
    
    cout << "lower_bound的值为: " << *val << endl;
    
    //equal_range() 返回Lower_bound 和upper_bound的值
    auto pair = s1.equal_range(249);
    
    cout << "pair.first = " << *(pair.first) << endl;
    cout << "pair.second = " << *(pair.second) << endl;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
//    practise1();
    
//    practise2();
    
//    practise3();
    
//    practise5();
    
//    practise6();
    
//    practise7();
    
//    practise8();
    
    practise9();

    return 0;
}
