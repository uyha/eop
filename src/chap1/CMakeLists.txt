add_executable(chap1_test tests.cpp)
target_link_libraries(chap1_test PRIVATE catch)

add_test(chap1_test chap1_test)