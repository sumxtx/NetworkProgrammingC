#include <unistd.h>
#include <stdio.h>

#define PREFIX_LEN 16



int main()
{
  get_broadcast_address("192.168.10.1");
  return (0);
}

void get_broadcast_address(char *ip_addr /*,char mask, char output_buffer*/)
{
  int i,j;
  i = j = 0;
  int ip_nbr[4] = {0};

  while (ip_addr[i] != '\0')
  {
    if (ip_addr[i] != '.')
    {
      if ((!(ip_addr[i + j] >= '0' || ip_addr[i + j] <= '9')) || (j > 3))
      {
        printf("\n[!!] Error: Invalid IP.\n");
        return ;
      }
      write(1, &ip_addr[j], 1);
      j++;
    }
    else
    {
    i = j;
    j = 0;
    i++;
    }
  }
}
