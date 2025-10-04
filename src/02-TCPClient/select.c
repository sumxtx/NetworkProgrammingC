
/* Windows only support select() in sockets */

/* Unix based systems can use it on files and terminals I/O */


/*https://www.ibm.com/docs/en/i/7.4?topic=designs-using-poll-instead-select*/


/* Given a set of sockets it can be used to block until any of the sockets    */
/* in that set is ready to be read from. Can also be configured to return     */
/* if a socket is ready to be writen to, or if a socket has an error, after a */
/* period of time or none of these events take place                          */


/*Add Sockets into a fd_set */

// define file descriptors for the sockets
fd_set our_sockets;

// Zero out the fd_set
FD_ZERO(&our_sockets);

// add socket desscriptors
FD_SET(socket_listen, &our_sockets);
FD_SET(socket_a, &our_sockets);
FD_SET(socket_b, &our_sockets);

SOCKET max_socket;
max_socket = socket_listen;
if ( socket_a > max_socket ) max_socket = socket_a;
if ( socket_b > max_socket ) max_socket = socket_b;

// select modifies the fd_set to indicate which ones are ready
// copy our sockets set before calling it
fd_set copy;
copy = our_sockets;

// select for readability
select(
    max_socket + 1, /* int nfds                 */
    &copy,          /* fd_set *readfds          */
    0,              /* fd_set *writefds         */
    0,              /* fd_set *exceptfds        */
    0               /* struct timeval *timeout  */
    );
// select for writeability
select(
    max_socket + 1, /* int nfds                 */
    0,              /* fd_set *readfds          */
    &copy,          /* fd_set *writefds         */
    0,              /* fd_set *exceptfds        */
    0               /* struct timeval *timeout  */
    );
// select for exceptions
select(
    max_socket + 1, /* int nfds                 */
    0,              /* fd_set *readfds          */
    0,              /* fd_set *writefds         */
    &copy,          /* fd_set *exceptfds        */
    0               /* struct timeval *timeout  */
    );

// on select() return, copy is modified so that it only contains the sockets that 
// are ready to be read from
// FD_ISSET() checks if a socket is still in copy

if(FD_ISSET(socket_listen, &copy))
{
  // socket_listen has a new connection
  accept(socket_listen...)
}

if(FD_ISSET(socket_a, &copy))
{
  //socket_a is ready to be read from
  recv(socket_a...)
}

if(FD_ISSET(socket_b, &copy))
{
  //socket_b is ready to be read from
  recv(socket_b...)
}


//    timeout
//    struct timeval
//    {
//      long tv_sec;  // seconds
//      long tv_usec; // microseconds
//    }

// example: timeout for 1.5seconds
// return after a socket in fd_set copy is ready to read of after 1.5 seconds has elapsed
// null does not return until a socket is ready to be read
struct timeval timeout;
timeout.tv_sec = 1;
timeout.tv_usec = 500000;
select(max_socket + 1, &copy, 0,0,&timeout);

// iterating throught an fd_set
// all socket descriptors are positive numbers
SOCKET i;
for(i = 1; i <= max_socket; ++i)
{
  if(FD_ISSET(i, &master))
  {
    CLOSESOCKET(i);
  }
}


