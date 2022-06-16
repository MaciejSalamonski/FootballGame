cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS -pthread)

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

if (CMAKE_VERSION VERSION_LESS 3.2)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

project(FootballGame)
enable_testing()

set(SRC_LIST
    src/ApiCommunicator/ApiCommunicator.cpp
    src/DataParser/Reader.cpp
    src/DataParser/Parser.cpp
    src/DataManager/DataManager.cpp
    src/Timer/Timer.cpp
)

include_directories(src)
add_library(${PROJECT_NAME}-lib ${SRC_LIST})
add_executable(${PROJECT_NAME} src/main.cpp src/GuiManager/GuiManager.cpp)
find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib Qt5::Widgets Qt5::Core Qt5::Gui)


set(TEST_SRC_LIST
    test/DataParserTests/ReaderTests.cpp
    test/DataParserTests/ParserTests.cpp
)

link_libraries(gmock)
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}-ut)
add_executable(${PROJECT_NAME}-ut ${TEST_SRC_LIST})
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib)
target_link_libraries(${PROJECT_NAME}-ut gtest_main)
