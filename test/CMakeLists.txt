cmake_minimum_required(VERSION 4.0)

add_subdirectory(./lib/googletest-main)
set(gtest_SOURCE_DIR, ./lib/googletest-main/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILE runAllTests.cpp TestModel.cpp TestLoader.cpp)
add_executable(${TEST_SOURCE_FILE} runAllTests.cpp)
target_link_libraries(runAllTests.cpp gtest gtest_main core ${wxWidgets_LIBRARIES})
