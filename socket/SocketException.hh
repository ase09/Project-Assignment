/*
 * File:   SocketException.h
 * Author: sanath
 *
 * Created on July 01, 2009, 7:25 AM
 */

#ifndef _SOCKETEXCEPTION_H
#define	_SOCKETEXCEPTION_H

#include <string>
#include <log4cplus/logger.h>
using namespace std;
using namespace log4cplus;

class SocketException {
public:
  SocketException(const string& s) : data(s) {
      //LOG4CPLUS_TRACE_METHOD(logger, "SocketException()");
      //LOG4CPLUS_TRACE(logger, "Args: <" << s << ">");
  }
  virtual ~SocketException() {
      //LOG4CPLUS_TRACE_METHOD(logger, "~SocketException()");
  }
  const string& description() {
      //LOG4CPLUS_TRACE_METHOD(logger, "SocketException::description()");
      //LOG4CPLUS_TRACE(logger, "Data: <" << data << ">");
      return data;
  }
private:
  string data;
};

#endif
