#include <iostream>
//#include <gtest/gtest.h>
#include "SDiZO_proj.hpp"

int main(int argc, char* argv[])
{


    DynamicList<int> dList;

    dList.push_back(1);
    dList.push_back(1);
    dList.push_back(1);
    dList.push_back(1);
    dList.push_back(1);
    dList.push_back(1);

//    dList.put(2,1);

    dList.push_back(9);
    dList.push_front(82);

    dList.erase(0);

    dList.print();

    std::cout << std::endl << dList.length();



    std::cout << "\n\nFINISHED!\n";

    return 0;
}
