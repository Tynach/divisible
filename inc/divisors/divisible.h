#ifndef DIVISORS_DIVISIBLE_H
#define DIVISORS_DIVISIBLE_H

/**************************
 * 'divisible' definition *
 **************************/

typedef struct _divisible* divisible;


/**********************************
 * 'divisible' method definitions *
 **********************************/

// Constructor
divisible new_divisible(unsigned long value);

// Getters
unsigned long get_value(divisible number);
unsigned int get_num_divisors(divisible number);
unsigned long* get_divisors(divisible number);

// Data Operations
void divide(divisible number);

#endif