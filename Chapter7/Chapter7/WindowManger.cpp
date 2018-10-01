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
    
}
