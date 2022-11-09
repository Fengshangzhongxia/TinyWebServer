add_library(timer "")

target_sources(timer
PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/lst_timer.cpp
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/lst_timer.h
)

target_include_directories(timer
PUBLIC  
    ${CMAKE_CURRENT_LIST_DIR}
)