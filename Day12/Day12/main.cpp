//
//  main.cpp
//  Day12
//
//  Created by 姚懿恒 on 2018/10/23.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;


void printMap(map<string, int> &myMap)
{
    for (map<string, int>::iterator it = myMap.begin(); it != myMap.end(); ++it)
    {
        cout << "Key:" << it->first << ", value: " << it->second << endl;
    }
    
}
void practise1()
{
    map<string, int> myMap;
    
    //方法一
    myMap.insert(pair<string, int>("姓名", 123));
    
    //方法二
    myMap.insert(make_pair("身高", 165));
    
    //方法三
    myMap.insert(map<string, int>::value_type("性别", 1));
    
    //方法四
    myMap["ID"] = 10000;
    
    printMap(myMap);
    
    cout << "------分割线-----"<<endl;
    //如果发现key不存在, 则会创建pair插入到map容器中
    myMap["passport"] = 4321345;
    //如果发现key存在, 则会修改key对应的value的值
    myMap["ID"] = 98654;
    
    printMap(myMap);

    cout << "------分割线-----"<<endl;
    
    //insert会返回一个pair<iterator, bool>类型的值, pair.first是迭代器, pair.second是bool值,
    //判断插入的key是否存在
    pair<map<string, int>::iterator, bool> ret = myMap.insert(make_pair("Phone", 123456));
    //通过insert插入的键值对, 如果已存在在map中, 则不会更新为新值.
    myMap.insert(make_pair("Phone", 321654));
    
    //如果通过[]访问map中不存在的值, 那么map会将这个访问的key插入到map中
    cout << "插入一个不存在的值myMap[Random] = "<< myMap["Random"] <<endl;
    
    //通过myMap[key] = value的方式插入的话, 如果key存在这回修改为新的值.
    myMap["Phone"] =987654321;
    if (ret.second)
    {
        cout << "第一次插入该值" <<endl;
    }
    else
    {
        cout << "已插入过该值, Phone: " << ret.first->second<< endl;
    }
    
    printMap(myMap);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    practise1();
    
    return 0;
}
