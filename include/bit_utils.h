#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef MAX_MASK_LEN
# define MAX_MASK_LEN 32
#endif // ! MAX_MASK_LEN

void unset_bit(unsigned int *n, int *pos);
unsigned int get_mask_value_uint(char mask_value);
