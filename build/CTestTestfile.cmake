# CMake generated Testfile for 
# Source directory: E:/Krishna/Qt_CICD_Demo/Qt_Mingw_CICD
# Build directory: E:/Krishna/Qt_CICD_Demo/Qt_Mingw_CICD/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(runTests "E:/Krishna/Qt_CICD_Demo/Qt_Mingw_CICD/build/runTests.exe")
set_tests_properties(runTests PROPERTIES  _BACKTRACE_TRIPLES "E:/Krishna/Qt_CICD_Demo/Qt_Mingw_CICD/CMakeLists.txt;54;add_test;E:/Krishna/Qt_CICD_Demo/Qt_Mingw_CICD/CMakeLists.txt;0;")
subdirs("googletest")
