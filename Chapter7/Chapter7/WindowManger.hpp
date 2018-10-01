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
    std::vector<Screen> screens{Screen(24, 80, ' ')};

public:
    void clear(ScreenIndex);
    
};
#endif /* WindowManger_hpp */
