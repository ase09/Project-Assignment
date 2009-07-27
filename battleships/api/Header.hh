/* 
 * File:   BattleshipsAPIHeader.h
 * Author: sanath
 *
 * Created on June 29, 2009, 7:04 PM
 */

#ifndef _HEADER_H
#define	_HEADER_H

#include <sys/types.h>
#include "Socket.hh"

typedef unsigned char byte;

#pragma pack(1)
typedef struct bbheader {
    byte apiVersion;
    byte apiFormat;
    byte messageType;
    byte reserved1;
    u_short sourceId;
    u_short destinationId;
    u_short bodyLength;
    u_short reserved2;
    u_int reserved3;
} BB_HEADER_T;
#pragma pack()

class Header {
public:
    Header();
    Header(const Header& orig);
    Header(const BB_HEADER_T&);
    virtual ~Header();
    void setMessageType(byte type);
    byte getMessageType();
    int getSourceId();
    void setBodyLength(int value);
    int getBodyLength();
    void send(Socket& s);
private:
    BB_HEADER_T header;
};

#endif	/* _HEADER_H */

