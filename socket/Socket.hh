/* 
 * File:   Socket.h
 * Author: sanath
 *
 * Created on July 01, 2009, 7:17 AM
 */

#ifndef _SOCKET_H
#define	_SOCKET_H

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

class Socket {
public:
    Socket();
    Socket(const Socket& orig);
    virtual ~Socket();

    // Server initialization
    bool create();
    bool bind(const int port);
    bool listen() const;
    bool accept(Socket&) const;

    // Client initialization
    bool connect(const string host, const int port);

    // Data Transimission
    // Binary
    bool send(const void* data, int length) const;
    int recv(void* buffer, int length) const;
    // Text
    bool send(const string) const;
    int recv(string&) const;
    const Socket& operator << (const string&) const;
    const Socket& operator >> (string&) const;

    // Misc.
    void setNonBlocking(const bool);
    bool isValid() const {
        return m_sock != -1;
    }

private:
    int m_sock;
};

#endif	/* _SOCKET_H */
