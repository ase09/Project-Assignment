/* 
 * File:   Accept.cc
 * Author: sanath
 * 
 * Created on July 23, 2009, 5:55 AM
 */

#include "Accept.hh"

// The message body would look like "GID=<GameId>".
// The minimum body length would thus be 5.
#define MIN_BODY_LENGTH 5

Accept::Accept(const string& gid) : Message(MSGTYPE_ACCEPT) {
    add("GID", gid);
}

Accept::Accept(Header* header, const char* buffer, int length) : Message(header, buffer, length) {
}

Accept::Accept(const Accept& orig) : Message(MSGTYPE_ACCEPT) {
}

Accept::~Accept() {
}

const string Accept::toString() {
    string dump = Message::toString();
    dump += "\n";
    if (!has("GID")) {
        dump += "Missing required tag: GID";
    } else {
        dump += "Accepting game with id: " + get("GID");
    }
    return dump;
}

void Accept::unmarshall(const char* buffer, int len) {
    if (MIN_BODY_LENGTH > len) {
        cerr << "ERROR!!! Received data length incorrect. Received=" << len << ", Min Required=" << MIN_BODY_LENGTH << endl;
        return;
    }
    Message::unmarshall(buffer, len);
}

