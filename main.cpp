#include <iostream>
//#include <gtest/gtest.h>
#include "SDiZO_proj.hpp"
int main(int argc, char* argv[])
{

    {
    DataManager* dMan = DataManager::getInstance("./Data");
    Tester<int> t;

    DLList<int> dlist = dMan->loadFromFile<int>("chuj.txt");
        t.setSubject(&dlist);

    dlist.print();

        t.test_all();
        t.dumpToFile("chuj_test.txt");
        t.dumpToFile("temp.txt");

    dlist.print();

        t.tpush_back(2);
        t.tpush_front(2);
        t.tadd(2);
        t.tpop_back();
        t.tpop_front();
        t.terase();

    dlist.print();

    //dlist.print();

    //dMan->saveToFile("chuj.txt",&dlist);

    std::cout << "\nFINISHED!\n";
    }
    std::cin.get();

    return 0;
}