cmake_minimum_required(VERSION 2.8)


project(BST)

set(SOURCE_EXE main.cpp)


include_directories(RandomNumbers)


include_directories(bst)

add_executable(main ${SOURCE_EXE})

add_subdirectory(RandomNumbers)
add_subdirectory(bst)

target_link_libraries(main RandomNumbers bst)