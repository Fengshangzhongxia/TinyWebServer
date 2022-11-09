add_library(sqlcon "")

target_sources(sqlcon
PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/sql_connection_pool.cpp
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/sql_connection_pool.h
)

target_include_directories(sqlcon
PUBLIC  
    ${CMAKE_CURRENT_LIST_DIR}
)

