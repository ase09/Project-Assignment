/* 
 * File:   ClientSocket.cc
 * Author: sanath
 * 
 * Created on July 20, 2009, 2:58 PM
 */

#include "SocketException.hh"
#include "ClientSocket.hh"

ClientSocket::ClientSocket(const string& host, int port) {
    if (!Socket::create()) {
        throw SocketException("Could not create client socket.");
    }
    if (!Socket::connect(host, port)) {
        throw SocketException("Could not bind to port.");
    }
}

ClientSocket::ClientSocket(const ClientSocket& orig) {
}

ClientSocket::~ClientSocket() {
}

