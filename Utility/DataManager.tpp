//
// Created by thero on 19.03.2022.
//

#ifndef SDIZO_PROJ_DATAMANAGER_TPP
#define SDIZO_PROJ_DATAMANAGER_TPP

#include "DataManager.hpp"

DataManager* DataManager::dataManager_ = nullptr;

DataManager::DataManager()
{

}

DataManager::DataManager(const std::string& dataDir)
: path{dataDir}
{

}

template<typename T>
void DataManager::saveToFile(const std::string & fileName, DataStruct<T>* dataStr)
{
    std::fstream file;

    if(!ut::is_path_exists("Data"))
        ut::make_directory("Data");

    file.open(this->path + "/" + fileName, std::ios::out);
    if(!file.good())
        throw ut::utilityException("Could not open " + this->path + "/" + fileName);

    file << dataStr->length() << std::endl;
    for(int i = 0; i<dataStr->length(); i++)
    {
        file << (*dataStr)[i] << std::endl;
    }

    file.close();

    std::cout << "\nSuccessfully saved into \"" + fileName + "\" in \"" + path + "\".\n";
}

// Bruuuuh..
template<typename T>
std::vector<T> DataManager::loadFromFile(const std::string& fileName)
{
    std::fstream file;

    file.open(this->path + "/" + fileName);
    if(!file.good())
        throw ut::utilityException("Could not open " + this->path + "/" + fileName);

    std::string line;
    std::getline(file,line);
    int noe_ = std::stoi(line);

    std::vector<T> temp;

    while(std::getline(file, line) &&noe_--)
    {
        temp.push_back(std::stod(line));
    }

    return  temp;
}

DataManager *DataManager::getInstance(const std::string &dataDir)
{
    if(dataManager_ == nullptr)
    {
        dataManager_ = new DataManager(dataDir);
    };
    return dataManager_;
}

#endif