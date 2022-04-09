#include <iostream>
//#include <gtest/gtest.h>
#include "SDiZO_proj.hpp"

int main(int argc, char* argv[])
{
    {
    DataManager* dMan = DataManager::getInstance("Data");

    DataStruct<int>* something = dMan->loadFromFile("test.json");

    something->print();

    DataStruct<int>* something1 = dMan->loadFromFile("test1.json");

    something1->print();

    std::cout << "\nFINISHED!\n";
    }
    std::cin.get();

    return 0;
}
