cmake_minimum_required(VERSION 3.30)
project(CodeGeneratorAPI LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
    zxing-cpp
    GIT_REPOSITORY https://github.com/zxing-cpp/zxing-cpp.git
    GIT_TAG master
)

FetchContent_MakeAvailable(zxing-cpp)

add_executable(server src/main.cpp src/QrGenerator.cpp src/DataMatrixGenerator.cpp)
target_link_libraries(server PRIVATE ZXing::ZXing)