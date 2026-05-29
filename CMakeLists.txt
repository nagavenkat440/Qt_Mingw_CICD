cmake_minimum_required(VERSION 3.16)

project(Qt_Mingw_CICD)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.12.12/5.12.12/mingw73_64")

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(Qt_Mingw_CICD
main.cpp
MainWindow.cpp
MainWindow.h
MainWindow.ui
)

target_link_libraries(Qt_Mingw_CICD
Qt5::Widgets
)

target_compile_options(runTests PRIVATE --coverage)
target_link_options(runTests PRIVATE --coverage)

# Calculator Library

add_library(calculator
calculator.cpp
)

target_include_directories(calculator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# GoogleTest

add_subdirectory(googletest)

enable_testing()

add_executable(runTests
tests/test_calculator.cpp
)

target_link_libraries(runTests
gtest
gtest_main
calculator
)

add_test(NAME runTests COMMAND runTests)
