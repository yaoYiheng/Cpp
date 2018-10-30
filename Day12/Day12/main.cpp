//
//  main.cpp
//  Day12
//
//  Created by 姚懿恒 on 2018/10/23.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <functional>

#include <algorithm>
using namespace std;


#define SALE_DEPARTMENT 1
#define DEVELOP_DEPARTMENT 2
#define FINACIAL_DEPARTMENT 3
#define ALL_DEPARTMENT 4

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


/*
 mutimap案例
    公司找了5个员工, 需要指派员工在哪个部门工作
 人员信息有: 姓名, 年龄, 电话, 工资等
 通过mutimap进行信息的插入 保存 显示
 分部门显示员工信息, 显示全部员工信息

 */

class Employee
{
public:
    Employee() = default;
    Employee(string name, int age, string phone, int salary):mName(name), mAge(age), mPhone(phone), mSalary(salary){};
public:
    string mName;
    int mAge;
    string mPhone;
    int mSalary;
};

void printEmployee(vector<Employee>& vectEmp)
{
    
    for (auto &emp : vectEmp)
    {
        cout << "姓名:" << emp.mName
        << " 年龄:" << emp.mAge
        << " 电话:" << emp.mPhone
        << " 薪水:" << emp.mSalary <<endl;
    }

}
//创建员工
void CreateEmployee(vector<Employee>& vectEmp)
{
    string nameSeed = "员工";
    
    for (int i = 0; i < 10; ++i)
    {
        string name = nameSeed + to_string(i + 1);
        int age = 20 + rand() % 15;
        string phone = to_string(176) + to_string(rand() % 10000000);
        int salary = 4000 + rand() % 1000;
        
        Employee temp(name, age, phone, salary);
        
        vectEmp.push_back(temp);
    }
    
//    printEmployee(vectEmp);
}

//对员工进行分组, 因为可能会出现同一部门内有多个员工,
//对应的就是multumap允许多个key存在于一个multumap中
void EmployeeGroup(vector<Employee>&vectEmp,multimap<int, Employee>& employeeGroup)
{
    //将vectEmp中的元素随机分配到employeeGroup中
    for (auto emp : vectEmp)
    {
        int department = rand() % 3 + 1;
        
        switch (department) {
            case SALE_DEPARTMENT:
                employeeGroup.insert(make_pair(SALE_DEPARTMENT, emp));
                break;
            case DEVELOP_DEPARTMENT:
                employeeGroup.insert(make_pair(DEVELOP_DEPARTMENT, emp));
                break;
            case FINACIAL_DEPARTMENT:
                employeeGroup.insert(make_pair(FINACIAL_DEPARTMENT, emp));
                break;
                
            default:
                break;
        }
    }
    
    
}

void showEmployee(multimap<int, Employee>& employeeGroup, int departmentID)
{
    //先通过key找到迭代器
    auto iter = employeeGroup.find(departmentID);
    
    auto numOfEmployee = employeeGroup.count(departmentID);
    
    int num = 0;
    //需要对迭代器添加添加一个控制, 因为如果只是单纯的迭代器++, 会一直向后查找, 但是只需要
    //查找到对应的key的元素们的个数就可以了.所以需要多一个num来控制for循环.
    for (auto pos = iter; pos != employeeGroup.end() && num < numOfEmployee; ++pos, ++num)
    {
        cout << "姓名:" << pos->second.mName
        << " 年龄:" << pos->second.mAge
        << " 电话:" << pos->second.mPhone
        << " 薪水:" << pos->second.mSalary <<endl;
    }
}
//对multimap进行输出
void printGroup(multimap<int, Employee>& employeeGroup)
{
    cout << "财务部门员工:" <<endl;
    
    showEmployee(employeeGroup, FINACIAL_DEPARTMENT);
    
    cout << "开发部门员工:" <<endl;
    
    showEmployee(employeeGroup, DEVELOP_DEPARTMENT);
    
    cout << "销售部门员工:" <<endl;
    
    showEmployee(employeeGroup, SALE_DEPARTMENT);
}


void practise2()
{
    
    //创建i一个用于放置新员工的vector
    vector<Employee> vectEmp;
    
    // 通过mutimap进行信息的插入 保存 显示
    multimap<int, Employee> employeeGroup;
    
    
    //创建员工
    CreateEmployee(vectEmp);
    
    //对员工进行分组, 因为可能会出现同一部门内有多个员工,
    //对应的就是multumap允许多个key存在于一个multumap中
    EmployeeGroup(vectEmp, employeeGroup);
    
    //对multimap进行输出
    printGroup(employeeGroup);
}


class Person {
public:
    char * mName;
    int mAge;
    
public:
    Person() = default;
    Person(char *name, int age)
    {
        this->mName = new char[strlen(name) + 1];
        strcpy(this->mName, name);
        this->mAge = age;
    }
    Person(const Person &person)
    {
        this->mName = new char[strlen(person.mName) + 1];
        strcpy(this->mName, person.mName);
        this->mAge = person.mAge;
    }
    Person& operator=(const Person &person)
    {
        if (this->mName != NULL)
        {
            delete [] this->mName;
            this->mName = NULL;
        }
        
        this->mName = new char[strlen(person.mName) + 1];
        strcpy(this->mName, person.mName);
        this->mAge = person.mAge;
        
        return *this;
    }
    ~Person()
    {
        if (this->mName != NULL)
        {
            delete [] this->mName;
            this->mName = NULL;
        }
    }
};

void practise3()
{
    vector<Person> vectP;
    
    Person p1("Moriat", 100), p2("Kim", 200);
    
    vectP.push_back(p1);
    vectP.push_back(p2);
}
struct MyPrint: public binary_function<int, int, void>
{
    void operator()(int val, int add) const
    {
        cout << "val = " << val <<", Add = " << add << endl;
        cout << val + add << " " << endl;
    }
};


/**
 仿函数适配器 bind1st bind2nd 绑定适配器
 */
void practise4()
{
    vector<int> vInt;
    for (int i = 0; i < 10; ++i)
    {
        vInt.push_back(i);
    }
    
    
    int num = 111;
    
    
    for_each(vInt.begin(), vInt.end(), bind1st(MyPrint(), num));
    /*
     val = 111, Add = 0
     111
     val = 111, Add = 1
     112
     val = 111, Add = 2
     113
     val = 111, Add = 3
     114
     val = 111, Add = 4
     115
     val = 111, Add = 5
     116
     val = 111, Add = 6
     117
     val = 111, Add = 7
     118
     val = 111, Add = 8
     119
     val = 111, Add = 9
     120
     
     */
    
//    for_each(vInt.begin(), vInt.end(), bind2nd(MyPrint(), num));
    //绑定适配器, 将一个二元函数对象转变成一个一元函数对象
    
    /*
     val = 0, Add = 111
     111
     val = 1, Add = 111
     112
     val = 2, Add = 111
     113
     val = 3, Add = 111
     114
     val = 4, Add = 111
     115
     val = 5, Add = 111
     116
     val = 6, Add = 111
     117
     val = 7, Add = 111
     118
     val = 8, Add = 111
     119
     val = 9, Add = 111
     120
     
     */
    
    cout << endl;
    
}


void printVec(vector<int> &vint)
{
    for (auto &it : vint)
    {
        cout << it << " ";
    }
    
    cout << endl;
}

struct MyCompare: public binary_function<int, int, bool>
{
    bool operator()(int val1, int val2) const
    {
        return val1 > val2;
    }
};

struct GreatThan: public unary_function<int, bool>
{
    bool operator()(int val) const
    {
        return val > -1116;
    }
};
/**
 仿函数适配器 not1 not2 取反适配器
 */
void practise5()
{
    vector<int> vInt;
    
    for (int i = 0; i < 10; ++i)
    {
        vInt.push_back(rand() % 200);
    }
    
    printVec(vInt);
    
    //使用not2对二元谓词取反.
    sort(vInt.begin(), vInt.end(), not2(MyCompare()));
    
    printVec(vInt);
    
    sort(vInt.begin(), vInt.end(), MyCompare());
    
    printVec(vInt);
    
    
    //对一元谓词取反, 使用not1
    //返回第一个符合第三个参数的迭代器
    auto it = find_if(vInt.begin(), vInt.end(), not1(GreatThan()));
    
    if (it == vInt.end())
    {
        cout << "没有找到" << endl;
    }
    else
    {
        cout << *it << endl;
    }
    
    

}

void printInt(int val, int val2)
{
    cout << "val = "<< val + val2 << " , val2 = "<< val2 << endl;
    cout << val2 + 10 << endl;
}

/**
 ptr_func 函数对象适配器
 就是把普通函数转换成 函数对象
 */
void practise6()
{
    vector<int> vInt;
    
    for (int i = 0; i < 10; ++i)
    {
        vInt.push_back(rand() % 200);
    }
    
    sort(vInt.begin(), vInt.end());
    
    //将普通函数转化成函数对象之后, 就可以使用 not1, not2, bind2nd, bind1st,等适配器了
    for_each(vInt.begin(), vInt.end(), bind2nd(ptr_fun(printInt), 20));
}


class Human
{
public:
    int mAge;
    int mID;
    
public:
    Human() = default;
    Human(int age, int id):mAge(age), mID(id){}
    
    void show()
    {
        cout << "s年龄: "<< mAge << ", ID: " << mID <<endl;
    }
};


/**
 
 成员函数适配器
 mem_fun_ref与mem_fun
 
 如果想要通过for_each调用类的成员方法需要使用
 mem_fun_ref与mem_fun
 mem_fun_ref: 针对的是类对象
 mem_fun: 针对的是类对象的指针
 */
void practise7()
{
    Human hi(10, 20), h2(20, 30), h3(30, 40);
    
    vector<Human> hVint;
    
    hVint.push_back(hi);
    hVint.push_back(h2);
    hVint.push_back(h3);
    
    for_each(hVint.begin(), hVint.end(), mem_fun_ref(&Human::show));
    
    
    cout << "------------"<<endl;
    
    vector<Human*> pHVec;
    pHVec.push_back(&hi);
    pHVec.push_back(&h2);
    pHVec.push_back(&h3);
    
    for_each(pHVec.begin(), pHVec.end(), mem_fun(&Human::show));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
//    practise1();

//    practise2();
    
//    practise3();
    
//    practise4();
//    practise5();
    
//    practise6();
    
    practise7();
    
    return 0;
}
