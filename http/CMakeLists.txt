add_library(http "")

target_sources(http
PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/http_conn.cpp
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/http_conn.h
)

target_include_directories(http
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

