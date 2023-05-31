cmake_minimum_required(VERSION 3.6)
project(
        ancpaint
        VERSION 0.1
        DESCRIPTION "ANCPAINT"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)


set (seqan3_git_tag "3.2.0") # adapt as needed, e.g. "3.2.0" or "master"
message (STATUS "Fetching SeqAn3 ${seqan3_git_tag}:")
include (FetchContent)
FetchContent_Declare (
        seqan3_fetch_content
        GIT_REPOSITORY "https://github.com/seqan/seqan3.git"
        GIT_TAG "${seqan3_git_tag}"
)
# Download and make SeqAn3 available.
FetchContent_MakeAvailable (seqan3_fetch_content)


add_executable(ancpaint main.cpp src/ancpaint.cpp include/ancpaint.h)

target_compile_options(ancpaint PUBLIC -Wall -Werror)
target_link_libraries(ancpaint ${CMAKE_SOURCE_DIR}/fCWT/build/debug/fCWT.lib seqan3::seqan3)
target_include_directories(ancpaint PUBLIC ${CMAKE_SOURCE_DIR}/includes)


