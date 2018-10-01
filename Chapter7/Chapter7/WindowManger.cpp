//
//  WindowManger.cpp
//  Chapter7
//
//  Created by 姚懿恒 on 2018/10/1.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include "WindowManger.hpp"


void WindowManger:: clear(ScreenIndex index)
{
    Screen &s = screens[index];

    s.contents = std::string(s.height * s.width, ' ');

//    Screen myScreem(10, 20, 'X');
//    std::cout << "清理之前:" <<myScreem.contents <<std::endl;
//    myScreem.contents = "";
//    std::cout << "清理之后:" <<myScreem.contents <<std::endl;
    
}


WindowManger::ScreenIndex WindowManger::addScreen(const Screen& screen)
{
    screens.push_back(screen);
    return screens.size() - 1;
}
