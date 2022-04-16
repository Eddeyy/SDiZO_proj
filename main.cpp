#include <iostream>
//#include <gtest/gtest.h>
#include "SDiZO_proj.hpp"
int main(int argc, char* argv[])
{
    {
    DataManager* dMan = DataManager::getInstance("./Data");

    DynamicArray<int> something = dMan->loadFromFile<int>("testunio.txt");

    DataStruct<int>* sth[2];
    sth[0] = new DLList<int>;
    sth[1] = new DynamicArray<int>;

    for(int i = 0; i <2 ; i++)
    {
        *sth[i] = dMan->loadFromFile<int>("test" + std::to_string(i) + ".txt");
    }

    for(auto s : sth)
        s->print();

    something.print();

    DLList<int> something1 = dMan->loadFromFile<int>("test1.txt");

    something1.print();

    std::cout << something1.find(69)->getValue() << std::endl;

    //something1->rfind(2137)

    std::cout << something.rfind(1)->getValue() << std::endl;
    dMan->saveToFile("testunio.txt",&something);

    for(auto & i : sth)
        delete i;

    std::cout << "\nFINISHED!\n";
    }
    std::cin.get();

    return 0;
}