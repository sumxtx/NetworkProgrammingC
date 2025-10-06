#include "sock.h"

int main()
{
#if defined(_WIN32)
  WSAData d;
  if(WSAStartup(MAKEWORD(2,2), &d))
  {
    fprintf(stderr, "Failed to initialize.\n");
    return 1;
  }
#endif

  printf("Configuring local address...\n");
  struct addrinfo hints;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;      /*IPv4*/
  hints.ai_socktype = SOCK_DGRAM; /*UDP*/
  hints.ai_flags = AI_PASSIVE;    

  struct addrinfo *bind_address;
  getaddrinfo(0, "8080", &hints, &bind_address);

  printf("Creating socket...\n");
  SOCKET socket_listen;
  socket_listen = socket(bind_address->ai_family, bind_address->ai_socktype, bind_address->ai_protocol);
  if(!ISVALIDSOCKET(socket_listen))
  {
    fprintf(stderr, "socket() faile. (%d)\n", GETSOCKETERRNO());
    return 1;
  }

  printf("Binding socket to local address...\n");
  if(bind(socket_listen, bind_address->ai_addr, bind_address->ai_addrlen))
  {
    fprintf(stderr, "bind() failed. (%d)\n", GETSOCKETERRNO());
    return 1;
  }
  freeaddrinfo(bind_address);

  /* UDP server divergence from TCP starts here. Once the local address is bound
   * we don't need to call listen() or accept() we listen for incoming data */

  struct sockaddr_storage client_address;
  socklen_t client_len = sizeof(client_address);
  char read[1024];
  int bytes_received = recvfrom(socket_listen, read, 1024, 0, (struct sockaddr*)&client_address,&client_len);

  printf("Received (%d bytes): %.*s\n", bytes_received, bytes_received, read);
  printf("Remote address is: ");
  char address_buffer[100];
  char service_buffer[100];
  getnameinfo(((struct sockaddr*) &client_address), client_len, address_buffer, sizeof(address_buffer), service_buffer, sizeod(service_buffer), NI_NUMERICHOST | NI_NUMERICSERV);
  printf("%s %s\n", address_buffer, service_buffer);
}
