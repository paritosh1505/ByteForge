cmake_minimum_required(VERSION 3.16)
project(byteforge LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SANITIZER -fsanitize=address,undefined)


add_library(byteforge src/string.cpp)
add_executable(byteTest 
        tests/test_string.cpp    
)
target_include_directories(byteforge PUBLIC include)

target_compile_features(byteforge PRIVATE cxx_std_17)

set_target_properties(byteforge PROPERTIES
    CXX_EXTENSIONS OFF
)
target_compile_options(byteTest PRIVATE ${SANITIZER})
target_link_options(byteTest PRIVATE ${SANITIZER})
target_link_libraries(byteTest byteforge)
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

    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(byteforge PRIVATE
            -g
            ${SANITIZER}
        )
        target_link_options(byteforge PRIVATE
            ${SANITIZER}
        )
        target_compile_options(byteTest PRIVATE 
        -g 
        ${SANITIZER}
        )
        target_link_options(byteTest PRIVATE 
        ${SANITIZER}
        )
    endif()
endif()
        
