/* 
 * File:   Initiate.cc
 * Author: sanath
 * 
 * Created on July 23, 2009, 5:53 AM
 */

#include "Initiate.hh"

// The message body would look like "GID=<GameId>".
// The minimum body length would thus be 5.
#define MIN_BODY_LENGTH 5

Initiate::Initiate(const string& gid) : Message(MSGTYPE_INITIATE) {
    add("GID", gid);
}

Initiate::Initiate(Header* header, const char* buffer, int length) : Message(header, buffer, length) {
}

Initiate::Initiate(const Initiate& orig) : Message(MSGTYPE_INITIATE) {
}

Initiate::~Initiate() {
}

const string Initiate::toString() {
    string dump = Message::toString();
    dump += "\n";
    if (!has("GID")) {
        dump += "Missing required tag: GID";
    } else {
        dump += "Request to initiate game with id: " + get("GID");
    }
    return dump;
}

void Initiate::unmarshall(const char* buffer, int len) {
    if (MIN_BODY_LENGTH > len) {
        cerr << "ERROR!!! Received data length incorrect. Received=" << len << ", Min Required=" << MIN_BODY_LENGTH << endl;
        return;
    }
    Message::unmarshall(buffer, len);
}
