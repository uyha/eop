add_library(eop_utils INTERFACE)
add_library(eop::utils ALIAS eop_utils)
target_include_directories(eop_utils INTERFACE ${CMAKE_CURRENT_LIST_DIR})

add_executable(utils tests.cpp)
target_link_libraries(utils PRIVATE catch)
add_test(utils utils)
