cmake_minimum_required(VERSION 2.8)

project(server)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

add_subdirectory(CGImysql)
add_subdirectory(log)
add_subdirectory(http)
add_subdirectory(timer)

aux_source_directory(. dir_srcs)
add_executable(server ${dir_srcs})

target_link_libraries(server 
    PRIVATE
        mysqlclient 
        pthread 
        timer 
        http 
        log 
        sqlcon
)
