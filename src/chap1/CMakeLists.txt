add_executable(chap1 tests.cpp)
target_link_libraries(chap1 PRIVATE catch eop::utils)

add_test(chap1 chap1)