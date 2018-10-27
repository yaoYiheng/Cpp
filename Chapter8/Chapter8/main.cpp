//
//  main.cpp
//  Chapter8
//
//  Created by 姚懿恒 on 2018/10/27.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;



/**
 编写一个函数, 接受一个istream& 参数, 返回值类型也是 istream&.
 此函数须从给定的流中读取数据, 直遇到文件结束标识时停止, 它将读取的数据打印在标准输出上
 完成这些操作后, 在返回流之前, 对流进行复位, 使其处于有效状态.
 */
istream& practise8_1(istream& in)
{
    int value;
    
    while (in >>value, !in.eof())
    {
        if (in.bad())
        {
            throw runtime_error("IO流错误");
        }
        
        if (in.fail())
        {
            cerr << "数据错误, 请重试: "<<endl;
            in.clear();
            in.ignore(100, '\n');
            continue;
        }
        cout << value <<endl;
    }
    
    in.clear();
    return in;
}


/**
 编写函数, 以读模式打开一个文件, 将其内容读入到一个string的vector中, 将每一行作为一个独立的元素
 存于vector中
 */
void practise8_4()
{
    ifstream ifs;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    practise8_1(cin);
    return 0;
}
