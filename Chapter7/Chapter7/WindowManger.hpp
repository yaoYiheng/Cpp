//
//  WindowManger.hpp
//  Chapter7
//
//  Created by 姚懿恒 on 2018/10/1.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef WindowManger_hpp
#define WindowManger_hpp

#include <stdio.h>
#include <iostream>
#include "Screen.hpp"
#include <vector>


class WindowManger {
    
private:
    
    using ScreenIndex = std::vector<Screen>::size_type;
    //默认情况下，该类开始时总是拥有一个默认初始化的screen。
    std::vector<Screen> screens{Screen(24, 80, ' ')};

public:
    void clear(ScreenIndex);
    ScreenIndex addScreen(const Screen& screen); //添加一个新的屏幕并返回该屏幕的索引index
    
};
#endif /* WindowManger_hpp */
