/* 
 * File:   Accept.hh
 * Author: sanath
 *
 * Created on July 23, 2009, 5:55 AM
 */

#ifndef _ACCEPT_HH
#define	_ACCEPT_HH

#include <string>
#include "Message.hh"

using namespace std;

class Accept : public Message {
public:
    Accept(const string& gid);
    Accept(Header* header, const char* buffer, int length);
    Accept(const Accept& orig);
    virtual ~Accept();
    const string toString();
    void unmarshall(const char* buffer, int len);
private:
};

#endif	/* _ACCEPT_HH */

