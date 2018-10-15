cmake_minimum_required(VERSION 3.12)
project(sort)

set(CMAKE_CXX_STANDARD 11)

add_executable(sort main.cpp heap.h findFun.h BST.h unionFind.h)