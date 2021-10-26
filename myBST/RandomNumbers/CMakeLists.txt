cmake_minimum_required(VERSION 2.8)

project(RandomNumbers)


set(SOURCE_LIB randomNumbers.cpp)

add_library(RandomNumbers STATIC ${SOURCE_LIB})
