cmake_minimum_required(VERSION 3.16)
project(byteforge LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Option to enable sanitizers
option(ENABLE_SANITIZER "Enable Address/UB Sanitizers" OFF)

add_library(byteforge src/string.cpp)

target_include_directories(byteforge PUBLIC include)
target_compile_features(byteforge PRIVATE cxx_std_17)

set_target_properties(byteforge PROPERTIES
    CXX_EXTENSIONS OFF
)

add_executable(byteTest tests/test_string.cpp)
target_link_libraries(byteTest byteforge)

# Common warnings (good, keep them)
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(byteforge PRIVATE
        -Wall
        -Wextra
        -Werror
        -Wconversion
        -pedantic
        -Wformat=2
        -Wshadow
        -Wnull-dereference
        -fno-omit-frame-pointer
        -fno-elide-constructors
    )

    target_compile_options(byteTest PRIVATE
        -Wall
        -Wextra
        -Werror
        -Wconversion
        -pedantic
    )
endif()

# Debug flags
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(byteforge PRIVATE -g)
    target_compile_options(byteTest PRIVATE -g)
endif()

# Sanitizer (ONLY when enabled)
if (ENABLE_SANITIZER)
    message(STATUS "Sanitizers enabled")

    target_compile_options(byteforge PRIVATE -fsanitize=address,undefined)
    target_link_options(byteforge PRIVATE -fsanitize=address,undefined)

    target_compile_options(byteTest PRIVATE -fsanitize=address,undefined)
    target_link_options(byteTest PRIVATE -fsanitize=address,undefined)
endif()