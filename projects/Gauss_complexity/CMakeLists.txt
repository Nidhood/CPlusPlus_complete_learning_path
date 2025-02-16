cmake_minimum_required(VERSION 3.24)
project(Gauss_Complexity_Analysis CXX)

set(CMAKE_CXX_STANDARD 17)
set(EIGEN3_INCLUDE_DIR "./eigen")
include_directories(${EIGEN3_INCLUDE_DIR})
add_executable(gauss
        main.cxx
        src/gauss_complexity_analysis.cxx
)

include_directories(include)
include_directories(src)