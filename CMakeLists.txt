cmake_minimum_required(VERSION 2.8)
project(Divisible)

include_directories("inc")
add_subdirectory("src")
set(divisible_files main.c $<TARGET_OBJECTS:test_to>)

set(libs divisors)

add_executable(divisible ${divisible_files})
target_link_libraries(divisible ${libs})
