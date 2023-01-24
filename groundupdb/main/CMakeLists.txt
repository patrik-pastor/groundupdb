add_executable(main main.cpp)

###TESTS###
find_package(Catch2)
add_executable(database_test
        database.cpp
        database.test.cpp)
target_link_libraries(database_test PRIVATE Catch2::Catch2WithMain)