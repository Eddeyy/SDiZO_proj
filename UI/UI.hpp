//
// Created by thero on 19.04.2022.
//

#ifndef SDIZO_PROJ_UI_HPP
#define SDIZO_PROJ_UI_HPP
#include <iostream>
#include "../DataStructures/DataStruct.hpp"
#include "../Utility/DataManager.hpp"
#include "../DataStructures/TestEnv/Tester.hpp"
#include <conio.h>

class UI
{
private:
    DataManager* dMan;
    Tester<int> tester;

    const std::string welcome_message =
            "=====================================================\n"
            "==    SDiZO_proj v1.0.0        by Adam Wysocki     ==\n"
            "=====================================================\n";

    std::vector<std::string> menu_options = {"1", "2", "3"};
    size_t cur_option;
    size_t cur_max_option;


    void menu_update(const char32_t& op);
    void print_menu();

public:
    UI();

    [[noreturn]] void app();

};


#endif //SDIZO_PROJ_UI_HPP
