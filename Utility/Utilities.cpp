//
// Created by thero on 19.03.2022.
//
#include "Utilities.hpp"


bool is_path_exists(const std::string& s)
{
    struct stat buffer;
    return (stat(s.c_str(), &buffer) == 0);
}

void make_directory(const std::string& s)
{
    if (_mkdir(s.c_str()) != 0)
    {
        throw ut::utilityException("Unable to create directory \"" + s + "\"");
    }
}

bool file_exists(const std::string& fileName, const std::string& dir)
{
    std::ifstream infile(dir + fileName);
    return infile.good();
}

ut::utilityException::utilityException(const std::string& msg)
: error_message{msg}
{};

