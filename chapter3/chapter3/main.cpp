//
//  main.cpp
//  chapter3
//
//  Created by 姚懿恒 on 2018/9/21.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include <cctype>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

void practise3_2()
{
    string temp;
    
#if 0
    while (getline(cin, temp))
    {
        cout << temp<<endl;
    }
#endif
    
    
    while (cin >> temp)
    {
        cout << temp<< endl;
    }
    
}


/**
 比较两个字符串是否相等并输出结果.
 是否长度相等, 并输出较长的那个.
 */
void practise3_4()
{
    string temp1, temp2;
#if 0
    while (cin >> temp1 >> temp2)
    {
        if (temp2 == temp1)
        {
            cout << temp2 << endl;
        }
        else
        {
            if (temp2 > temp1)
            {
                cout << "更大的是:" << temp2 << endl;
            }
            else
            {
                cout << "更大的是:"<< temp1 << endl;
            }
        }
    }
#endif
    
    while (cin >> temp1 >> temp2)
    {
        if (temp2.size() >= temp1.size())
        {
            cout << "更长的是:" <<temp2<<endl;
        }
        else
        {
            cout<<"更长的是: "<<temp1 << endl;
        }
    }
    
    
}

/**
 编写一段程序从标准输入中读入多个字符串并将它们连接在一起输出成大字符串.
 
 修改, 空个分割.
 */
void practise3_5()
{
#if 0
    string temp1, temp2, temp3;
    
    cout << "请输入三个字符串, 以回车"<<endl;
    
    while (cin >> temp1 >> temp2 >>temp3)
    {
        cout << temp1 +" "+ temp2 + " " + temp3 <<endl;
        cout << "请输入三个字符串, 以回车"<<endl;
    }
    
#endif
    
    char cont = 'y';
    string temp, result;
    
    cout << "请输入第一个字符串"<<endl;
    
    while (cin >> temp)
    {
#if 0
        result += temp;
#else
        if (!temp.size())
        {
            result += temp;
        }
        else
        {
            result = result + " " + temp;
        }
#endif
        cout << "是否继续(y or n)" << endl;
        cin >> cont;
        if (cont == 'y' || cont == 'Y')
        {
            cout << "请输入下一个字符串" << endl;
        }
        else
        {
            break;
        }
        
    }
    
    cout << "拼接后的字符串为: " << result <<endl;
    
}


/**
考察auto
 */
void practise3_6()
{
    string temp = "hello world";
    
    for (auto &bite : temp)
    {
        bite = 'X';
        
    }
    
    cout << temp <<endl;
}

/**
 使用for循环完成替换字符串
 */
void pracise3_7()
{
    string temp;
    
    cout << "请输入一个字符串, 可以包含空格"<<endl;
    
    getline(cin, temp);
    for (unsigned i = 0; i < temp.size(); i++)
    {
        temp[i] = 'x';
    }
    cout << temp<< endl;
}
/**
 使用while循环完成字符串替换.
 */
void practise3_8()
{
    string temp;
 
    cout << "请输入一个字符串, 可以包含空格"<<endl;
    getline(cin, temp);
    
    int index = 0;
    while (temp[index] != '\0')
    {
        //完成替换
        temp[index] = 'x';
        ++index;
    }

    cout << temp<< endl;
}

/**
 剔除字符串中的标点符号
 */
void practise3_10()
{
    string temp, result;
    cout << "输入一段包含标点符号的字符串: "<<endl;
    
    getline(cin, temp);
    
    for (auto &c : temp)
    {
        if (!ispunct(c))
        {
            result +=c;
        }
    }
    cout << result << endl;
    
}

void pratise3_11()
{
    const string temp = "hello world";
    
    for (auto &ch : temp)
    {
        //不能正确编译, 因为ch绑定到常量上的引用, 无法修改.
//        ch = 'x';
    }
    
    cout << temp <<endl;
}

/**
 分布情况.
 */
void pratcize1()
{
    vector<unsigned> scores(11, 0);
    unsigned grade;
    
    cout << "请输入分数:" << endl;
    
    while (cin >> grade)
    {
        if (grade <= 100)
        {
            auto index = grade / 10;
            scores[index] = scores[index] + 1;
        }
    }
    
    cout << "分布情况为: "<<endl;
    
    for (auto ver : scores)
    {
        cout << ver << endl;
    }
}
void pratcize2()
{
    //通过迭代器输出一个vector<int>
    vector<int> vetInt(10, 1);
    
    for (auto it = vetInt.begin(); it != vetInt.end(); ++it)
    {
        cout << *it << " ";
    }
    cout <<endl;
    
    
    //通过迭代器修改字符串大小写.
    string str("hello world");
    
    for (auto it = str.begin(); it != str.end() && !isspace(*it); ++it)
    {
        *it = toupper(*it);
    }
    cout << str<<endl;
}
/**
 向vector中输入整数
 */
void practise3_14()
{
    int temp;
    
    vector<int> vecInt;
    
    char cont = 'y';
    
    cout << "请输入一个整数:"<< endl;
    
    while (cin >> temp)
    {
        vecInt.push_back(temp);
        
        cout << "是否继续(y or n)" <<endl;
        cin >> cont;
        
        if (cont != 'y' && cont != 'Y')
        {
            break;
        }
        
        cout << "请输入:" <<endl;
        
    }
    
    for (auto index: vecInt)
    {
        cout << index << " ";
    }
}
/**
 将输入的单词变为大写.
 */
void practise3_17()
{
    string temp;
    vector<string> text;
    char cont = 'y';
    
    while (cin >> temp)
    {
        text.push_back(temp);
        
        cout << "是否继续(y or n)"<<endl;
        cin >> cont;
        if (cont == 'y' || cont == 'Y')
        {
            cout << "请输入下一个:"<<endl;
        }
        else
        {
            break;
        }
    }
    
    //变量vector中的每一个字符串
    for (auto &ch : text)
    {
        //遍历每个字符串中的每个字符
        for (auto &bite : ch)
        {
            bite = toupper(bite);//将其大写后并返回.
        }
        
        cout << ch << endl;
    }
    
}

/**
 输入一段文字, 将其改变为大写.
 */
void practise3_22()
{
    vector<string> text;
    string temp;
    
    while (getline(cin, temp))
    {
        text.push_back(temp);
    }
    
    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
    {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            *it2 = toupper(*it2);
        }
        
        cout << *it << endl;
    }
    
    
}

/**
 读入一组整数, 并把他们存放入一个vector对象, 将每对相邻整数的和输出.
 修改程序, 收尾相加.
 */
void practise3_20()
{
    int temp;
    vector<int> intVec;
    
    cout << "请输入一组整数: " << endl;
    
    while (cin >> temp)
    {
        intVec.push_back(temp);
    }
    
    decltype(intVec.size()) vecSize = intVec.size();

    //因为递增两是每次+2, 为了保证最后的下标不越界, 所以 index 需要小于长度 - 1;
    for (decltype(intVec.size()) index = 0; index < vecSize - 1; index += 2)
    {

        //计算相邻的元素的和
        cout << "相邻元素和为: " << intVec[index] + intVec[index + 1] << endl;
        
    }
    if (vecSize % 2 != 0)
    {
        cout << "最后一个元素不参与相加, 结果为: "<< intVec[vecSize - 1] <<endl;
    }
#if 0
    if (vecSize % 2 == 1)
    {
        
        cout << "中间的数不参与计算, 其结果为: "<<intVec[vecSize / 2]<<endl ;
    }
    else
    {
        cout << "正好可以收尾相加没有数剩下" << endl;
        cout << "头尾相加结果为:"<<endl;
        
        auto mid = vecSize / 2;
        
        for (decltype(intVec.size()) index = 0; index < vecSize; ++index )
        {
            
            if (index == mid)
            {
                break;
            }
            cout << intVec[index] + intVec[vecSize - 1 - index] <<endl;

        }
    }
#endif
    for (decltype(intVec.size()) index = 0; index < vecSize / 2; ++index )
    {

        cout <<"收尾相加为: "<< intVec[index] + intVec[vecSize - 1 - index] <<endl;
        
    }
    if (vecSize % 2 != 0)
    {
        cout << "中间的数不参与计算, 其结果为: "<<intVec[vecSize / 2]<<endl ;
    }
}

void practise3_23()
{
    vector<int>vecInt(10, 20);
    
    for (auto b = vecInt.begin(); b != vecInt.end(); b++)
    {
        *b *= 2;
        cout << *b <<" " ;
    }
    cout << endl;
    
    vector<int>randomVec;
    //生成随机数种子
    srand((unsigned) time(NULL));
    
    //装入容器中
    for (int i = 0; i < 10; i++)
    {
        //随机生成1000内的随即数
        randomVec.push_back(rand() % 1000);
    }
    cout <<"生成的随机数为: ";
    for (auto b = randomVec.begin(); b != randomVec.end(); b++)
    {
        cout << *b << " ";
    }
    
    cout << "翻倍后的随机数为: ";
    for (auto b = randomVec.begin(); b != randomVec.end(); b++)
    {
        cout << *b * 2 << " ";
    }
    cout << endl;
}

/**
 <#Description#>
 */
void practise3_24()
{
    vector<unsigned>scoreVec(11);
    
    auto it = scoreVec.begin();
    
    int temp;
    
    cout << "请输入一组分数:"<<endl;
    
    while (cin >> temp)
    {
        if (temp < 101)//限制无效输入
        {
            /*等价于
             auto index = temp / 10;
             *(it + index) = *(it + index) + 1;
             */
            ++*(it + temp / 10);

        }
    }
    cout << "总计输入" << scoreVec.size()<<"个成绩" << endl;
    cout << "从低到高分数分布:"<<endl;
    
    for (; it != scoreVec.end(); it++)
    {
        cout << *it<< " ";
    }
    
    vector<int> s{1,22,32,42,52,62,72};
    auto iit = s.begin();
    //迭代器与整数n相加, 移动迭代器向前 移动 n个单位
    cout << *(iit + 6)<<endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
//    practise3_2();
    
//    practise3_4();
    
//    practise3_5();

//    practise3_6();
    
//    pracise3_7();
    
//    practise3_8();
    
//    practise3_10();
    
//    pratcize1();
    
//    practise3_14();
//    practise3_17();
    
//    practise3_20();
    
//    practise3_22();
    
//    practise3_23();
    
//    practise3_24();

   
    
    
    

    return 0;
}
