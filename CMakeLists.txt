cmake_minimum_required(VERSION 3.6)
project(
        ancpaint
        VERSION 0.1
        DESCRIPTION "ANCPAINT"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        seqan3
        GIT_REPOSITORY "https://github.com/seqan/seqan3"
        GIT_TAG "3.2.0"
)
FetchContent_MakeAvailable(seqan3)

add_executable(ancpaint main.cpp src/ancpaint.cpp)

target_compile_options(ancpaint PUBLIC -Wall -Werror)
target_link_libraries(ancpaint ${CMAKE_SOURCE_DIR}/fCWT/build/debug/fCWT.lib)
target_include_directories(ancpaint PUBLIC ${CMAKE_SOURCE_DIR}/includes)


