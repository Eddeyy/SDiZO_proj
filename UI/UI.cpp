//
// Created by thero on 19.04.2022.
//

#include "UI.hpp"

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define ENTER_KEY 13


UI::UI()
: cur_option{0}, cur_max_option{menu_options.size()}
{
 dMan = DataManager::getInstance("./Data");
}

void UI::menu_update(const char32_t& op)
{
    if(op == ARROW_UP && cur_option > 0)
        cur_option--;

    if(op == ARROW_DOWN && cur_option < cur_max_option)
        cur_option++;

    if(op == ENTER_KEY)
        execute_option(cur_option);

}

[[noreturn]] void UI::app()
{
    header_update("SDiZO_proj v1.0.0        by Adam Wysocki");
    options_update({"Create data structure", "Delete data structure", "Test manually", "Perform auto-test" , "Exit"});
    print_menu();
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
    std::cout << header << std::endl;
    for(int i =0; i<=cur_max_option; i++)
    {
        std::cout << i+1 << ")";
        if(i == cur_option)
             std::cout << ">>";
        else
            std::cout << " ";
        std::cout << menu_options[i] << std::endl;
    }
}

void UI::header_update(const std::string &text)
{
    header.clear();
    header += "=====================================================\n";
    header += "==    ";
    header += text;
    if((45-text.size())>0)
        header += std::string(45 - text.size(), ' ');
    header.resize(105);
    header += "==";
    header += "\n";
    header += "=====================================================\n";
}

void UI::options_update(std::vector< std::string> opts)
{
    menu_options = opts;
    cur_option = 0;
    cur_max_option = opts.size()-1;
}

void UI::execute_option(const size_t &num_of_opt)
{
    if(state == MenuState::Main)
    {

        switch(num_of_opt)
        {
            case 0:
                header_update("Choose data structure to add.");
                options_update({"Dynamic Array"
                                    ,"Doubly-linked List"
                                    ,"Binary Max Heap"
                                    ,"Red-Black Tree"
                                    ,"[Return to main menu]"});
                state = MenuState::DStruct_choice_add;
                break;
            case 1:
                if(!structs.empty()){
                header_update("Choose data structure to delete.");
                std::vector<std::string> temp = list_available();

                options_update(temp);
                state = MenuState::DStruct_choice_del;
                }
                else
                    header_update("There are no structs yet.");
                break;
            case 3:
                execute_auto_test();
                break;
            case 4:
                exit(0);
                break;
            default:
                break;
        }
    }
    else if(state == MenuState::DStruct_choice_add)
    {
        switch(num_of_opt)
        {
            case 4:
                header_update("SDiZO_proj v1.0.0        by Adam Wysocki");
                options_update({"Create data structure", "Delete data structure", "Test manually", "Perform auto-test" , "Exit"});
                state = MenuState::Main;
                break;
            default:
                add_struct(num_of_opt);
                break;
        }
    }
    else if(state == MenuState::DStruct_choice_del)
    {
        if(num_of_opt==cur_max_option)
        {
            header_update("SDiZO_proj v1.0.0        by Adam Wysocki");
            options_update(
                    {"Create data structure", "Delete data structure", "Test manually", "Perform auto-test", "Exit"});
            state = MenuState::Main;
        }
        else
        {
            auto it = structs.begin();
            for(int i=0; i<structs.size(); i++, it++)
            {
                if(i==num_of_opt)
                    structs.erase(it);
            }
            std::vector<std::string> temp = list_available();
            options_update(temp);
        }
    }
}

void UI::add_struct(const unsigned int type)
{
    size_t size;
    std::cout <<"\n\n >> Specify the size : ";
    std::cin >> size;
    DataStruct<int>* temp;
    switch(type)
    {
        case 0:
            temp = new DynamicArray<int>;
            *temp = tester.genRand(size);
            structs.push_back(temp);
            break;
        case 1:
            temp = new DLList<int>;
            *temp = tester.genRand(size);
            structs.push_back(temp);
            break;
        case 2:
            temp = new BHeap<int>;
            *temp = tester.genRand(size);
            structs.push_back(temp);
            break;
        case 3:
            temp = new RBTree<int>;
            *temp = tester.genRand(size);
            structs.push_back(temp);
            break;
        default:
            break;
    }
}

std::vector<std::string> UI::list_available()
{
    std::vector<std::string> temp;
    for(auto s : structs)
        temp.push_back(s->getName());
    temp.push_back("[Return to main menu]");
    return temp;
}

void UI::execute_auto_test()
{
    DataStruct<int>* subj;

    int sizes[5] = {1000, 2000, 5000, 10000, 20000};

    subj = new DynamicArray<int>;
    for(int i = 0; i<5; i++)
    {
        tester.setSubject(subj);
        *subj = tester.genRand(sizes[i]);
        tester.test_avg(100);
        tester.dumpToFile("auto_test_" + subj->getName() + "_" + std::to_string(sizes[i]));
    }

    delete subj;

    subj = new DLList<int>;
    for(int i = 0; i<5; i++)
    {
        tester.setSubject(subj);
        *subj = tester.genRand(sizes[i]);
        tester.test_avg(100);
        tester.dumpToFile("auto_test_" + subj->getName() + "_" + std::to_string(sizes[i]));
    }

    delete subj;

    subj = new BHeap<int>;
    for(int i = 0; i<5; i++)
    {
        tester.setSubject(subj);
        *subj = tester.genRand(sizes[i]);
        tester.test_avg(100);
        tester.dumpToFile("auto_test_" + subj->getName() + "_" + std::to_string(sizes[i]));
    }

    delete subj;

    subj = new RBTree<int>;
    for(int i = 0; i<5; i++)
    {
        tester.setSubject(subj);
        *subj = tester.genRand(sizes[i]);
        tester.test_avg(100);
        tester.dumpToFile("auto_test_" + subj->getName() + "_" + std::to_string(sizes[i]));
    }

    delete subj;

}


