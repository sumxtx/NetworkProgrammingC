#include "inc.h"

unsigned int get_mask_value_uint(char mask_value)
{
  unsigned int mask = 0xFFFFFFFF;
  char n_trails_bits = MAX_MASK_LEN - mask_value;
  int i = 0;
  for(; i < n_trails_bits; i++)
    unset_bit(&mask, &i);
  return mask;
}
