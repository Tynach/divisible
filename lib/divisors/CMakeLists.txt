file(GLOB divisors_files *.c)
add_library(divisors SHARED ${divisors_files})

install(
	TARGETS divisors
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)