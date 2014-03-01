cmake_minimum_required(VERSION 2.8)
project(Divisible)

set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_RPATH}:$$ORIGIN/../lib/:$ORIGIN/../lib/)

include_directories(inc)

add_subdirectory(src)
set(divisible_files main.c $<TARGET_OBJECTS:divisible_src>)

add_subdirectory(lib)
set(libs divisors)

add_executable(divisible ${divisible_files})
target_link_libraries(divisible ${libs})

install(
	TARGETS divisible
	RUNTIME DESTINATION bin
)