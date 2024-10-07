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
target_include_directories(chat PRIVATE ${BOOST_LIBRARY_INCLUDES} )
target_link_libraries(chat
        ${USED_LIBS}
        ${PQXX_LIB}
)
```
