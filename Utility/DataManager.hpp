//
// Created by thero on 19.03.2022.
//

#ifndef SDIZO_PROJ_DATAMANAGER_HPP
#define SDIZO_PROJ_DATAMANAGER_HPP
#include <vector>
#include <fstream>
#include "../DataStructures/DataStruct.hpp"
#include "../DataStructures/DArray/DynamicArray.hpp"
#include "../DataStructures/DArray/DynamicArray.tpp"
#include "../DataStructures/DList/DLList.hpp"
#include "../DataStructures/DList/DLList.tpp"
#include "Utilities.hpp"


class DataManager
{
private:

    static DataManager* dataManager_;

    std::string path;

    DataManager();
    explicit DataManager(const std::string& dataDir);

public:

    //void saveData();
    template<typename T>
    std::vector<T> loadFromFile(const std::string& fileName);
    //void loadData();
    template<typename T>
    void saveToFile(const std::string&,DataStruct<T>*);

    static DataManager* getInstance(const std::string& dataDir);

    DataManager(DataManager &other) = delete;
    void operator=(const DataManager &) = delete;

};


#endif //SDIZO_PROJ_DATAMANAGER_HPP
