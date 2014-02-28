add_subdirectory("divisors")
file(GLOB divisible_files *.c)
add_library(test_to OBJECT ${divisible_files})
