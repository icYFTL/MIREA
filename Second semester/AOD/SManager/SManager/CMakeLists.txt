cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
include_directories(include)
set(SOURCES 
source/Console.cpp
source/Menu.cpp
source/Sorts.cpp
Smanager.cpp
)

add_executable(SManager ${SOURCES})

target_include_directories(SManager
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)
