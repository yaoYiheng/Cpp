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

void printPerson(vector<Person> &pVector)
{
    cout << __func__<<endl;
    
    for (auto &pVecBegin: pVector )
    {
        pVecBegin.showPerson();
    }
}
/**
 容器嵌套容器
 */
void pratise11()
{
    vector<Person> pVec;
    Person p1(10, 20), p2(20, 30), p3(30, 40);
    pVec.push_back(p1);
    pVec.push_back(p2);
    pVec.push_back(p3);
    
    vector<Person> pVec1;
    Person p11(101, 20), p22(202, 30), p33(302, 40);
    pVec1.push_back(p11);
    pVec1.push_back(p22);
    pVec1.push_back(p33);
    
    
    vector<Person> pVec2;
    Person p111(103, 20), p222(203, 30), p333(303, 40);
    pVec2.push_back(p111);
    pVec2.push_back(p222);
    pVec2.push_back(p333);
    
    //嵌套容器
    vector<vector<Person>> pPVec;
    pPVec.push_back(pVec);
    pPVec.push_back(pVec1);
    pPVec.push_back(pVec2);
    
    printPerson(pVec);
    
    //交换元素
    pVec.swap(pVec1);
    
    printPerson(pVec);
    cout << "开始"<< endl;
    
    for (auto &pPVecbegin : pPVec)
    {
        for (auto &pVecBegin: pPVecbegin )
        {
            pVecBegin.showPerson();
        }
    }
    
    cout << pPVec.size() << endl;
    
}

void practise12()
{
    string s1 = "12341234";
    string s2 = "QWERT";
    
    //增
    s1 += s2;
    s1.append("keke");
    //查找rfind最后一次出现的位置
    cout << s1.rfind("1234") << endl;
    cout << s1[s1.rfind("1234")] <<endl;
    
    
//    插入
    //s1.insert(index, s2) 将从index位置上的字符 插入s2
    s1.insert(1, s2);
    cout << "s1 = " <<s1 << endl;
    
    
    string s3 = "abcdefg";
    //字符串的删除
    //erase(n)从[n]之后的字符都会被删除
    //erase(m, n)//从[m, n)之间的区间的字符串都会被删除, 不包含第[n]上的
    s3.erase(0, 2);
    cout << s3 <<endl;
    
    //s.replace(m, n, s2)从s[m],到s[n]的字符串, 替换成为s2
    s3.replace(1, 3, s2);
    cout <<"替换后" << s3 <<endl;
    
    
}

void printIntV(vector<int> &vint)
{
    for (auto &pVint: vint)
    {
        cout << pVint<<" ";
    }
    cout << endl;
}
void practise13()
{
    int array[] = {1, 22, 333,4444};
    //使用数组初始化
    
    vector<int> intVec(array, array + sizeof(array) / sizeof(int));
    
    printIntV(intVec);
}


void practise14()
{
    int array[] = {1001, 22, 333,4444};
    //使用数组初始化
    
    vector<int> intVec(array, array + sizeof(array) / sizeof(int));
    
    //返回容器中元素的个数
    cout << "size()该容器的size = " <<intVec.size() << endl;
    
    //判断元素是否为空
    intVec.empty()? cout <<"为空" << endl: cout <<"不为空" << endl;
    
    //resize(int num) 重新制定容器的长度为num, 若容器边长, 则以默认值填充新位置.
    //如果容器变短, 则末尾超出容器长度的元素被删除
    intVec.resize(5);
    printIntV(intVec);
    cout << "resize()前" <<endl;
    intVec.resize(3);
    printIntV(intVec);
    
    //resize(int num, elem), 超出的元素以elem填充
    intVec.resize(5, 222);
    printIntV(intVec);
    
    //capacity() 容量
    cout <<"容量是: " <<intVec.capacity() << endl;
    
    //删除迭代器指向的元素
    intVec.erase(intVec.begin() + 2);
    printIntV(intVec);
    
    //erase(start, end) 删除迭代器从start到end之间的元素.
    intVec.erase(intVec.begin() + 1, intVec.end() - 1);
    printIntV(intVec);
    
    //
    cout << "第一个元素是:" <<intVec.front() <<endl;
    cout << "最后一个元素是:" <<intVec.back() <<endl;
    //清除所有元素
    intVec.clear();
    printIntV(intVec);
    
    //当调用clear()之后的迭代器, 如果还是使用front()去访问迭代器元素, 会返回清除前的第一个位置的元素
    cout << "第一个元素是:" <<intVec.front() <<endl;
}


/**
 巧用swap释放内存空间
 */
void practise15()
{
    vector<int> vInt;
    
    for (int i = 0 ; i < 100000; ++i)
    {
        vInt.push_back(i);
    }
    cout << "swap前" << endl;
    vInt.resize(10);
    cout << "大小是: "<< vInt.size() << endl;
    cout << "容积是: "<< vInt.capacity() << endl;
    
    
    cout << "swap后" << endl;
    
    //使用vInt去初始化一个匿名对象, 并调用swap与vInt交换指针.
    vector<int>(vInt).swap(vInt);
    
    cout << "大小是: "<< vInt.size() << endl;
    cout << "容积是: "<< vInt.capacity() << endl;
}
int main(int argc, const char * argv[]) {
    
    
//    practise1();
    
//    practise2();
//    practise3();

//    practise5();
//    practist6();
    
//    pratcise7();
    
//    practise9();
    
//    practise10();
    
//    pratise11();
    
//    practise12();
    
//    practise13();
    
//    practise14();
    
    practise15();

    return 0;
}
