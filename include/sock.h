 /* On Windows */
#if defined(_WIN32)
# ifndef __WIN32__WINNT
# define __WIN32__WINNT 0x0600 /*Widows Api version 6.0 or above (Vista)*/
# endif
# include <winsock2.h>
# include <ws2tcpip.h>
# pragma comment(lib, "ws2_32.lib")
// socket() returns SOCKET.SOCKET a typedef for unsigned int
// returns INVALID_SOCKET if it fails
# define ISVALIDSOCKET(s) ((s) != INVALID_SOCKET)
// error number is retrieved by calling
# define GETSOCKETERRNO() (WSAGetLastError())

/* On Unix */
#else
# include <sys/types.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <sys/socket.h>
# include <unistd.h>
# include <errno.h>
//
// socket() returns a negative number on failure
// typedef int SOCKET to store a socket descriptor as SOCKET on all platforms
# define SOCKET int
# define ISVALIDSOCKET(s) ((s) >= 0)
// sockets are standard file descriptors so they can be closed
// using the standard close()
# define CLOSESOCKET(s) close(s)
// error number gets stored in the thread-global errno
# define GETSOCKETERRNO() (errno)
#endif
