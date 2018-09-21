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
    
    practise3_14();
//    practise3_17();

    return 0;
}
