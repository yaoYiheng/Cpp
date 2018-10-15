//
//  main.cpp
//  Day10
//
//  Created by 姚懿恒 on 2018/10/8.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>
#include <algorithm>

using namespace std;


/**
 标准输入流 cin.get()
 */
void practise1()
{
//    char ch;
//
//    while ((ch = cin.get()) != EOF)
//    {
//        cout << ch <<endl;
//    }
//
//    cin.get(ch);//读取一个字符
//
    char buff[256] = {0};
//    cin.get(buff, ch);//从缓冲区读取一个字符串
    
    cin.get(buff,256);//读取一行数据, 不读换行符
    
    cout << buff;
    
}


/**
 cin.ignore() 用于忽略当前字符，即从缓冲区清楚掉
 */
void practise2()
{
    
    char ch;
    cin.get(ch);
    cout << ch <<endl;

    /*  如果不传入参数，则默认为1，忽略掉当前的字符
        例如：当向缓冲区中输入string时，调用cin.get(ch),将会执行从缓冲区取出第一个字符，然后输入
     此时缓冲区内还剩tring，执行cin.ignore(), 则会忽略't'此时缓冲区还剩ring。
     
     如果执行的是带参数的cin.ignore(2， '\n')则会
     
     */
    /*
     cin.ignore(int char); 如果在第一个参数制定的大小之前出现了第二个参数的字符，则忽略
     包含该字符之前的所有内容。
     如果在第二个参数出现之前，已经达到了第一个参数制定的大小，则忽略第一个参数个数的字符
     */
    
    
    
    cin.ignore(2, 'a');
    cin.get(ch);
    cout << ch <<endl;
}


/**
 cin.peek 偷窥第一个字符
 */
void practise3()
{
    cout << "请输入数字或字符串："<<endl;
    
    char ch;
    ch = cin.peek();//从缓冲区拿出第一个字符 ，并返回，但并不会清除该字符
    
    if (ch >= '0' && ch <= '9')
    {
        int num;
        cin >>num;
        cout << "输入的数字是：" << num << endl;
    }
    else
    {
        char buf[256] = {0};
        cin >> buf;
        
        cout << "输入的字符串是："<<buf <<endl;
    }
}


/**
 cin.putback(ch);//将从cin.get()取回的字符在放回原位。
 */
void practise4()
{
    cout << "请输入数字或字符串："<<endl;
    
    char ch;
    cin.get(ch);//从缓冲区拿出第一个字符
    
    if (ch >= '0' && ch <= '9')
    {
        cin.putback(ch);
        int num;
        cin >>num;
        cout << "输入的数字是：" << num << endl;
    }
    else
    {
        cin.putback(ch);//将从cin.get()取回的字符在放回原位。
        char buf[256] = {0};
        cin >> buf;
        
        cout << "输入的字符串是："<<buf <<endl;
    }
}

/**
 格式化输出
 */
void practise5()
{
    
    int num = 15;
#if 0   //通过成员方法的方式完成格式化输出
    
    cout.width(4);  //长度为4位
    cout.fill('%'); //多余位数以参数填充
    cout.setf(ios::left);//默认先输出填充符，在输出数字，该为left后先输出数字
    cout << num <<endl;
    cout.unsetf(ios::dec); //卸载当前默认的10进制
    cout.setf(ios::oct);//设置为8进制输出
    cout.setf(ios::showbase);//加上8进制的关键字
    cout << num <<endl;
    
    cout.unsetf(ios::oct);//卸载8进制
    cout.setf(ios::hex);//设置为16进制
    cout.setf(ios::showpoint);
    cout << num <<endl;
#endif
    
    cout << hex //16进制
        << setiosflags(ios::showbase) //表示符
        << setiosflags(ios::left)   //数字在左
        << setw(10)     //设置宽度
        << setfill('$')  //设置填充
    << num << endl;     //输出
    
}


/**
 使用ifstream从文件中读取数据并写入到另一个文件当中
 */
void practist6()
{
    cout <<__func__<<endl;
    string targetPath = "/Users/xxx/Documents/copy.txt";
    string sourcePath = "/Users/xxx/Documents/ThirdPersonCharacterGuidelines.txt";
    
    //创建文件in流对象
    //以只读方式打开文件
    ifstream ifs(sourcePath, ios::in); //等价 ifstream ifs;ifs.open(sourcePath, ios::in);
    
    
    
    //同时也需要创建out流对象
    ofstream ofs(targetPath, ios::out);
    
    //判断是否打开成功
    if (!ifs)
    {
        cout << "打开文件失败" <<endl;
    }
    
    char ch;
    while (ifs.get(ch)) //从流文件中读取字符
    {
        cout << ch;
        //将字符串写入到目标文件
        ofs.put(ch);
        
    }
    
    //关闭文件
    ifs.close();
    
    ofs.close();
    
    
    
}

class Person
{
public:
    int m_id;
    int m_age;
    
public:
    Person() = default;
    
    Person(int id, int age):m_id(id), m_age(age){};
    
    friend void showPerson(Person &);
    
    friend void test(Person &);

    void showPerson()
    {
        cout << "id = " <<m_id << " age = " << m_age << endl;
    }
    
};

void showPerson(Person &person)
{
    cout << "id = " << person.m_id << " age = " << person.m_age << endl;
}
void test(Person &person)
{
    cout << "id = " << person.m_id << " age = " << person.m_age << endl;
}
//void Person::showPerson()
//{
//    cout << "id = " << m_id << " age = " << m_age << endl;
//}


/**
 将自定义对象写入文件
 */
void pratcise7()
{
    Person p1(10, 20);
    Person p2(20, 30);
    string filePath =  "/Users/yiheng/Documents/copy1.txt";
    
//    创建out对象
    ofstream ofs(filePath, ios:: binary);
    
    ofs.write((char*) &p1, sizeof(Person));
    ofs.write((char*) &p2, sizeof(Person));
    
    ofs.close();
    
    
    Person p3;
    ifstream ifs;
    ifs.open(filePath, ios:: in| ios::binary);
    
    ifs.read((char*)&p3, sizeof(Person));
    
//    p3.showPerson();
    
    
    
}

/**
 计算value在数组中出现的个数

 @param begin 指向数组第一个元素的指针
 @param end 指向数组最后一个元素的下一位的指针
 @param value 待查的数
 @return value在数组中出现的个数
 */
int myCount(int *begin, int *end, int value)
{
    int count = 0;
    while (begin != end)
    {
        if (*begin == value)
        {
            count += 1;
        }
        begin++;
    }
    
    return count;
}

/**
 测试myCount
 */
void practise8()
{
    int array[] = {0, 22, 33, 10, 0, 20, 22, 0};
    
    int *pBegin, *pEnd;
    
    pBegin = array;
    
    pEnd = &array[sizeof(array) / sizeof(int)];
    
    
    cout << myCount(pBegin, pEnd,22) << endl;
}


void show(int value)
{
    cout << value << " ";
}

/**
 容器
 算法
 迭代器
 */
void practise9()
{
    vector<int> intV;
    
    for (int i = 0; i < 5 ; ++i)
    {
        intV.push_back(10 * i);
    }
    
    //
    for_each(intV.begin(), intV.end(), show);
    
}

void practise10()
{
    vector<Person> pVec;
    Person p1(10, 20), p2(20, 30), p3(30, 40);
    
    pVec.push_back(p1);
    pVec.push_back(p2);
    pVec.push_back(p3);
    
    
    //for range写法
    for (auto &pv : pVec) {
         pv.showPerson();
    }
    
    
    //正常for写法, 加入了迭代器
    for (auto begin = pVec.begin(); begin != pVec.end(); ++begin)
    {
        begin->showPerson();
    }
    
    //使用添加回调的迭代器
    for_each(pVec.begin(), pVec.end(), test);
    
}
int main(int argc, const char * argv[]) {
    
    
//    practise1();
    
//    practise2();
//    practise3();

//    practise5();
//    practist6();
    
//    pratcise7();
    
//    practise9();
    
    practise10();

    return 0;
}
