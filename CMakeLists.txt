cmake_minimum_required(VERSION 3.20)

project(cpp_tasks LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(CPP_TASKS_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)

enable_testing()

include(cmake/FetchGoogleTest.cmake)

add_subdirectory(tests)
