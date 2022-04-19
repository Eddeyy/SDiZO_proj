//
// Created by thero on 16.04.2022.
//

#ifndef SDIZO_PROJ_TESTER_HPP
#define SDIZO_PROJ_TESTER_HPP
#include "../DataStruct.hpp"
#include "../../DataStructures/DArray/DynamicArray.hpp"
#include "../../DataStructures/DList/DLList.hpp"
#include "../../Utility/DataManager.hpp"
#include "../../Utility/Utilities.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <windows.h>

template<typename T>
class Tester
{
protected:
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();

    std::default_random_engine e;
    DataStruct<T>* subject;
    std::vector<double> test_data;

    double PCFreq = 0.0;
    __int64 CounterStart = 0;

    void startCounter();
    double getCounter();

public:
    Tester();
    ~Tester();

    std::vector<T> genRand(const size_t& size);
    std::vector<T> genFRand(const size_t& size);
    std::vector<T> gen(const size_t& size, const int& v);
    std::vector<T> gen(const size_t& size, const float& v);

    double tpush_back(const size_t& val = 1);
    double tpush_front(const size_t& val = 1);
    double tadd(const size_t& val = 1, size_t index = -2);
    double tpop_back();
    double tpop_front();
    double terase(size_t index = -2);

    std::vector<double> test_all();
    std::vector<double> test_avg(const size_t& iterations);

    void setSubject(DataStruct<T>* structure);
    void clear();

    void dumpToFile(const std::string &fileName, const size_t& its = 1);

};
#endif //SDIZO_PROJ_TESTER_HPP
