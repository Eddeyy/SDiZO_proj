//
// Created by thero on 19.03.2022.
//

#include "DataManager.hpp"

DataManager* DataManager::dataManager_ = nullptr;

DataManager::DataManager()
{

}

DataManager::DataManager(const std::string& dataDir)
: path{dataDir}
{

}

void DataManager::saveToFile(const std::string &)
{
//TODO implementation
}

// Bruuuuh..
DataStruct<int>* DataManager::loadFromFile(const std::string& fileName)
{
    std::fstream file;

    file.open(this->path + "/" + fileName);
    if(!file.good())
        throw ut::utilityException("Could not open " + this->path + "/test.json");


    std::string type;
    std::string line;
    int noe_;
    std::vector<int> values;

    DataStruct<int>* temp = nullptr;

    while(std::getline(file, line))
    {
        if(line == "{")
        {
            noe_ = 0;
            values.clear();
        }

        if(line.find("type")!=std::string::npos)
            type = line.substr(line.find(':') + 3, 3);

        if(line.find("num_of_elements")!=std::string::npos)
            noe_ = std::stoi(line.substr(line.find(':')+2, line.find(',')));

        if(line.find("arr")!=std::string::npos)
        {
            auto curReadPos = line.find('[');
            for(int i = 0; i<noe_; i++)
            {
                values.push_back(std::stoi(line.substr(curReadPos+1, line.find(',', curReadPos)-1)));
                curReadPos = line.find(',', curReadPos+1);
            }
        }

        if(line == "}")
        {
                if (type == "arr")
                    temp = new DynamicArray<int>();
                else if (type == "lst")
                    temp = new DynamicList<int>();

                if(temp!= nullptr)
                    for (int i = 0; i < noe_; i++)
                    {
                        temp->push_back(values[i]);
                    }
        }
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