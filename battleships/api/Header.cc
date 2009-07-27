/* 
 * File:   BattleshipsAPIHeader.cpp
 * Author: sanath
 * 
 * Created on June 29, 2009, 7:04 PM
 */

#include <string.h>
#include "Header.hh"

Header::Header() {
    header.apiFormat = 1;
    header.apiVersion = 0;
    header.sourceId = htons(54321);
    header.destinationId = 0;
    header.bodyLength = 0;
    header.messageType = 0;
}

Header::Header(const Header& orig) {
}

Header::Header(const BB_HEADER_T& h) {
    memcpy(&header, &h, sizeof (BB_HEADER_T));
}

Header::~Header() {
}

void Header::setMessageType(byte type) {
    header.messageType = type;
}

byte Header::getMessageType() {
    return header.messageType;
}

int Header::getSourceId() {
    return ntohs(header.sourceId);
}

void Header::setBodyLength(int value) {
    header.bodyLength = htons(value);
}

int Header::getBodyLength() {
    return ntohs(header.bodyLength);
}

void Header::send(Socket& s) {
    s.send(&header, sizeof (BB_HEADER_T));
}
