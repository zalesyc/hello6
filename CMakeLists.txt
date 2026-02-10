cmake_minimum_required(VERSION 3.16)
project(hello)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(WITH_COLOR_SCHEME      yes CACHE BOOL "Build with color-scheme")
set(WITH_PLASMA_THEME      yes CACHE BOOL "Build with plasma theme")
set(WITH_WINDOW_DECORATION yes CACHE BOOL "Build with window-decoration")

if(WITH_COLOR_SCHEME)
  add_subdirectory(color-scheme)
endif()

if(WITH_PLASMA_THEME)
  add_subdirectory(plasma-theme)
endif()

if(WITH_WINDOW_DECORATION)
  add_subdirectory(window-decoration)
endif()
