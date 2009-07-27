/* 
 * File:   Socket.cpp
 * Author: sanath
 * 
 * Created on July 01, 2009, 7:17 AM
 */

#include <errno.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#include <string.h>
#include <sys/socket.h>
#include "Socket.hh"
#include "SocketException.hh"

#include <log4cplus/logger.h>
using namespace log4cplus;
static Logger logger = Logger::getInstance("Socket");

const int MAXHOSTNAME = 200;
const int MAXCONNECTIONS = 5;
const int MAXRECV = 500;

Socket::Socket() : m_sock(-1) {
    LOG4CPLUS_TRACE_METHOD(logger, "Socket()");
}

Socket::Socket(const Socket& orig) {
    m_sock = orig.m_sock;
}

Socket::~Socket() {
    if (isValid()) {
        ::close(m_sock);
    }
}

bool Socket::create() {
    m_sock = ::socket(AF_INET, SOCK_STREAM, 0);
    if (!isValid()) {
        return false;
    }
    // Setup to avoid TIME_WAIT
    int on = 1;
    if (setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR, (const char*)&(on), sizeof(on)) == -1) {
        return false;
    }
    return true;
}

bool Socket::bind(const int port) {
    if (!isValid()) {
        return false;
    }
    sockaddr_in m_addr;
    memset(&m_addr, 0, sizeof(m_addr));
    m_addr.sin_family = AF_INET;
    m_addr.sin_addr.s_addr = INADDR_ANY;
    m_addr.sin_port = htons(port);
    int bind_return = ::bind(m_sock, (struct sockaddr *)&(m_addr), sizeof(m_addr));
    return (-1 != bind_return);
}

bool Socket::listen() const {
    if (!isValid()) {
        return false;
    }
    int listen_return = ::listen(m_sock, MAXCONNECTIONS);
    return (-1 != listen_return);
}

bool Socket::accept(Socket& new_socket) const {
    sockaddr_in m_addr;
    memset(&m_addr, 0, sizeof(m_addr));
    int addr_length = sizeof(m_addr);
    new_socket.m_sock = ::accept(m_sock, (sockaddr *)&(m_addr), (socklen_t*)&(addr_length));
    return (new_socket.m_sock > 0);
}

bool Socket::send(const void* data, int length) const {
    int status = ::send(m_sock, data, length, MSG_NOSIGNAL);
/*
    int status;
    int i=0;
    const char* cdata = (const char*) data;
    while (i<length) {
      status = ::send(m_sock, cdata+i, 1, MSG_NOSIGNAL);
      i++;
      sleep(1);
    }
*/
    return (-1 != status);
}

bool Socket::send(const std::string s) const {
    return send(s.c_str(), s.size());
}

int Socket::recv(void* buffer, int length) const {
    int status = ::recv(m_sock, buffer, length, 0);
    return status;
}

int Socket::recv(std::string& s) const {
    char buf[MAXRECV + 1];
    s = "";
    memset(buf, 0, MAXRECV + 1);
    int status = ::recv(m_sock, buf, MAXRECV, 0);
    if (status == -1) {
        cout << "status == -1   errno == " << errno << "  in Socket::recv\n";
        return 0;
    } else if (0 == status) {
        return 0;
    } else {
        s = buf;
        return status;
    }
}

const Socket& Socket::operator << (const std::string& s) const {
  if (!send(s)) {
      throw SocketException("Could not write to socket.");
  }
  return *this;
}

const Socket& Socket::operator >> (std::string& s) const {
  if (!recv(s)) {
      throw SocketException ("Could not read from socket.");
  }
  return *this;
}

bool Socket::connect(const string host, const int port) {
    if (!isValid()) {
        return false;
    }
    sockaddr_in m_addr;
    memset(&m_addr, 0, sizeof(m_addr));
    m_addr.sin_family = AF_INET;
    m_addr.sin_port = htons(port);
    int status = inet_pton(AF_INET, host.c_str(), &m_addr.sin_addr);
    if (errno == EAFNOSUPPORT) {
        return false;
    }
    status = ::connect(m_sock, (sockaddr *)&(m_addr), sizeof(m_addr));
    return (0 == status);
}

void Socket::setNonBlocking(const bool set) {
    int opts = fcntl(m_sock, F_GETFL);
    if (opts < 0) {
        return;
    }
    if (set) {
        opts = (opts | O_NONBLOCK);
    } else {
        opts = (opts & ~O_NONBLOCK);
    }
    fcntl(m_sock, F_SETFL, opts);
}

