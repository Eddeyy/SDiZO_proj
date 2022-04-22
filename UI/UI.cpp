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

    switch(cur_option)
    {
        case 0:
            switch(state)
            {
                case MenuState::Main:
                    desc_update("Create a new data structure from:\n"
                                     "Array, Doubly-Linked List, Binary Heap or\n"
                                     "Red-Black Tree.");
                    break;
                default:
                    desc_update("");
                    break;
            }
            break;
        case 1:
            switch(state)
            {
                case MenuState::Main:
                    desc_update("Delete from the existing data\n"
                                     "structures.\n");
                    break;
                default:
                    desc_update("");
                    break;
            }
            break;
        case 2:
            switch(state)
            {
                case MenuState::Main:
                    desc_update("Perform manual time tests on existing\n"
                                     "data structures.");
                    break;
                default:
                    desc_update("");
                    break;
            }
            break;
        case 3:
            switch(state)
            {
                case MenuState::Main:
                    desc_update("Perform fixed tests for all operations\n"
                                "on a set of 1000, 2000, 5000, 10000 and 20000\n"
                                "element filled data structures, then save results.");
                    break;
                default:
                    desc_update("");
                    break;
            }
            break;
        case 4:
            switch(state)
            {
                case MenuState::Main:
                    desc_update("Edit the structures present in current\n"
                                     "session.");
                    break;
                default:
                    desc_update("");
                    break;
            }
            break;
        case 5:
            switch(state)
            {
                case MenuState::Main:
                    desc_update("Create a structure filled with data from\n"
                                    "a given file of provided name.");
                    break;
                default:
                    desc_update("");
                    break;
            }
            break;
        default:
            switch(state)
            {
                case MenuState::Main:
                    desc_update("Exit the program.");
                    break;
                default:
                    break;
            }
            break;
    }

}

[[noreturn]] void UI::app()
{
    header_update("SDiZO_proj v1.0.0        by Adam Wysocki");
    options_update(main_menu);
    desc_update("Create a new data structure from:\n"
                "Array, Doubly-Linked List, Binary Heap or\n"
                "Red-Black Tree.");
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
    std::cout << "\n\n\n" << std::string(53, '=');
    std::cout << "\n\b" + this->opt_desc;
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

        if(num_of_opt==cur_max_option)
        {
            exit(0);
        }
        else
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
                case 2:
                    if(!structs.empty()){
                        header_update("Choose data structure to edit.");
                        std::vector<std::string> temp = list_available();

                        options_update(temp);
                        state = MenuState::DStruct_choice_manip;
                    }
                    else
                        header_update("There are no structs yet.");
                    break;

                case 3:
                    execute_auto_test();
                    std::cout << "\nPress ENTER to continue...";
                    std::cin.get();
                    break;
                default:
                    break;
            }
    }
    else if(state == MenuState::DStruct_choice_add)
    {
        if(num_of_opt==cur_max_option)
        {
            header_update("SDiZO_proj v1.0.0        by Adam Wysocki");
            options_update(main_menu);
            state = MenuState::Main;
        }
        else
            add_struct(num_of_opt);
    }
    else if(state == MenuState::DStruct_choice_del)
    {
        if(num_of_opt==cur_max_option)
        {
            header_update("SDiZO_proj v1.0.0        by Adam Wysocki");
            options_update(main_menu);
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
    else if(state == MenuState::DStruct_choice_manip)
    {
        if(num_of_opt==cur_max_option)
        {
            header_update("SDiZO_proj v1.0.0        by Adam Wysocki");
            options_update(main_menu);
            state = MenuState::Main;
        }
        else
        {
            cur_struct = structs[cur_option];
            state = MenuState::DStruct_manip;
            if(cur_struct!=nullptr)
                if(!dynamic_cast<BHeap<int>*>(cur_struct) && !dynamic_cast<RBTree<int>*>(cur_struct))
                    options_update(manip_opts);
                else
                    options_update(manip_opts_tree);

        }
    }
    else if(state == MenuState::DStruct_manip)
    {
        if(num_of_opt==cur_max_option)
        {
            header_update("SDiZO_proj v1.0.0        by Adam Wysocki");
            options_update(main_menu);
            state = MenuState::Main;
        }
        else if(!dynamic_cast<BHeap<int>*>(cur_struct) && !dynamic_cast<RBTree<int>*>(cur_struct))
            switch(cur_option)
            {
                case 0:
                    push_front();
                    break;
                case 1:
                    push_back();
                    break;
                case 2:
                    add();
                    break;
                case 3:
                    pop_back();
                    break;
                case 4:
                    pop_front();
                    break;
                case 5:
                    erase();
                    break;
                case 6:
                    print();
                    break;
                default:
                    break;
            }
            else
            switch(cur_option)
            {
                case 0:
                    add();
                    break;
                case 1:
                    erase();
                    break;
                case 2:
                    print();
                    break;
                default:
                    break;
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

void UI::desc_update(const std::string& desc)
{
    this->opt_desc = desc;
}

void UI::add()
{
    if(cur_struct != nullptr)
    {
        try
        {
            size_t val;
            size_t index;
            std::cout << "\n\n >>Specify the value : ";
            std::cin >> val;
            if(!dynamic_cast<BHeap<int>*>(cur_struct) && !dynamic_cast<RBTree<int>*>(cur_struct))
            {
                std::cout << "\n\n >>Specify the index : ";
                std::cin >> index;
            }
            cur_struct->add(val, index);
        }catch(std::exception& e)
        {
            std::cout << e.what();
            std::cout << "\nPress ENTER to continue...";
            std::cin.get();
            std::cin.get();

        }
    }
}

void UI::push_back()
{
    if(cur_struct != nullptr)
    {
        size_t val;
        std::cout << "\n\n >>Specify the value : ";
        std::cin >> val;
        cur_struct->push_back(val);
    }
}

void UI::push_front()
{
    if(cur_struct != nullptr)
    {
        size_t val;
        std::cout << "\n\n >>Specify the value : ";
        std::cin >> val;
        cur_struct->push_front(val);
    }
}

void UI::pop_back()
{
    if(cur_struct != nullptr)
    {
        try
        {
            cur_struct->pop_back();
        }catch(std::exception& e)
        {
            std::cout << e.what();
            std::cout << "\nPress ENTER to continue...";
            std::cin.get();
            std::cin.get();
        }
    }
}

void UI::pop_front()
{
    if(cur_struct != nullptr)
    {
        try
        {
            cur_struct->pop_front();
        }catch(std::exception& e)
        {
            std::cout << e.what();
            std::cout << "\nPress ENTER to continue...";
            std::cin.get();
            std::cin.get();
        }
    }
}

void UI::erase()
{
    if(cur_struct != nullptr)
    {
        try
        {
            size_t index;
            if(!dynamic_cast<BHeap<int>*>(cur_struct) && !dynamic_cast<RBTree<int>*>(cur_struct))
            {
                std::cout << "\n\n >>Specify the index : ";
                std::cin >> index;
                cur_struct->erase(index);
            }
            else
            {
                std::cout << "\n\n >>Specify the value : ";
                std::cin >> index;
                cur_struct->erase(index);
            }
        }catch(std::exception& e)
        {
            std::cout << e.what();
            std::cout << "\nPress ENTER to continue...";
            std::cin.get();
            std::cin.get();
        }
    }
}

void UI::print()
{
    if(cur_struct != nullptr)
    {
        system("cls");
        cur_struct->print();

        std::cout << "\n\n Printed representation of " << cur_struct->getName();
        std::cout << "\nPress ENTER to continue...";
        std::cin.get();
        std::cin.get();
    }
}

