#include <test_to.h>
#include <divisors/divisible.h>

// Count how many numbers divide evenly into every number from 0 to max_num.
divisible test_to(unsigned long max_num)
{
	unsigned long test_num;
	divisible number = new_divisible(0);
	divisible current_number = new_divisible(0);

	for (test_num = 0; test_num <= max_num; test_num++) {
		set_value(current_number, test_num);
		if (get_num_divisors(current_number) > get_num_divisors(number)) {
			set_value(number, get_value(current_number));
		}
	}

	free_divisible(current_number);
	return number;
}