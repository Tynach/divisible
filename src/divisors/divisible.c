#include <string.h>
#include <stdlib.h>
#include <divisors/divisible.h>

/**************************
 * 'divisible' definition *
 **************************/

struct _divisible {
	unsigned long value;
	unsigned int num_divisors;

	unsigned long divisors[1000];
};


/**********************************
 * 'divisible' method definitions *
 **********************************/

// Constructor
divisible new_divisible(unsigned long value)
{
	divisible number = malloc(sizeof(struct _divisible));
	number->value = value;
	divide(number);

	return number;
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
	unsigned long* tmp = malloc(sizeof(number->divisors[0]) * number->num_divisors);
	memcpy(tmp, number->divisors, sizeof(number->divisors[0]) * number->num_divisors);
	return tmp;
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