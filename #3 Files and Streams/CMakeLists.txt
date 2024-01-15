# CMakeLists.txt : CMake project for SearchingStrings, include source and define the project specific logic here.
cmake_minimum_required(VERSION 3.27)

# Set the project name to "SearchingStrings".
project(FilesAnStreams)

# Set the C++ standard to C++11.
set(CMAKE_CXX_STANDARD 11)

# Add the executable "BasicStringOperations" to the project.
add_executable(FileStreams "#1_File_Streams.cpp")

# Add the executable "StreamsAndOutputBuffering" to the project.
add_executable(StreamsAndOutputBuffering "#2_Streams_and_Output_Buffering.cpp")

# Add the executable "UnbufferedInputAndOutput" to the project.
add_executable(UnbufferedInputAndOutput "#3_Unbuffered_Input_and_Output.cpp")

# Add the executable "FilesModes" to the project.
add_executable(FilesModes "#4_Files_Modes.cpp")

# Add the executable "StreamMemberedFunctionsAndState" to the project.
add_executable(StreamMemberedFunctionsAndState "#5_Stream_Membered_Functions_and_State.cpp")

# Add the executable "StreamManipulatorsAndFormatting" to the project.
add_executable(StreamManipulatorsAndFormatting "#6_Stream_Manipulators_and_Formatting.cpp")

# Add the executable "FloatingPointOutputFormats" to the project.
add_executable(FloatingPointOutputFormats "#7_Floating_point_Output_Formats.cpp")

# Add the executable "StringStreams" to the project.
add_executable(StringStreams "#8_StringStreams.cpp")

# Add the executable "ResourceManagement" to the project.
add_executable(ResourceManagement "#9_Resource_Management.cpp")

# Add the executable "RandomAccessToStreams" to the project.
add_executable(RandomAccessToStreams "#10_Random_Access_to_Streams.cpp")

# Add the executable "StreamIterators" to the project.
add_executable(StreamIterators "#11_Stream_iterators.cpp")

# Add the executable "BinaryFiles" to the project.
add_executable(BinaryFiles "#12_Binary_Files.cpp")
