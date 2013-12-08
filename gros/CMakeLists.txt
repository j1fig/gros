cmake_minimum_required (VERSION 2.8.7)
project (gros)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SQLite REQUIRED sqlite3)
find_package(Boost 1.46.1 REQUIRED system thread)

include_directories(${Boost_INCLUDE_DIRS} ${SQLite_INCLUDE_DIRS})

file(GLOB_RECURSE PROJECT_SOURCES src/*.cpp)
add_executable (gros ${PROJECT_SOURCES})
target_link_libraries(gros ${Boost_LIBRARIES} ${SQLite_LIBRARIES})
