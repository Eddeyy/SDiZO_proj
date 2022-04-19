//
// Created by thero on 19.04.2022.
//

#include "UI.hpp"

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77


UI::UI()
: cur_option{1}, cur_max_option{menu_options.size()}
{
 dMan = DataManager::getInstance("./Data");
}

void UI::menu_update(const char32_t& op)
{
    if(op == ARROW_UP && cur_option > 0)
    {
        cur_option--;
    }

    if(op == ARROW_DOWN && cur_option < cur_max_option-1)
    {
        cur_option++;
    }
}

[[noreturn]] void UI::app()
{
    std::cout << this->welcome_message;
    while(true)
    {
        char op;
        while((op = _getch()))
        {
            menu_update(op);
            print_menu();
        }
    }
}

void UI::print_menu()
{
    system("cls");
    for(int i =0; i<cur_max_option; i++)
    {
        if(i == cur_option)
            std::cout << ">>";
        std::cout << menu_options[i] << std::endl;
    }
}
