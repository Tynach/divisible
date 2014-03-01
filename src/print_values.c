#include <stdio.h>
#include <divisors/divisible.h>

void print_divisors(divisible number)
{
	unsigned long* divisors = get_divisors(number);
	unsigned int num_divisors = get_num_divisors(number);
	int i;

	for (i = 0; i < num_divisors; i++) {
		printf("%lu, ", divisors[i]);
	}
	printf("%lu.\n", get_value(number));
}

void print_divisible(divisible number)
{
	printf("Number:\n\t%lu\n", get_value(number));
	printf("Number of Divisors:\n\t%u\n", get_num_divisors(number));
	printf("Divisors:\n\t");
	print_divisors(number);
}