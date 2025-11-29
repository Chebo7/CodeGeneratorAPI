cmake_minimum_required(VERSION 3.30)
project(CodeGeneratorAPI LANGUAGES CXX)
file(GLOB SERVER_SOURCES "src/*.cpp")
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
    zxing-cpp
    GIT_REPOSITORY https://github.com/zxing-cpp/zxing-cpp.git
    GIT_TAG master
)

FetchContent_MakeAvailable(zxing-cpp)

add_executable(server ${SERVER_SOURCES})
target_link_libraries(server PRIVATE ZXing::ZXing)