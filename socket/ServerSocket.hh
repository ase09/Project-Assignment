/* 
 * File:   ServerSocket.hh
 * Author: sanath
 *
 * Created on July 20, 2009, 3:03 PM
 */

#ifndef _SERVERSOCKET_HH
#define	_SERVERSOCKET_HH

#include "Socket.hh"

class ServerSocket : public Socket {
public:
    ServerSocket(int port);
    ServerSocket();
    ServerSocket(const ServerSocket& orig);
    virtual ~ServerSocket();
private:
};

#endif	/* _SERVERSOCKET_HH */

