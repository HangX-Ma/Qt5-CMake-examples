cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(mplayer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Here we let find_package(<PackageName>...) try to find first Qt 6, and if that fails Qt 5, under the name QT. 
# If either of them is found, find_package will succeed, and the CMake variable QT_VERSION_MAJOR will be defined to either 5 or 6.
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS 
    Widgets
    Multimedia
)

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
    Widgets
    Multimedia 
)

set(QRC_SOURCE_FILES res.qrc)
qt5_add_resources(QRC_FILES ${QRC_SOURCE_FILES})
source_group("source" FILES ${QRC_SOURCE_FILES})

