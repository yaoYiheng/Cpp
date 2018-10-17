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
};

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
int main(int argc, const char * argv[]) {
    // insert code here...
    
    
//    practise1();
    
//    practise2();
    
//    practise3();
    

    return 0;
}
