cmake_minimum_required(VERSION 2.8)

project(server)

add_subdirectory(CGImysql)
add_subdirectory(log)
add_subdirectory(http)
add_subdirectory(timer)

aux_source_directory(. dir_srcs)
add_executable(server ${dir_srcs})

target_link_libraries(server mysqlclient pthread timer http log sqlcon)
