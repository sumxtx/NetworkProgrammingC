## Networking Concepts With Socket Programming



### Q1

```C
    void get_broadcast_address(char *ip_addr, char mask, char output_buffer);
    /*
        char ipadd_buffer[PREFIX_LEN];
        memset(ipadd_buffer, 0 PREFIX_LEN);
        ...
        printf("Broadcast address = %s\n", ipadd_buffer);
        Usage: 
            ip_addr = "192.168.12.123"
            mask    = 24;
            output  = "192.168.2.255"

            ip_add  = "10.1.23.10"
            mask    = 20;
            output  = "10.1.31.255"
    */
```
### Q2 

```C
    unsigned int get_ip_integer_equivalent(char *ip_address);
    /*
        printf("Integer equivalent for %s is %u\n", ip_address, int_ip);
        Usage:
            ip_address  = "192.168.2.10"
            output      = 3232236042

            ip_address  = "10.1.23.10"
            output      = 167843594
    */
```
### Q3

```C
    void get_abcd_ip_format(unsigned int ip_address, char *output_buffer);
    /*
        char ipadd_buffer[PREFIX_LEN];
        memset(ipadd_buffer, 0, PREFIX_LEN);
        Usage:
            ip_address = 2058138165;
            output = 122.172.178.53;
    */
```
### Q4

```C
    void get_network_id(char *ip_addr, char mask, char* output_buffer);
    /*
        char ipadd_buffer[PREFIX_LEN];
        memset(ipadd_buffer, 0, PREFIX_LEN);
        char *ip_add = "192.168.2.10";
        char mask = 20;
        printf("Network Id = %s\n", ipadd_buffer);
        Usage:
    */  

```
### Q5

```C
    unsigned int get_subnet_cardinality(char mask);
    /*
        printf("Subnet cardinality for Mask = %u is %u\n", mask, get_subnet_cardinality(mask));
    */
```
### 6

```c
    int check_ip_subnet_membership(char *Network_id, char mask, char *check_ip);
    /*
        int result =
        if(result == 0)
            printf("%s is a member of subnet %s,/%u
        else
            printf("%s is not a member of subnet %s,/%u
    */
```
