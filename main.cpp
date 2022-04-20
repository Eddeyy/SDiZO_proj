#include <iostream>
//#include <gtest/gtest.h>
#include "SDiZO_proj.hpp"
int main(int argc, char* argv[])
{

    {
    DataManager* dMan = DataManager::getInstance("./Data");
    Tester<int> t;
    UI ui;
    RBTree<int> bhp;

    DynamicArray<int> a;
    a = t.genRand(3);
    t.setSubject(&a);
    t.tadd(1);
    t.tfind(1);
    //t.test_all();
    //t.test_avg(3);


    ui.app();

    std::cout << "\nFINISHED!\n";
    }
    std::cin.get();

    return 0;
}