#include <stdio.h>
#include <stdlib.h>
#include <test_to.h>
#include <divisors/divisible.h>

// Count how many numbers divide evenly into every number from 0 to max_num.
divisible test_to(unsigned long max_num)
{
	unsigned long test_num;
	divisible current_number, number = new_divisible(0);

	for (test_num = 0; test_num <= max_num; test_num++) {
		current_number = new_divisible(test_num);
		if (get_num_divisors(current_number) > get_num_divisors(number)) {
			free(number);
			number = current_number;
		} else {
			free(current_number);
		}
	}

	return number;
}

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