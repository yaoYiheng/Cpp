//
//  Computer.cpp
//  Day7
//
//  Created by 姚懿恒 on 2018/9/5.
//  Copyright © 2018年 姚懿恒. All rights reserved.
//

#include "Computer.hpp"

Computer::Computer()
{
    
}
Computer::~Computer()
{
    cout << "Computer析构" <<endl;
    if (this->cpu != NULL)
    {
        delete this->cpu;
    }
    if (this->gpu != NULL)
    {
        delete this->gpu;
    }
    if (this->memory != NULL)
    {
        delete this->memory;
    }
}

Computer::Computer(CPU &cpu ,GPU &gpu, Memeory &memory)
{
//    this->cpu = cpu;
//    this->gpu = gpu;
//    this->memory = memory;
//
    cout << "组装了一台处理器是: "<<cpu.getBrand() << ", ";
    cout << "显卡是: "<<gpu.getBrand()<< ", ";
    cout << "内存是: "<<memory.getBrand()<< "的电脑"<<endl;
}
Computer::Computer(CPU *cpu ,GPU *gpu, Memeory *memory)
{
    this->cpu = cpu;
    this->gpu = gpu;
    this->memory = memory;
    cout << "组装了一台处理器是: "<<cpu->getBrand() << ", ";
    cout << "显卡是: "<<gpu->getBrand()<< ", ";
    cout << "内存是: "<<memory->getBrand()<< "的电脑"<<endl;
}


void Computer::work()
{
    this->cpu->calculate();
    this->gpu->display();
    this->memory->storage();
}
