//
//  main.cpp
//  CommmandPattern
//
//  Created by 姚懿恒 on 2018/9/7.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include <istream>
#include <InputMethodKit/IMKInputController.h>

using namespace std;
class Command
{
public:
    virtual ~Command(){};
    
    virtual void execute() = 0;
};

class JumpCommand: public Command
{
    
public:
    virtual void execute(jump();)
};

class FireCommand: public Command
{
    
public:
    virtual void execute(fireGun();)
};
class InputHandler
{
private:
    
    
public:
    <#member functions#>
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
