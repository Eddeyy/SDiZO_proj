//
// Created by thero on 19.03.2022.
//

#ifndef SDIZO_PROJ_UTILITIES_HPP
#define SDIZO_PROJ_UTILITIES_HPP
#include <iostream>
#include <cstdlib>
#include <direct.h>
#include <sys/stat.h>
#include <fstream>
#include <exception>


namespace ut
{
    class utilityException : public std::exception
        {
        std::string error_message;
    public:
        explicit utilityException(const std::string &msg);
        const char* what() const noexcept override {return error_message.c_str();}

        };

        bool is_path_exists(const std::string& s);
        void make_directory(const std::string& s);
        bool file_exists(const std::string& fileName, const std::string& dir);
}

#endif //SDIZO_PROJ_UTILITIES_HPP
