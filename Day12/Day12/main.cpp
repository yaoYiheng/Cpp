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
int main(int argc, const char * argv[]) {
    // insert code here...
    
    
//    practise1();

    practise2();
    
    return 0;
}
