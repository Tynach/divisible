#include <stdio.h>
#include <test_to.h>
#include <divisors/divisible.h>

int main(int argc, char* argv[])
{
	unsigned long max_num;
	divisible number;

	// Grab the first number given at the command line, or default to 1024.
	if (argc == 1) {
		max_num = 1024;
	} else {
		max_num = strtoul(argv[1], NULL, 0);
	}

	number = test_to(max_num);

	printf("Value:\n\t%lu\n", get_value(number));
	printf("Number of Divisors:\n\t%u\n", get_num_divisors(number));
	printf("Divisors:\n\t");
	print_divisors(number);

	return 0;
}