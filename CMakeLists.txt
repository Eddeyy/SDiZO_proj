cmake_minimum_required(VERSION 3.20)
project(SDiZO_proj)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/ae1b7ad4308249bfa928e65d1a33be117fc0992c.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(SDiZO_proj main.cpp
        DataStructures/DataStruct.hpp
        DataStructures/DArray/DynamicArray.hpp
        SDiZO_proj.hpp DataStructures/DList/DynamicList.hpp
        DataStructures/DList/DynamicList.tpp
        DataStructures/DArray/DynamicArray.tpp
        DataStructures/DList/ListElement.tpp
        DataStructures/DList/ListElement.hpp
        T_list
        T_list.cpp)


#target_link_libraries(
#        T_list
#        gtest_main
#)

add_test(NAME T_LIST COMMAND T_LIST)

include(GoogleTest)
#gtest_discover_tests(T_LIST)