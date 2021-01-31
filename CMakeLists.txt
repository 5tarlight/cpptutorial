cmake_minimum_required(VERSION 3.17)
project(cpptutorial)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpptutorial main.cpp func/FuncTemplate.h mystring/MyString.cpp mystring/MyString.h stdafx.h mystring/MyStringEx.cpp mystring/MyStringEx.h)