#include <iostream>
//#include <gtest/gtest.h>
#include "SDiZO_proj.hpp"
int main(int argc, char* argv[])
{

    {
    DataManager* dMan = DataManager::getInstance("./Data");
    Tester<int> t;
    UI ui;

//    DynamicArray<int> dlist = dMan->loadFromFile<int>("chuj.txt");
//        t.setSubject(&dlist);
//
//    dlist.print();
//
//        t.test_avg(1000);
//        t.dumpToFile("temp.txt", 1000);
//
//        t.test_avg(100);
//        t.dumpToFile("chuj_test.txt", 100);
//
//    dlist.print();

    ui.app();

    BHeap<int> bhp;

    bhp.add(1);
    bhp.add(2);
    bhp.add(3);
    bhp.add(4);

    std::cout << bhp.getName();

    std::vector<int> a = {124, 56, -12, -1, 0, 690};

    dMan->saveToFile("heap_data.txt", &bhp);

    bhp = a;

    bhp.print();

    dMan->saveToFile("heap_data.txt", &bhp);


    std::cout << "\nFINISHED!\n";
    }
    std::cin.get();

    return 0;
}