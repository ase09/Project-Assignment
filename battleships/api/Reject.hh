/* 
 * File:   Reject.hh
 * Author: sanath
 *
 * Created on July 23, 2009, 5:55 AM
 */

#ifndef _REJECT_HH
#define	_REJECT_HH

#include <string>
#include "Message.hh"
using namespace std;

class Reject : public Message {
public:
    Reject(const string& gid, int rc);
    Reject(Header* header, const char* buffer, int length);
    Reject(const Reject& orig);
    virtual ~Reject();
    const string toString();
    void unmarshall(const char* buffer, int len);
private:
};

#endif	/* _REJECT_HH */

