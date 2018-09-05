//
//  Computer.hpp
//  Day7
//
//  Created by 姚懿恒 on 2018/9/5.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#ifndef Computer_hpp
#define Computer_hpp
#include <iostream>
#include "CPU.hpp"
#include "GPU.hpp"
#include "Memeory.hpp"
#include "BaseCPU.hpp"
#include "BaseGPU.hpp"
#include "BaseMemory.hpp"
using namespace std;
#include <stdio.h>

class Computer
{
    CPU *cpu;
    GPU *gpu;
    Memeory *memory;
    
//    CPU cpu;
//    GPU gpu;
//    Memeory memory;
public:
    Computer();
    ~Computer();
    Computer(CPU *cpu ,GPU *gpu, Memeory *memory);
    Computer(CPU &cpu ,GPU &gpu, Memeory &memory);

    void work();
};
#endif /* Computer_hpp */
