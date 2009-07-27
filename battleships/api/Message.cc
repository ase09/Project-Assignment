/* 
 * File:   BattleshipsAPIMessage.cpp
 * Author: sanath
 * 
 * Created on June 29, 2009, 7:23 PM
 */

#include <sstream>
#include "Message.hh"

using namespace std;

const char* MsgTypeDesc[] = {
  "Initiate",
  "Accept",
  "Reject",
  "Salvo",
  "SalvoResponse"
};

Message::Message(byte type) {
    header = new Header();
    header->setMessageType(type);
}

Message::Message(Header* h, const char* buffer, int length) {
    this->header = h;
    unmarshall(buffer, length);
}

Message::Message(const Message& orig) {
}

Message::~Message() {
    if (NULL != header) {
        delete header;
    }
}

const string Message::toString() {
    string dump;
    dump = "Message: Type=<";
    dump += getMessageTypeString();
    dump += ">, Body=<";
    map<string, string>::iterator i;
    for (i = body.begin(); i != body.end(); i++) {
        if (body.begin() != i) {
            dump += ",";
        }
        dump += i->first;
        dump += "=";
        dump += i->second;
    }
    dump += ">";
    return dump;
}

byte Message::getMessageType() {
    return header->getMessageType();
}

const string Message::getMessageTypeString() {
    int type = (int) header->getMessageType();
    if ((type >= 0) & (type < MSGTYPE_MAX)) {
        return MsgTypeDesc[type];
    } else {
        return "UNKNOWN";
    }
}

void Message::add(const string& tag, const string& value) {
    body[tag] = value;
}

void Message::add(const string& tag, int value) {
    stringstream ss;
    ss << value;
    add(tag, ss.str());
}

bool Message::has(const string& tag) {
    map<string, string>::iterator i = body.find(tag);
    return (body.end() != i);
}

const string& Message::get(const string& tag) {
    return body[tag];
}

void Message::unmarshall(const char* buffer, int len) {
    char tbuf[len + 1];
    strncpy(tbuf, buffer, len);
    tbuf[len] = 0;
    char* t = strtok(tbuf, ",");
    while (NULL != t) {
        string ts = t;
        size_t pos = ts.find("=");
        if (string::npos != pos) {
            add(ts.substr(0, pos), ts.substr(pos + 1));
        }
        t = strtok(NULL, ",");
    }
}

void Message::send(Socket& s) {
    char buffer[1024];
    int len = 0;
    for (map<string, string>::iterator i = body.begin(); i != body.end(); i++) {
        const char* tag = i->first.c_str();
        const char* value = i->second.c_str();
        if (0 != len) {
            buffer[len++] = ',';
        }
        strcpy(buffer + len, tag);
        len += strlen(tag);
        buffer[len++] = '=';
        strcpy(buffer + len, value);
        len += strlen(value);
    }
    header->setBodyLength(len);
    header->send(s);
    s.send(buffer, len);
}
