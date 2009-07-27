/* 
 * File:   ServerSocket.cc
 * Author: sanath
 * 
 * Created on July 20, 2009, 3:03 PM
 */

#include "SocketException.hh"
#include "ServerSocket.hh"

ServerSocket::ServerSocket(int port) {
    if (!Socket::create()) {
        throw SocketException("Could not create server socket.");
    }
    if (!Socket::bind(port)) {
        throw SocketException("Could not bind to port.");
    }
    if (!Socket::listen()) {
        throw SocketException("Could not listen on socket.");
    }
}

ServerSocket::ServerSocket() {
}

ServerSocket::ServerSocket(const ServerSocket& orig) {
}

ServerSocket::~ServerSocket() {
}

