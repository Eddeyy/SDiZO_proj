#include <iostream>
//#include <gtest/gtest.h>
#include "SDiZO_proj.hpp"
#include "Utility/DataManager.tpp"
int main(int argc, char* argv[])
{
    {
    DataManager* dMan = DataManager::getInstance("../Data");

    DataStruct<int>* something = dMan->loadFromFile("test.json");

    something->print();

    DataStruct<int>* something1 = dMan->loadFromFile("test1.json");

    something1->print();

    std::cout << something1->rfind(420)->getValue() << std::endl;

    //something1->rfind_el(2137)

    std::cout << "\nFINISHED!\n";
    }
    std::cin.get();

    return 0;
}
