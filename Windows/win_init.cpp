#include "sock.h" 
#include <stdio.h>
/*./include/sock.h*/

int main() {

	WSADATA d;
	if (WSAStartup(MAKEWORD(2, 2), &d)) {
		printf("Failed to initialize.\n");
		return(1);
	}

	WSACleanup();
	printf("Ok.\n");
	return(0);
}
