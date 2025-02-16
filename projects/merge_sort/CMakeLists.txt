cmake_minimum_required(VERSION 3.24)
project(Gauss_Complexity_Analysis CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(gauss
        main.cxx
        src/merge_sort.cxx
)

include_directories(include)
include_directories(src)