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
}
/**
 Merge算法
 Merge算法可以将两个类型一样的容器合并成一个容器, 每个容器中的值必须是有序的.
     merge(vInt1.begin(), vInt1.end(), vInt2.begin(), vInt2.end(), vInt3.begin(), MyCompare())
 最后一个参数用来指定是升序还是降序.
 
 random_shuffle(vInt3.begin(), vInt3.end());
将一个有序的容器打乱
 
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
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    practise1();
    
    
    return 0;
}
