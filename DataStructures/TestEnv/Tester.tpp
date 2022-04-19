#ifndef SDIZO_PROJ_TESTER_TPP
#define SDIZO_PROJ_TESTER_TPP
#include "Tester.hpp"


template<typename T>
Tester<T>::Tester()
{
    e.seed(seed);
}

template<typename T>
Tester<T>::~Tester()
{
//TODO: implement to gowno
}

template<typename T>
std::vector<T> Tester<T>::genRand(const size_t& size)
{
    std::vector<T> temp;
    for(int i = 0; i<size; i++)
    {
        temp.push_back(e() - std::default_random_engine::max()/2);
    }
    std::cout << "\nGenerated " + std::to_string(size) + " random integers.\n";
    return temp;
}

template<typename T>
std::vector<T> Tester<T>::genFRand(const size_t& size)
{
    std::vector<T> temp;
    std::uniform_real_distribution<float> distribution(0.0, 1.0);
    for(int i = 0; i<size; i++)
    {
        temp.push_back(distribution(e));
    }
    std::cout << "\nGenerated " + std::to_string(size) + " random floating point numbers from 0.0 to 1.0\n";
    return temp;
}

template<typename T>
std::vector<T> Tester<T>::gen(const size_t& size, const int& v)
{
    std::vector<T> temp;
    std::uniform_real_distribution<float> distribution(0.0, 1.0);
    for(int i = 0; i<size; i++)
    {
        temp.push_back(v);
    }
    std::cout << "\nGenerated " + std::to_string(size) + " random floating point numbers from 0.0 to 1.0\n";
    return temp;
}

template<typename T>
std::vector<T> Tester<T>::gen(const size_t& size, const float& v)
{
    std::vector<T> temp;
    std::uniform_real_distribution<float> distribution(0.0, 1.0);
    for(int i = 0; i<size; i++)
    {
        temp.push_back(v);
    }
    std::cout << "\nGenerated " + std::to_string(size) + " random floating point numbers from 0.0 to 1.0\n";
    return temp;
}

template<typename T>
void Tester<T>::dumpToFile(const std::string &fileName, const size_t& its)
{
    std::fstream file;

    if(!ut::is_path_exists("Logs"))
        ut::make_directory("Logs");

    file.open("./Logs/" + fileName, std::ios::out);
    if(!file.good())
        throw ut::utilityException("Could not open Logs/" + fileName);

    file << ">>>Test data for " << fileName << "<<<\n";
    file << "Number of elements : " << subject->length() << "\n";
    file << "Number of tests performed : " << its << "\n";
    file << "==========================================\n";


    file << "push_back  : " << test_data[0] << "[ms]\n";
    file << "push_front : " << test_data[1] << "[ms]\n";
    file << "add        : " << test_data[2] << "[ms]\n";
    file << "pop_back   : " << test_data[3] << "[ms]\n";
    file << "pop_front  : " << test_data[4] << "[ms]\n";
    file << "erase      : " << test_data[5] << "[ms]\n";
    file << "whole test : " << test_data[6] << "[ms]\n";

    file.close();
    std::cout << "\nSuccessfully saved into \"" + fileName + "\" in Logs.\n";

}


template<typename T>
void Tester<T>::setSubject(DataStruct<T> *structure)
{
    if(structure != nullptr)
    {
        subject = structure;
    }
}

template<typename T>
void Tester<T>::clear()
{
    if(subject != nullptr)
        subject = nullptr;
}

template<typename T>
double Tester<T>::tpush_back(const size_t& val)
{
    if(subject != nullptr)
    {
        startCounter();

        subject->push_back(val);

        double time = getCounter();
        std::cout << "Elapsed time since call of push_back(): " << time << "[ms]\n";
        return time;
    }
    throw
            ut::utilityException("\n\nCould not perform time test : no subject instance provided!\n");
}

template<typename T>
double Tester<T>::tpush_front(const size_t& val)
{

    if(subject != nullptr)
    {
        startCounter();

        subject->push_front(val);

        double time = getCounter();
        std::cout << "Elapsed time since call of push_front(): " << time << "[ms]\n";
        return time;
    }
    throw
            ut::utilityException("\n\nCould not perform time test : no subject instance provided!\n");
}

template<typename T>
double Tester<T>::tadd(const size_t& val, size_t index)
{
    if(subject != nullptr)
    {
        if(index == -2)
            index = subject->length()/2;

        startCounter();
        subject->add(val,index);
        double time = getCounter();

        std::cout << "Elapsed time since call of add(): " << time << "[ms]\n";
        return time;
    }
    throw
            ut::utilityException("\n\nCould not perform time test : no subject instance provided!\n");
}

template<typename T>
double Tester<T>::tpop_back()
{

    if(subject != nullptr)
    {
        startCounter();

        subject->pop_back();

        double time = getCounter();
        std::cout << "Elapsed time since call of pop_back(): " << time << "[ms]\n";
        return time;
    }
    throw
            ut::utilityException("\n\nCould not perform time test : no subject instance provided!\n");

}

template<typename T>
double Tester<T>::tpop_front()
{

    if(subject != nullptr)
    {
        startCounter();

        subject->pop_front();

        double time = getCounter();
        std::cout << "Elapsed time since call of pop_front(): " << time << "[ms]\n";
        return time;
    }
    throw
            ut::utilityException("\n\nCould not perform time test : no subject instance provided!\n");

}

template<typename T>
double Tester<T>::terase(size_t index)
{
    if(subject != nullptr)
    {
        if(index == -2)
            index = subject->length()/2;

        startCounter();
        subject->erase(index);
        double time = getCounter();

        std::cout << "Elapsed time since call of erase(): " << time << "[ms]\n";
        return time;
    }
    throw
            ut::utilityException("\n\nCould not perform time test : no subject instance provided!\n");

}

template<typename T>
std::vector<double> Tester<T>::test_all()
{
    test_data.clear();
    double test_time = 0;

    startCounter();

    test_data.push_back(tpush_back(1));
    test_data.push_back(tpush_front(1));
    test_data.push_back(tadd(1));
    test_data.push_back(tpop_back());
    test_data.push_back(tpop_front());
    test_data.push_back(terase());

    for(auto d : test_data)
        test_time+=d;

    test_data.push_back(test_time);

    std::cout << "\n\n>>The full test took : " << test_time << "[ms]\n";

    return test_data;
}

template<typename T>
std::vector<double> Tester<T>::test_avg(const size_t& iterations)
{
    std::vector<double> avg_data(6, 0);
    const size_t struct_size = subject->length();
    test_data.clear();
    for(int i = 0; i<iterations; i++)
    {
        test_all();
        for(int j=0; j<test_data.size(); j++)
        {
            avg_data[j]+=test_data[j];
        }
        *subject = genRand(struct_size);
    }

    for(auto &d : avg_data)
        d=d/iterations;

    test_data = avg_data;
    return avg_data;
}
/////////////////////////////////////////////////////
///     Query performance counter functions       ///
/////////////////////////////////////////////////////

template<typename T>
void Tester<T>::startCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        std::cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

template<typename T>
double Tester<T>::getCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

#endif