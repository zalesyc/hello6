# add_definitions(-DTRANSLATION_DOMAIN="hello_kwin_deco")

project(hello)

cmake_minimum_required(VERSION 3.14)

# find_package(ECM REQUIRED NO_MODULE)
# set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

# include(KDEInstallDirs)

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
### config classes
### they are kept separately because they might move in a separate library in the future

# set(hellodecoration_config_SRCS
#     config/helloconfigwidget.cpp
#     config/hellodetectwidget.cpp
#     config/helloexceptiondialog.cpp
#     config/helloexceptionlistwidget.cpp
#     config/helloexceptionmodel.cpp
#     config/helloitemmodel.cpp)


# set(hellodecoration_config_PART_FORMS
#    config/ui/helloconfigurationui.ui
#    config/ui/hellodetectwidget.ui
#    config/ui/helloexceptiondialog.ui
#    config/ui/helloexceptionlistwidget.ui
# )


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

### build library
add_library(hellodecoration MODULE
    ${hellodecoration_SRCS}
    # ${hellodecoration_config_SRCS}
    # ${hellodecoration_config_PART_FORMS}
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
# install(FILES config/hellodecorationconfig.desktop DESTINATION  ${SERVICES_INSTALL_DIR})

add_subdirectory(config)