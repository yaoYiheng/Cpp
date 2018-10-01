//
//  main.cpp
//  Chapter7
//
//  Created by 姚懿恒 on 2018/9/30.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include <iostream>
#include "Person.hpp"
#include "Screen.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    

    Screen myScreen(5, 5,'X');
    myScreen.move(4, 0).set('#').display(cout);  
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";

    return 0;
}
