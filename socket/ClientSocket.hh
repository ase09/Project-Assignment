/* 
 * File:   ClientSocket.hh
 * Author: sanath
 *
 * Created on July 01, 2009, 2:58 PM
 */

#ifndef _CLIENTSOCKET_HH
#define	_CLIENTSOCKET_HH

#include <string>
#include "Socket.hh"
using namespace std;

class ClientSocket : public Socket {
public:
    ClientSocket(const string& host, int port);
    ClientSocket(const ClientSocket& orig);
    virtual ~ClientSocket();
private:
};

#endif	/* _CLIENTSOCKET_HH */

