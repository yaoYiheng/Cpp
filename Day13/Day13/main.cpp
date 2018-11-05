//
//  main.cpp
//  Day13
//
//  Created by 姚懿恒 on 2018/11/5.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


struct MyPrint
{
    void operator()(int val)
    {
        cout <<val << " ";
    }
};
struct MyCompare
{
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};
void printVec(vector<int> &vInt)
{
    for_each(vInt.begin(), vInt.end(), MyPrint());
    cout << endl;
}
/**
 Merge算法
 Merge算法可以将两个类型一样的容器合并成一个容器, 每个容器中的值必须是有序的.
     merge(vInt1.begin(), vInt1.end(), vInt2.begin(), vInt2.end(), vInt3.begin(), MyCompare())
 最后一个参数用来指定是升序还是降序.
 
 random_shuffle(vInt3.begin(), vInt3.end());
将一个有序的容器打乱
 
 
sort(vInt1.begin(), vInt1.end(), MyCompare());
 按照第三个参数的规则来指定是升序还是降序
 
 reverse(vInt3.begin(), vInt3.end());
 将原容器进行反转
 
 Merge针对任意有序的容器, 均可进行合并操作
 但random_shuffle, sort, reverse, 如果不支持随机访问, 则不可被操作.
 
 
 reverse
 */
void practise1()
{
    vector<int> vInt1, vInt2;
    
    for (int i = 0; i < 10; ++i)
    {
        vInt1.push_back(rand() % 100);
        vInt2.push_back(rand() % 200);
    }
    
    sort(vInt1.begin(), vInt1.end(), MyCompare());
    sort(vInt2.begin(), vInt2.end(), MyCompare());
    
//    printVec(vInt1);
//    printVec(vInt2);

    vector<int> vInt3;
    vInt3.resize(vInt1.size() + vInt2.size());
    merge(vInt1.begin(), vInt1.end(), vInt2.begin(), vInt2.end(), vInt3.begin(), MyCompare());
    
    printVec(vInt3);
    
    cout << "洗牌前" << endl;
    random_shuffle(vInt3.begin(), vInt3.end());
    
    printVec(vInt3);
    
    reverse(vInt3.begin(), vInt3.end());
    cout << "反转:";
    printVec(vInt3);
    
    
}

void printList(list<int> &list)
{
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}
/**
 常用的拷贝算法
 */
void practise2()
{
    vector<int> vInt1;
//    list<int> list2;
    
    
    for (int i = 0; i < 10; ++i)
    {
        vInt1.push_back(i);
//        list2.push_back(rand() % 5);
    }
    
    vector<int> vInt2;
    
    vInt2.resize(vInt1.size());
    //将vInt1里的元素赋值到vInt2中
    copy(vInt1.begin(), vInt1.end(), vInt2.begin());
    
//    printVec(vInt2);
    
    
    
    list<int> list1;
//    copy(list2.begin(), list2.end(), list1.begin());
    
//    cout << list2.size();
//    copy(vInt1.begin(), vInt1.end(), list1);
    
    printVec(vInt1);
    cout << endl;
//    printList(list2);
    
}


/**
 swap用于交换两个容器里的值
  copy不能用于list容器
 */
void practise3()
{
    list<int> list1, list2;
    vector<int> vInt1;
    
    for (int i = 0; i < 10 ; ++i)
    {
        list1.push_back(rand() % 100);
        list2.push_back(rand() % 100);
        vInt1.push_back(rand() % 1000);
    }
    
    printList(list1);
    printList(list2);
//    copy(list1.begin(), list1.end(), list2.begin());
    
    swap(list1, list2);
    
    printList(list1);
    printList(list2);
}



struct GreatThan
{
    bool operator()(int val)
    {
        return val > 5;
    }
};
/**
 replace replace_if
 */
void practise4()
{
    vector<int> vInt;
    for (int i = 0; i < 10 ; ++i)
    {
        vInt.push_back(i);
    }
    cout << "元素数据:";
    printVec(vInt);
    
    cout << "将容器中的5替换成299:"<<endl;
    replace(vInt.begin(), vInt.end(), 5, 299);
    printVec(vInt);
    
    cout << "将容器中大于5的都替换成10000"<<endl;
    replace_if(vInt.begin(), vInt.end(), GreatThan(), 10000);
    printVec(vInt);
    
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
//    practise1();
    
    
//    practise2();
    
//    practise3();
    
    practise4();
    
    
    return 0;
}
