/* 
 * File:   Initiate.hh
 * Author: sanath
 *
 * Created on July 23, 2009, 5:53 AM
 */

#ifndef _INITIATE_HH
#define	_INITIATE_HH

#include <string>
#include "Message.hh"
using namespace std;

class Initiate : public Message {
public:
    Initiate(const string& gid);
    Initiate(Header* header, const char* buffer, int length);
    Initiate(const Initiate& orig);
    virtual ~Initiate();
    const string toString();
    void unmarshall(const char* buffer, int len);
private:
};

#endif	/* _INITIATE_HH */

