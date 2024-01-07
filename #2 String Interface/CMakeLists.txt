# CMakeLists.txt : CMake project for SearchingStrings, include source and define the project specific logic here.
cmake_minimum_required(VERSION 3.27)

# Set the project name to "SearchingStrings".
project(StringInterface)

# Set the C++ standard to C++17.
set(CMAKE_CXX_STANDARD 17)

# Add the executable "BasicStringOperations" to the project.
add_executable(BasicStringOperations "#1_Basic_String_Operations.cpp")

# Add the executable "SearchingStrings" to the project.
add_executable(SearchingStrings "#2_Searching_Strings.cpp")

# Add the executable "AddingElementsToStrings" to the project.
add_executable(AddingElementsToStrings "#3_Adding_Elements_to_Strings.cpp")

# Add the executable "RemovingElementsToStrings" to the project.
add_executable(RemovingElementsToStrings "#4_Removing_Elements_from_Strings.cpp")