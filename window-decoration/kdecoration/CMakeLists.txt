project(hello)
cmake_minimum_required(VERSION 3.14)

find_package(Qt6 CONFIG REQUIRED COMPONENTS DBus Core Widgets Gui Core5Compat)
find_package(KF6Config CONFIG REQUIRED)
find_package(KF6CoreAddons CONFIG REQUIRED)
find_package(KF6GuiAddons CONFIG REQUIRED)
find_package(KF6WindowSystem CONFIG REQUIRED)
find_package(KF6I18n CONFIG REQUIRED)
find_package(KF6ConfigWidgets CONFIG REQUIRED)
find_package(KDecoration3 CONFIG REQUIRED)
find_package(KF6KCMUtils CONFIG REQUIRED)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

################# newt target #################
### plugin classes
set(hellodecoration_SRCS
    hellobutton.cpp
    hellodecoration.cpp
    helloexceptionlist.cpp
    hellosettingsprovider.cpp
    hellosizegrip.cpp
    libhellocommon/helloboxshadowrenderer.cpp
    )

kconfig_add_kcfg_files(hellodecoration_SRCS hellosettings.kcfgc)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

### build library
add_library(hellodecoration MODULE
    ${hellodecoration_SRCS}
    )

target_link_libraries(hellodecoration
    PUBLIC
        Qt6::Core
        Qt6::Gui
        Qt6::DBus
        Qt6::Core5Compat
    PRIVATE
        KDecoration3::KDecoration
        KF6::ConfigCore
        KF6::CoreAddons
        KF6::ConfigWidgets
        KF6::GuiAddons
        KF6::I18n
        KF6::WindowSystem
        KF6::KCMUtils
        )


install(TARGETS hellodecoration DESTINATION ${CMAKE_INSTALL_LIBDIR}/qt6/plugins/org.kde.kdecoration3)

add_subdirectory(config)