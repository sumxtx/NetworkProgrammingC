#include "inc.h"

void unset_bit(unsigned int *n, int *pos)
{
  *n = *n & ((1 << *pos) ^ 0xFFFFFFFF);
}
