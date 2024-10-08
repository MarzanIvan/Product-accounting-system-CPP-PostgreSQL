<h3>The project was created for shop https://vk.com/gadgetkontaktvk</h3>
<img src="https://github.com/user-attachments/assets/c2a456a1-3fbf-4820-9fe0-89b7f6532044" width="350">
<br><br>

This is desktop application that use Qt community 6.7.2 Framework for macOS<br>
<div>Main platform is <i>macOS</i> operating system</div>
<div>Database is PostgreSQL: https://www.postgresql.org</div>
<div>UNIT testing: gtes: https://github.com/google/googletestt</div>
<div>CPP compiler Apple clang version 15.0.0 (clang-1500.3.9.4)</div>
<div>C++ used version is C++17<div>
<div>Build system: CMake</div>
For reports docx project uses DuckX library https://github.com/amiremohamadi/DuckX <br>
DuckX requires: <br>
<table> 
  <ul>
    <li>
      <span>kuba--/zip https://github.com/kuba--/zip</span>
    </li>
    <li>
      <span>zeux/pugixml https://github.com/zeux/pugixml</span>
    </li>
  </ul>
</table>


 <h4>Including PQXX library</h4>

```cmake
#PQXX Postgresql library
set(PQXX /opt/local/lib/libpqxx.a)
find_library(PQXX_LIB pqxx)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx")

#Libraries
target_include_directories(project PRIVATE ${BOOST_LIBRARY_INCLUDES} )
target_link_libraries(project
        ${USED_LIBS}
        ${PQXX_LIB}
)
```
<hr>
<h4>Including Boost 1.85.0 library</h4>

```cmake
#Boost library
FIND_PACKAGE(Boost 1.85.0 REQUIRED COMPONENTS  system thread regex)
set(BOOST_INCLUDE_LIBRARIES thread filesystem system program_options asio date_time)
set(BOOST_ENABLE_CMAKE ON)
SET(USED_LIBS ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

#Libraries
target_include_directories(project PRIVATE ${BOOST_LIBRARY_INCLUDES} )
```

<hr>
<h4>Including gtest library</h4>

  ```cmake
  # set this flag when running coverage tests
  set(CMAKE_CXX_FLAGS "--coverage")
  # generate debug information
  set(CMAKE_CXX_FLAGS "-g")
  #----------------------------------------------------

  add_subdirectory(lib/gtest/)

  # to link source files and include google test include/ folder to search the files
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
#after add_executable function
target_link_libraries(courseproject PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    ${USED_LIBS}
    ${PQXX_LIB}
    gtest gtest_main
)
```

<hr>
<h4>Including DUCKX library</h4>

```cmake
###INCLUDING DuckX lib
add_subdirectory(lib/DuckX-1.2.2/)
# to link source files and include DuckX-1.2.2 src/ folder to search the files
include_directories(lib/DuckX-1.2.2/include lib/DuckX-1.2.2/src)
set(DUCKX lib/DuckX-1.2.2/build/libduckx.a)
find_library(DUCKX_LIB duckx)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lduckx")


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
```


<hr>
<h4>Including Boost Logging library</h4>

```cmake
FIND_PACKAGE(Boost 1.85.0 REQUIRED COMPONENTS  system filesystem chrono atomic log   thread regex)
set(BOOST_INCLUDE_LIBRARIES thread filesystem log atomic chrono system program_options asio date_time)
SET(USED_LIBS ${Boost_SYSTEM_LIBRARY} ${Boost_ATOMIC_LIBRARY} ${Boost_CHRONO_LIBRARY}  ${Boost_THREAD_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} ${Boost_LOG_LIBRARY}  ${Boost_REGEX_LIBRARY})
set(BOOST_ENABLE_CMAKE ON)

target_link_libraries(courseproject PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    ${USED_LIBS}
    ${PQXX_LIB}
    gtest gtest_main
    duckx
    c++abi pthread
            /opt/homebrew/lib/libboost_system-mt.dylib
            /opt/homebrew/lib/libboost_thread-mt.dylib
            /opt/homebrew/lib/libboost_regex-mt.dylib
            /opt/homebrew/lib/libboost_chrono-mt.dylib
            /opt/homebrew/lib/libboost_atomic-mt.dylib
            /opt/homebrew/lib/libboost_log-mt.dylib
            /opt/homebrew/lib/libboost_log_setup-mt.dylib
            /opt/homebrew/lib/libboost_filesystem-mt.dylib
)


```
