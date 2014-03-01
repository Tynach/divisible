#include <stdio.h>
#include <stdlib.h>
#include <test_to.h>
#include <divisors/divisible.h>

int main(int argc, char* argv[])
{
	unsigned long max_nums[argc];
	divisible number;
	int i;

	// Grab the first number given at the command line, or default to 1024.
	if (argc == 1) {
		max_nums[0] = 1024;
		number = test_to(max_nums[0]);

		printf("Tested Up To:\n\t%lu\n", max_nums[i]);
		print_divisible(number);

		free(number);
	} else {
		for (i = 0; i < argc - 1; i++) {
			max_nums[i] = strtoul(argv[i + 1], NULL, 0);
		}

		for (i = 0; i < argc - 1; i++) {
			number = test_to(max_nums[i]);

			printf("Tested Up To:\n\t%lu\n", max_nums[i]);
			print_divisible(number);

			if (i == argc - 2) {
				free(number);
				break;
			}
			printf("\n");

			free(number);
		}
	}

	return 0;
}