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
			free_divisible(number);
			number = current_number;
		} else {
			free_divisible(current_number);
		}
	}

	return number;
}