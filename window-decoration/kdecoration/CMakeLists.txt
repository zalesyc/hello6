# add_definitions(-DTRANSLATION_DOMAIN="hello_kwin_deco")

project(hello)

cmake_minimum_required(VERSION 3.14)

# find_package(ECM REQUIRED NO_MODULE)

find_package(Qt6 CONFIG REQUIRED COMPONENTS DBus Core Widgets Gui Core5Compat)
find_package(KF6Config CONFIG REQUIRED)
find_package(KF6CoreAddons CONFIG REQUIRED)
find_package(KF6GuiAddons CONFIG REQUIRED)
find_package(KF6WindowSystem CONFIG REQUIRED)
find_package(KF6I18n CONFIG REQUIRED)
find_package(KF6ConfigWidgets CONFIG REQUIRED)
find_package(KDecoration3 CONFIG REQUIRED)
find_package(KF6KCMUtils CONFIG REQUIRED)

### XCB
# find_package(XCB COMPONENTS XCB)
# set_package_properties(XCB PROPERTIES
#   DESCRIPTION "X protocol C-language Binding"
#   URL "http://xcb.freedesktop.org"
#   TYPE OPTIONAL
#   PURPOSE "Required to pass style properties to native Windows on X11 Platform"
# )

# if(UNIX AND NOT APPLE)

#   set(HELLO_HAVE_X11 ${XCB_XCB_FOUND})

# else()

#   set(HELLO_HAVE_X11 FALSE)

# endif()

################# configuration #################
# configure_file(config-hello.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config-hello.h )

################# includes #################
# include_directories(${CMAKE_SOURCE_DIR}/libhellocommon)
# include_directories(${CMAKE_BINARY_DIR}/libhellocommon)
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
### config classes
### they are kept separately because they might move in a separate library in the future

set(hellodecoration_config_SRCS
    config/helloconfigwidget.cpp
    config/hellodetectwidget.cpp
    config/helloexceptiondialog.cpp
    config/helloexceptionlistwidget.cpp
    config/helloexceptionmodel.cpp
    config/helloitemmodel.cpp
)

set(hellodecoration_config_PART_FORMS
   config/ui/helloconfigurationui.ui
   config/ui/hellodetectwidget.ui
   config/ui/helloexceptiondialog.ui
   config/ui/helloexceptionlistwidget.ui
)

# ki18n_wrap_ui(hellodecoration_config_PART_FORMS_HEADERS ${hellodecoration_config_PART_FORMS})

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

### build library
add_library(hellodecoration MODULE
    ${hellodecoration_SRCS}
    ${hellodecoration_config_SRCS}
    ${hellodecoration_config_PART_FORMS}
    config/helloexceptionlistwidget.h
    )

target_link_libraries(hellodecoration
    PUBLIC
        Qt6::Core
        Qt6::Gui
        Qt6::DBus
    PRIVATE
        Qt6::Core5Compat
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
# install(FILES config/hellodecorationconfig.desktop DESTINATION  ${SERVICES_INSTALL_DIR})
