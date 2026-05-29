include_directories(
../src
E:/Krishna/Qt_CICD_Demo/googletest-1.17.0/googletest/include
)

add_subdirectory(
E:/Krishna/Qt_CICD_Demo/googletest-1.17.0
googletest_build
)

add_executable(runTests
test_calculator.cpp
)

target_link_libraries(runTests
calculator
gtest
gtest_main
)

target_compile_options(runTests PRIVATE --coverage)
target_link_options(runTests PRIVATE --coverage)

add_test(NAME runTests COMMAND runTests)
