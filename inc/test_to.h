#ifndef TEST_TO_H
#define TEST_TO_H

#include <divisors/divisible.h>

// Count how many numbers divide evenly into every number from 0 to max_num.
divisible test_to(unsigned long max_num);
void print_divisors(divisible number);
void print_divisible(divisible number);

#endif