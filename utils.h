// Utility functions for socket servers in C.
// This code is in the public domain.

#ifndef UTILS_H
#define UTILS_H

#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

// Dies (exits with a failure status) after printing the given printf-like
// message to stdout.
void die(char* fmt, ...);

// Reports a peer connection to stdout. sa is the data populated by a successful
// accept() call.
void report_peer_connected(const struct sockaddr_in* sa, socklen_t salen);

// Creates a bound and listening INET socket on the given port number. Returns
// the socket fd when successful; dies in case of errors.
int listen_inet_socket(int portnum);

#endif /* UTILS_H */
