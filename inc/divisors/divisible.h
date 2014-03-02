#ifndef DIVISORS_DIVISIBLE_H
#define DIVISORS_DIVISIBLE_H

/**************************
 * 'divisible' definition *
 **************************/

typedef struct _divisible* divisible;


/**********************************
 * 'divisible' method definitions *
 **********************************/

// Constructor and Destructor
divisible new_divisible(unsigned long value);
divisible clone_divisible(divisible number);
void free_divisible(divisible number);

// Getters
unsigned long get_value(divisible number);
unsigned int get_num_divisors(divisible number);
unsigned long* get_divisors(divisible number);

// Setters
void set_value(divisible number, unsigned long value);

// Data Operations
void divide(divisible number);

#endif