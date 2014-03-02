#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <divisors/divisible.h>

/**************************
 * 'divisible' definition *
 **************************/

struct _divisible {
	unsigned long value;
	unsigned int num_divisors;

	unsigned long* divisors;
};


/**********************************
 * 'divisible' method definitions *
 **********************************/

// Constructors and Destructor
divisible allocate_ram()
{
	size_t struct_size = sizeof(struct _divisible);
	size_t array_size = sizeof(unsigned long) * 1000;
	size_t number_size = struct_size + array_size;

	divisible number = malloc(number_size);
	if (number == NULL) {
		printf("new_divisible() failed to allocate %zu bytes.\n", number_size);
		exit(EXIT_FAILURE);
	}
	number->divisors = (unsigned long*)(number + struct_size);

	return number;
}

divisible new_divisible(unsigned long value)
{
	divisible number = allocate_ram();

	number->value = value;
	divide(number);

	return number;
}

divisible clone_divisible(divisible number)
{
	// Return a new divisible identical to the one passed in.
	return new_divisible(number->value);
}

void free_divisible(divisible number)
{
	free(number);
}

// Getters
unsigned long get_value(divisible number)
{
	return number->value;
}

unsigned int get_num_divisors(divisible number)
{
	return number->num_divisors;
}

unsigned long* get_divisors(divisible number)
{
	// Do *not* let anyone modify the *actual* list.
	size_t array_size = sizeof(number->divisors[0]) * number->num_divisors;

	unsigned long* tmp = malloc(array_size);
	if (tmp == NULL) {
		printf("get_divisors() failed to allocate %zu bytes.\n", array_size);
		exit(EXIT_FAILURE);
	}

	memcpy(tmp, number->divisors, array_size);
	return tmp;
}

// Setters
void set_value(divisible number, unsigned long value)
{
	number->value = value;
	divide(number);
}

// Data Operations
void divide(divisible number)
{
	number->num_divisors = 0;

	unsigned long divisor;
	for (divisor = 1; divisor <= number->value; divisor++) {
		if (number->value % divisor == 0) {
			number->divisors[number->num_divisors] = divisor;
			number->num_divisors++;
		}
	}
}