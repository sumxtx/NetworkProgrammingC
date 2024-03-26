#include <unistd.h>
#include <stdio.h>

#define PREFIX_LEN 16


void
get_broadcast_address(char *ip_addr /*,char mask, char output_buffer*/);
/* usage: 
 *      char ipadd_buffer[PREFIX_LEN];
 *      memset(ipadd_buffer, 0, PREFIX_LEN);
 *      char *ip_add = "192.168.146.115";
 *      char mask = 20;
 *      get_broadcast_address(ip_add, mask, ipadd_buffer);
 *      printf("Broadcast address = %s\n", ipadd_buffer);
 * */

unsigned int
get_ip_integral_equivalent(char *ip_address);
/* usage: */

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
