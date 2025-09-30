
set(hellodecoration_config_SRCS
    helloconfigwidget.cpp
    hellodetectwidget.cpp
    helloexceptiondialog.cpp
    helloexceptionlistwidget.cpp
    helloexceptionmodel.cpp
    helloitemmodel.cpp
    ../helloexceptionlist.cpp
)

set(hellodecoration_config_PART_FORMS
   ui/helloconfigurationui.ui
   ui/hellodetectwidget.ui
   ui/helloexceptiondialog.ui
   ui/helloexceptionlistwidget.ui
)


kconfig_add_kcfg_files(hellodecoration_config_SRCS ../hellosettings.kcfgc)

add_library(kcm_hellodecoration MODULE
    ${hellodecoration_config_SRCS}
    ${hellodecoration_config_PART_FORMS}
    )


target_link_libraries(kcm_hellodecoration 
    PUBLIC
        Qt6::Core
        Qt6::Gui
        Qt6::DBus
    PRIVATE
        Qt6::Core5Compat
        KF6::ConfigCore
        KF6::CoreAddons
        KF6::ConfigWidgets
        KF6::GuiAddons
        KF6::I18n
        KF6::WindowSystem
        KF6::KCMUtils
)
# kcmutils_generate_desktop_file(kcm_hellodecoration)

install(TARGETS kcm_hellodecoration DESTINATION ${CMAKE_INSTALL_LIBDIR}/qt6/plugins/org.kde.kdecoration3.kcm)


