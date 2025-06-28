cmake_minimum_required(VERSION 3.24)
project(l4)

set(CMAKE_CXX_STANDARD 17)

add_executable(l4 main.cpp BinaryTree.cpp LinkedList.cpp menu.cpp)
