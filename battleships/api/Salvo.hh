/* 
 * File:   BattleshipsSalvoMessage.h
 * Author: sanath
 *
 * Created on June 29, 2009, 10:22 PM
 */

#ifndef _SALVO_H
#define	_SALVO_H

#include <string>
#include "Message.hh"

using namespace std;

class Salvo : public Message {
public:
    Salvo();
    Salvo(Header* header, const char* buffer, int length);
    Salvo(const string& gid, int sid, const char* t1, const char* t2, const char* t3);
    Salvo(const Salvo& orig);
    virtual ~Salvo();
    const string toString();
    void unmarshall(const char* buffer, int len);
    int getSalvoSize();
    const string& getTarget1() { get("T1"); }
    const string& getTarget2() { get("T2"); }
    const string& getTarget3() { get("T3"); }
private:
};

#endif	/* _SALVO_H */

