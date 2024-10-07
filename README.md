

<h3>The project was created for shop https://vk.com/gadgetkontaktvk</h3>

<table style="width:100%" border-collapse:collapse; cellspacing="0" cellpadding="0">
  <tr>
    <td>
      <img src="https://github.com/user-attachments/assets/c2a456a1-3fbf-4820-9fe0-89b7f6532044" width="350"></td>
    <td>
      Интернет-Магазин «KONTAKT»<br>Магазин в 🌐ДНР г. Енакиево<br>
    </td>
  </tr>
</table>
<hr>

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
#PQXX Postgresql library
FIND_PACKAGE(Boost 1.85.0 REQUIRED COMPONENTS  system thread regex)
set(BOOST_INCLUDE_LIBRARIES thread filesystem system program_options asio date_time)
set(BOOST_ENABLE_CMAKE ON)
SET(USED_LIBS ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

#Libraries
target_include_directories(project PRIVATE ${BOOST_LIBRARY_INCLUDES} )
```
