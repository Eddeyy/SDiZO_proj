#include <iostream>
//#include <gtest/gtest.h>
#include "SDiZO_proj.hpp"
int main(int argc, char* argv[])
{

    {
    DataManager* dMan = DataManager::getInstance("./Data");
    Tester<int> t;

    DynamicArray<int> dlist = dMan->loadFromFile<int>("chuj.txt");
        t.setSubject(&dlist);

    dlist.print();

        t.test_avg(1000);
        t.dumpToFile("temp.txt");

        t.test_avg(100);
        t.dumpToFile("temp1.txt");

    dlist.print();

    std::cout << "\nFINISHED!\n";
    }
    std::cin.get();

    return 0;
}