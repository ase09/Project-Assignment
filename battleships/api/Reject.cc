/* 
 * File:   Reject.cc
 * Author: sanath
 * 
 * Created on July 23, 2009, 5:55 AM
 */

#include "Reject.hh"

// The message body would look like "GID=<GameId>,RC=<RejectCode>".
// The minimum body length would thus be 5.
#define MIN_BODY_LENGTH 10

Reject::Reject(const string& gid, int rc) : Message(MSGTYPE_REJECT) {
    add("GID", gid);
    add("RC", rc);
}

Reject::Reject(Header* header, const char* buffer, int length) : Message(header, buffer, length) {
}

Reject::Reject(const Reject& orig) : Message(MSGTYPE_REJECT) {
}

Reject::~Reject() {
}

const string Reject::toString() {
    string dump = Message::toString();
    dump += "\n";
    if ((!has("GID")) || (!has("RC"))) {
        dump += "Missing required tag(s): GID/RC";
    } else {
        dump += "Rejecting game with id: " + get("GID");
        dump += "\n";
        dump += "Error code is: " + get("RC");
    }
    return dump;
}

void Reject::unmarshall(const char* buffer, int len) {
    if (MIN_BODY_LENGTH > len) {
        cerr << "ERROR!!! Received data length incorrect. Received=" << len << ", Min Required=" << MIN_BODY_LENGTH << endl;
        return;
    }
    Message::unmarshall(buffer, len);
}

