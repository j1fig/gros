cmake_minimum_required (VERSION 2.8.7)
project (gui)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SQLite REQUIRED sqlite3)
find_package(OpenGL REQUIRED)
find_package(X11 REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${X11_INCLUDE_DIRS} ${SQLite_INCLUDE_DIRS})

file(GLOB_RECURSE PROJECT_SOURCES src/*.cpp)
add_executable (gros-gui ${PROJECT_SOURCES})
target_link_libraries(gros-gui ${OPENGL_LIBRARIES} ${SQLite_LIBRARIES} ${X11_LIBRARIES})
