/* 
 * File:   BattleshipsSalvoResponseMessage.h
 * Author: sanath
 *
 * Created on June 30, 2009, 5:41 AM
 */

#ifndef _SALVORESPONSE_H
#define	_SALVORESPONSE_H

#include "Message.hh"

class SalvoResponse : public Message {
public:
    SalvoResponse(const string& gid, int sid);
    SalvoResponse(Header* header, const char* buffer, int length);
    SalvoResponse(const SalvoResponse& orig);
    virtual ~SalvoResponse();
    const string toString();
    void unmarshall(const char* buffer, int len);
    void setShipsAllSunk(bool value);
    bool getShipsAllSunk();
    void setNumberOfHits(int value);
    int getNumberOfHits();
    void setNumberOfShipsSunk(int value);
    int getNumberOfShipsSunk();
private:
    bool shipsAllSunk;
    int numberOfHits;
    int numberOfShipsSunk;
};

#endif	/* _SALVORESPONSE_H */

