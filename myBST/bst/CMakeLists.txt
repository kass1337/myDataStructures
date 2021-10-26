cmake_minimum_required(VERSION 2.8)

project(bst)


set(SOURCE_LIB bst.cpp)

add_library(bst STATIC ${SOURCE_LIB})
