cmake_minimum_required(VERSION 3.20)
project(FLTK_First VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    fltk
    GIT_REPOSITORY https://github.com/fltk/fltk.git
    GIT_TAG master
    GIT_SHALLOW TRUE
)

set(FLTK_BUILD_TEST OFF CACHE BOOL "" FORCE)
set(FLTK_BUILD_FLUID OFF CACHE BOOL "" FORCE)
set(FLTK_BUILD_FLTK_OPTIONS OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(fltk)

include_directories(${CMAKE_SOURCE_DIR}/PPP)

set(PPP_SOURCES
    PPP/Graph.cpp
    PPP/Window.cpp
    PPP/GUI.cpp
    PPP/Simple_window.cpp
)

add_executable(${PROJECT_NAME}
    12_Study.cpp
    ${PPP_SOURCES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    fltk
    fltk_images
)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        gdiplus ole32 uuid comdlg32 winspool comctl32 ws2_32
    )
endif()
