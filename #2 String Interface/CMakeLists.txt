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
add_executable(AddingElementsToStrings "#3_Adding_Elements_to_Strings.cpp"
        "../#3 Files and Streams/#1_File_Streams.cpp")

# Add the executable "RemovingElementsToStrings" to the project.
add_executable(RemovingElementsToStrings "#4_Removing_Elements_from_Strings.cpp")

# Add the executable "ConvertingBetweenStringsAndNumbers" to the project.
add_executable(ConvertingBetweenStringsAndNumbers "#5_Converting_Between_Strings_and_Numbers.cpp")

# Add the executable "MiscellaneousStringOperations" to the project.
add_executable(MiscellaneousStringOperations "#6_Miscellaneous_String_Operations.cpp")

# Add the executable "CharacterFunctions" to the project.
add_executable(CharacterFunctions "#7_Character_Functions.cpp")