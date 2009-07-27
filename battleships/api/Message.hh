/* 
 * File:   BattleshipsAPIMessage.h
 * Author: sanath
 *
 * Created on June 29, 2009, 7:23 PM
 */

#ifndef _MESSAGE_H
#define	_MESSAGE_H

#include <iostream>
#include <map>
#include <cstring>
#include "Header.hh"
#include "Socket.hh"

using namespace std;

#define MSGTYPE_INITIATE         0
#define MSGTYPE_ACCEPT            1
#define MSGTYPE_REJECT            2
#define MSGTYPE_SALVO             3
#define MSGTYPE_SALVO_RESPONSE 4
#define MSGTYPE_MAX                5

extern const char* MsgTypeDesc[];

class Message {
public:
    Message(byte type);
    Message(Header* header, const char* buffer, int length);
    Message(const Message& orig);
    virtual ~Message();
    virtual const string toString();
    byte getMessageType();
    const string getMessageTypeString();
    void add(const string& tag, const string& value);
    void add(const string& tag, int value);
    bool has(const string& tag);
    const string& get(const string& tag);
    virtual void unmarshall(const char* buffer, int len);
    void send(Socket& s);
private:
    Header* header;
    map<string, string> body;
};

#endif	/* _MESSAGE_H */
