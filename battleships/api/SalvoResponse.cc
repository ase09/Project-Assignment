/* 
 * File:   SalvoResponse.cc
 * Author: sanath
 * 
 * Created on June 30, 2009, 5:41 AM
 */

#include <stdlib.h>
#include "SalvoResponse.hh"

// The message body would look like "SAS=<0/1>,NOH=<...>,NSS=<...>".
// The minimum body length would thus be 17.
#define MIN_BODY_LENGTH 17

SalvoResponse::SalvoResponse(const string& gid, int sid) : Message(MSGTYPE_SALVO_RESPONSE) {
    add("GID", gid);
    add("SID", sid);
    setShipsAllSunk(false);
    setNumberOfHits(0);
    setNumberOfShipsSunk(0);
}

SalvoResponse::SalvoResponse(Header* header, const char* buffer, int length) : Message(header, buffer, length) {
}

SalvoResponse::SalvoResponse(const SalvoResponse& orig) : Message(MSGTYPE_SALVO_RESPONSE) {
}

SalvoResponse::~SalvoResponse() {
}

const string SalvoResponse::toString() {
    string dump = Message::toString();
    dump += "\n";
    dump += "Received Salvo Response for game with id: <";
    dump += has("GID") ? get("GID") : "ERROR: Missing GID";
    dump += ">\n";
    dump += "Salvo id: <";
    dump += has("SID") ? get("SID") : "ERROR: Missing SID";
    dump += ">\n";
    dump += "All ships sunk? <";
    dump += (getShipsAllSunk() ? "Y" : "N");
    dump += ">\n";
    dump += "Number of hits: <";
    dump += has("NOH") ? get("NOH") : "ERROR: Missing NOH";
    dump += ">\n";
    dump += "Number of ships sunk: <";
    dump += has("NSS") ? get("NSS") : "ERROR: Missing NSS";
    dump += ">\n";
    return dump;
}

void SalvoResponse::setShipsAllSunk(bool value) {
    shipsAllSunk = value;
    add("SAS", getShipsAllSunk() ? 1 : 0);
}

bool SalvoResponse::getShipsAllSunk() {
    return shipsAllSunk;
}

void SalvoResponse::setNumberOfHits(int value) {
    numberOfHits = value;
    add("NOH", value);
}

int SalvoResponse::getNumberOfHits() {
    return numberOfHits;
}

void SalvoResponse::setNumberOfShipsSunk(int value) {
    numberOfShipsSunk = value;
    add("NSS", getNumberOfShipsSunk());
}

int SalvoResponse::getNumberOfShipsSunk() {
    return numberOfShipsSunk;
}

void SalvoResponse::unmarshall(const char* buffer, int len) {
    if (MIN_BODY_LENGTH > len) {
        cerr << "ERROR!!! Received data length incorrect. Received=" << len << ", Min Required=" << MIN_BODY_LENGTH << endl;
        return;
    }
    Message::unmarshall(buffer, len);
    shipsAllSunk = has("SAS") ? atoi(get("SAS").c_str()) : 0;
    numberOfHits = has("NOH") ? atoi(get("NOH").c_str()) : 0;
    numberOfShipsSunk = has("NSS") ? atoi(get("NSS").c_str()) : 0;
}

