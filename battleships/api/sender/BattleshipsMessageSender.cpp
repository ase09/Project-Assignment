/* 
 * File:   BattleshipsMessageSender.cpp
 * Author: sanath
 *
 * Created on July 22, 2009, 5:40 PM
 */

#include <stdlib.h>
#include <iostream>
#include <string>
#include <sys/socket.h>

#include <log4cplus/configurator.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/helpers/loglog.h>

#include "SocketException.hh"
#include "ClientSocket.hh"
#include "Initiate.hh"
#include "Accept.hh"
#include "Reject.hh"
#include "Salvo.hh"
#include "SalvoResponse.hh"

using namespace log4cplus;
static Logger logger = Logger::getInstance("Battleships.MessageSender");

int sendMessage() {

    cout << "Enter Message Type (0=Initiate, 1=Accept, 2=Reject, 3=Salvo, 4=SalvoResponse):";
    string type;
    cin >> type;
    int mt = atoi(type.c_str());
    Message* msg = NULL;

    switch (mt) {
        case MSGTYPE_INITIATE:
            msg = new Initiate("SAF1");
            break;
        case MSGTYPE_ACCEPT:
            msg = new Accept("SAF1");
            break;
        case MSGTYPE_REJECT:
            msg = new Reject("SAF1", 6);
            break;
        case MSGTYPE_SALVO:
            msg = new Salvo("SAF1", 14, "A1", "C6", "E3");
            break;
        case MSGTYPE_SALVO_RESPONSE:
            msg = new SalvoResponse("SAF1", 14);
            ((SalvoResponse*) msg)->setNumberOfHits(2);
            ((SalvoResponse*) msg)->setNumberOfShipsSunk(1);
            break;
        default:
            return -1;
    }

    try {
        if (NULL != msg) {
            //string host = "192.168.19.39";
            string host = "localhost";
            int port = 30000;
            ClientSocket socket(host, port);
            LOG4CPLUS_INFO(logger, "Connected to: " << host << ":" << port);
            LOG4CPLUS_INFO(logger, "Sending: " << msg->toString());
            msg->send(socket);
        }
    } catch (SocketException& se) {
        LOG4CPLUS_ERROR(logger, "Socket Error: " << se.description());
    }

    return 0;
}

int main(int argc, char* argv[]) {

    //Add File appender
    helpers::LogLog::getLogLog()->setInternalDebugging(true);
    //SharedAppenderPtr append_1(new RollingFileAppender("bb_sender.log", 1 * 1024 * 1024, 5));
    SharedAppenderPtr append_1(new ConsoleAppender(new TTCCLayout()));
    append_1->setName("First");
    append_1->setLayout(std::auto_ptr<Layout > (new TTCCLayout()));
    Logger::getRoot().addAppender(append_1);
    logger.setLogLevel(TRACE_LOG_LEVEL);

    LOG4CPLUS_INFO(logger, "Running...");

    while (sendMessage() >= 0) {
    }
    return (EXIT_SUCCESS);
}
