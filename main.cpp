#include <iostream>
//#include <gtest/gtest.h>
#include "SDiZO_proj.hpp"

int main(int argc, char* argv[])
{
    /*{
        DynamicArray<float> fArray;

        fArray.push_back(9.2);
        fArray.push_back(8.8);
        fArray.push_front(6.9);

        fArray.put(7.2, 1);

        fArray.print();

        fArray.pop_back();

        fArray.print();

        fArray.pop_front();
        fArray.erase(0);

        fArray.print();
        {
            DynamicArray<float> fArray2 = fArray;

            fArray2.push_back(9.9);

            fArray2.print();

            fArray = fArray2;
        }

        fArray.print();
        std::cout << std::endl << fArray.length();
    }*/

    DynamicList<int> fList;

    fList.push_back(1.6);
    fList.push_back(2.3);
    fList.push_front(6.9);
    fList.push_back(5.91237);

    fList.print();

    std::cout << "\n\nFINISHED!\n";

    return 0;
}
