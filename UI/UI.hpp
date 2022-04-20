//
// Created by thero on 19.04.2022.
//

#ifndef SDIZO_PROJ_UI_HPP
#define SDIZO_PROJ_UI_HPP
#include <iostream>
#include "../DataStructures/DataStruct.hpp"
#include "../DataStructures/BHeap/BHeap.hpp"
#include "../DataStructures/BHeap/BHeap.tpp"
#include "../DataStructures/RBTree/RBTree.hpp"
#include "../Utility/DataManager.hpp"
#include "../DataStructures/TestEnv/Tester.hpp"
#include "../DataStructures/TestEnv/Tester.tpp"
#include <conio.h>


enum class MenuState
{
    Main,
    DStruct_create,
    DStruct_choice_add,
    DStruct_choice_del,
    Manual_test,
    Auto_test
};

class UI
{
private:
    DataManager* dMan;
    Tester<int> tester;

    MenuState state = MenuState::Main;
    std::string header =
            "=====================================================\n"
            "==    SDiZO_proj v1.0.0        by Adam Wysocki     ==\n"
            "=====================================================\n";

    std::vector<std::string> menu_options = {"1", "2", "3"};
    size_t cur_option;
    size_t cur_max_option;

    std::vector<DataStruct<int>*> structs;

    void menu_update(const char32_t& op);
    void print_menu();

    void header_update(const std::string& text);
    void options_update(std::vector<std::string> opts);
    void execute_auto_test();
    void execute_option(const size_t& num_of_opt);
    std::vector<std::string> list_available();
    void add_struct(const unsigned int type);

public:
    UI();

    [[noreturn]] void app();

};



#endif //SDIZO_PROJ_UI_HPP
