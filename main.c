#include "inc.h"

int main(void)
{
  int suf = 24;
  size_t mask = get_mask_value_uint(suf);
  printf("\n%d -> %u", suf, mask);
  return 0;
}
