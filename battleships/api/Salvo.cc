/* 
 * File:   Salvo.cc
 * Author: sanath
 * 
 * Created on June 29, 2009, 10:22 PM
 */

#include <iostream>
#include <stdlib.h>
#include "Salvo.hh"

// The message body would look like "NOT=3,T1=..,T2=..,T3=..".
// The minimum body length (for a 3 target salvo) would thus be 23.
#define MIN_BODY_LENGTH 23

Salvo::Salvo() : Message(MSGTYPE_SALVO) {
}

Salvo::Salvo(const string& gid, int sid, const char* t1, const char* t2, const char* t3) : Message(MSGTYPE_SALVO) {
    add("GID", gid);
    add("SID", sid);
    add("NOT", 3);
    add("T1", t1);
    add("T2", t2);
    add("T3", t3);
}

Salvo::Salvo(Header* header, const char* buffer, int length) : Message(header, buffer, length) {
}

Salvo::Salvo(const Salvo& orig) : Message(MSGTYPE_SALVO) {
}

Salvo::~Salvo() {
}

const string Salvo::toString() {
    string dump = Message::toString();
    dump += "\n";
    dump += "Received Salvo for game with id: <";
    dump += has("GID") ? get("GID") : "ERROR: Missing GID";
    dump += ">\n";
    dump += "Salvo id: <";
    dump += has("SID") ? get("SID") : "ERROR: Missing SID";
    dump += ">\n";
    dump += "Salvo size: <";
    dump += has("NOT") ? get("NOT") : "ERROR: Missing NOT";
    dump += ">\n";
    dump += "Salvo targets: <";
    dump += has("T1") ? get("T1") : "ERROR: Missing T1";
    dump += ", ";
    dump += has("T2") ? get("T2") : "ERROR: Missing T2";
    dump += ", ";
    dump += has("T3") ? get("T3") : "ERROR: Missing T3";
    dump += ">\n";
    return dump;
}

void Salvo::unmarshall(const char* buffer, int len) {
    if (MIN_BODY_LENGTH > len) {
        cerr << "ERROR!!! Received data length incorrect. Received=" << len << ", Min Required=" << MIN_BODY_LENGTH << endl;
        return;
    }
    Message::unmarshall(buffer, len);
}

int Salvo::getSalvoSize() {
    int size = has("NOT") ? atoi(get("NOT").c_str()) : -1;
    return size;
}