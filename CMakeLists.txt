cmake_minimum_required(VERSION 3.20)
project(SDiZO_proj)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        SDiZO_proj main.cpp
        DataStructures/DataStruct.hpp
        DataStructures/DArray/DynamicArray.hpp
        SDiZO_proj.hpp
        DataStructures/DList/DLList.hpp
        DataStructures/DList/DLList.tpp
        DataStructures/DArray/DynamicArray.tpp
        DataStructures/DList/ListElement.tpp
        DataStructures/DList/ListElement.hpp
        DataStructures/DArray/ArrayElement.hpp
        DataStructures/DArray/ArrayElement.tpp
        Utility/DataManager.hpp
        Utility/DataManager.tpp
        Utility/Utilities.hpp
        Utility/Utilities.cpp
        DataStructures/TestEnv/Tester.hpp
        DataStructures/TestEnv/Tester.tpp
        DataStructures/BHeap/BHeap.tpp
        DataStructures/BHeap/BHeap.hpp
        UI/UI.cpp
        UI/UI.hpp
        DataStructures/RBTree/RBTree.tpp
        DataStructures/RBTree/RBTree.hpp
        DataStructures/RBTree/Node.tpp
        DataStructures/RBTree/Node.hpp)
