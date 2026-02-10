<img src="hello_icon.png" align="right" width="128" /> hello6.
======

hello6. is a compilation of various color-schemes, themes, icons and more for the KDE Plasma desktop. It is unopinionated, putting _you_ in charge.


### Origin
This is a fork of the original [hello.](https://github.com/n4n0GH/hello) for KDE Plasma 5. Ported to Qt6 and KDecoration3, working on KDE Plasma 6.3+

## Content

| Package | WIP Status |
| --- | --- |
| [**Color Scheme**](https://github.com/zalesyc/hello6/tree/master/color-scheme)<br/>A beautifully crafted set of color schemes, supporting light and dark modes alike. | 90% done |
| ~~[**Application Style**]()<br/>Taking the best parts of KDE's own Breeze set and improving upon it subtly.~~ | Removed |
| [**Window Decoration**](https://github.com/zalesyc/hello6/tree/master/window-decoration)<br/>Allowing for granular customization, yet looking absolutely astonishing in every setting. | 90% done |
| [**Plasma Theme**](https://github.com/zalesyc/hello6/tree/master/plasma-theme)<br/>Completing your desktop experience with a well balanced and elegant Plasma theme, complementing your light or dark color scheme. | 90% done |
| ~~[**Effects**]()<br/>Rounding off the overall beautiful experience with the hello shader set.~~ | Removed |

## Installation

### Build Dependencies

To build the packages you have to install some build-tools for your system first. If you already built something from source chances are you might have some of those installed.

Build:
- CMake
- GCC-c++ or Clang

Run:
- Qt6 DBus Core Widgets Gui Core5Compat
- KF6Config
- KF6CoreAddons
- KF6GuiAddons
- KF6WindowSystem
- KF6I18n

### Manual Installation
Clone the repository and create the build directory:
``` shell
git clone https://github.com/zalesyc/hello6 && cd hello
```

``` shell
mkdir build && cd build
```

Configure and build:

_here you can add aditional parameters_
``` shell
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr ..
```
``` shell
cmake --build . --parallel
```
Install
``` shell
sudo cmake --install .
```
Finally log out and back in. 

You should now be able to use KDE's system settings to enable and modify the theme.
