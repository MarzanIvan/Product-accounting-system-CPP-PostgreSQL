cmake_minimum_required(VERSION 3.16)

project(courseproject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


###INCLUDING GTEST lib

# set this flag when running coverage tests
set(CMAKE_CXX_FLAGS "--coverage")
# generate debug information
set(CMAKE_CXX_FLAGS "-g")
add_subdirectory(lib/gtest/)
# to link source files and include google test include/ folder to search the files
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

###INCLUDING DuckX lib
add_subdirectory(lib/DuckX-1.2.2/)
# to link source files and include DuckX-1.2.2 src/ folder to search the files
include_directories(lib/DuckX-1.2.2/include lib/DuckX-1.2.2/src)
set(DUCKX lib/DuckX-1.2.2/build/libduckx.a)
find_library(DUCKX_LIB duckx)


### Duckx dependencies

###INCLUDING pugixml lib
add_subdirectory(lib/zip-0.3.2/)
# to link source files and include zip-0.3.2 src/ folder to search the files
include_directories(lib/zip-0.3.2/include lib/zip-0.3.2/src)
set(zip lib/zip-0.3.2/build/libzip.a)
find_library(zip_LIB zip)

###INCLUDING pugixml lib
add_subdirectory(lib/pugixml-1.14/)
# to link source files and include pugixml-1.14 src/ folder to search the files
include_directories(lib/pugixml-1.14/include lib/pugixml-1.14/src)
set(pugixml lib/pugixml-1.14/build/libpugixml.a)
find_library(pugixml_LIB pugixml)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)


FIND_PACKAGE(Boost 1.85.0 REQUIRED COMPONENTS  system thread regex)
set(BOOST_INCLUDE_LIBRARIES thread filesystem system program_options asio date_time)
set(BOOST_ENABLE_CMAKE ON)
SET(USED_LIBS ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})
INCLUDE_DIRECTORIES(
    ${Boost_INCLUDE_DIRS}
)
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

#PQXX Postgresql library
set(PQXX /opt/local/lib/libpqxx.a)
find_library(PQXX_LIB pqxx)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx")


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(courseproject
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )


#Libraries
target_include_directories(courseproject PRIVATE ${BOOST_LIBRARY_INCLUDES} )

# Define target properties for Android with Qt 6 as:
#    set_property(TARGET courseproject APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(courseproject SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(courseproject
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(courseproject PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    ${USED_LIBS}
    ${PQXX_LIB}
    gtest gtest_main
    duckx
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.courseproject)
endif()
set_target_properties(courseproject PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS courseproject
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(courseproject)
endif()
