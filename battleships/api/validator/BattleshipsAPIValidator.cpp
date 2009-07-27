/* 
 * File:   main.cpp
 * Author: sanath
 *
 * Created on July 20, 2009, 5:28 PM
 */

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "SocketException.hh"
#include "ServerSocket.hh"
#include "Header.hh"
#include "Message.hh"
#include "Initiate.hh"
#include "Accept.hh"
#include "Reject.hh"
#include "Salvo.hh"
#include "SalvoResponse.hh"

using namespace std;

static ofstream f_status;

Header* processMessageHeader(const Socket& dataSocket) {
    BB_HEADER_T tHeader;
    int headerLen = sizeof (BB_HEADER_T);
    char* hp = (char*) & tHeader;
    int recv = dataSocket.recv(hp, headerLen);
    while (recv < headerLen) {
        f_status << "Have header bytes: " << recv << ", Need " << headerLen << endl;
        int nbr = dataSocket.recv(hp + recv, headerLen - recv);
        if (nbr <= 0) {
            return NULL;
        }
        recv += nbr;
    }
    Header* header = new Header(tHeader);
    return header;
}

void processClientConnection(const Socket& dataSocket) {
    Header* header = processMessageHeader(dataSocket);
    if (NULL == header) {
        return;
    }
    int mt = (int) header->getMessageType();
    if ((mt < 0) || (mt >= MSGTYPE_MAX)) {
        f_status << "Unknown/Unsupported Message Type: <" << mt << ">" << endl;
        return;
    }
    f_status << "Header: Type=<" << MsgTypeDesc[mt] << ">, Length=<" << header->getBodyLength();
    f_status << ">, Source=<" << header->getSourceId() << ">" << endl;
    // TODO: Validate the header. Check the message type and then the length.
    stringstream ss;
    ss << "/var/www/BG/bg_" << header->getSourceId();
    ofstream f_client(ss.str().c_str(), ios::app);
    f_client << "--------------------------------------------------------------------------------" << endl;
    f_client << "Header: Type=<" << MsgTypeDesc[(int) header->getMessageType()] << ">, Length=<" << header->getBodyLength() << ">" << endl;
    char buffer[1024];
    int bodyLen = header->getBodyLength();
    int recv = dataSocket.recv(buffer, bodyLen);
    while (recv < bodyLen) {
        f_client << "Waiting on more body data. Need: " << bodyLen - recv << endl;
        int nbr = dataSocket.recv(buffer + recv, bodyLen - recv);
        if (nbr <= 0) {
            f_client << "Read error.. Terminating connection" << endl;
            return;
        }
        recv += nbr;
    }
    buffer[recv] = 0;
    f_client << "Body: <" << buffer << ">" << endl;
    f_client << "----------------------------------------" << endl;
    Message* msg = NULL;
    switch (header->getMessageType()) {
        case MSGTYPE_INITIATE:
        {
            f_client << "Received INITIATE Message" << endl;
            msg = new Initiate(header, buffer, recv);
            break;
        }
        case MSGTYPE_ACCEPT:
        {
            f_client << "Received ACCEPT Message" << endl;
            msg = new Accept(header, buffer, recv);
            break;
        }
        case MSGTYPE_REJECT:
        {
            f_client << "Received REJECT Message" << endl;
            msg = new Reject(header, buffer, recv);
            break;
        }
        case MSGTYPE_SALVO:
        {
            f_client << "Received SALVO Message" << endl;
            msg = new Salvo(header, buffer, recv);
            break;
        }
        case MSGTYPE_SALVO_RESPONSE:
        {
            f_client << "Received SALVO_RESPONSE Message" << endl;
            msg = new SalvoResponse(header, buffer, recv);
            break;
        }
    }
    if (NULL != msg) {
        f_client << msg->toString() << endl;
        delete msg;
    }
    f_client.close();
}

/*
 *
 */
int main(int argc, char** argv) {
    f_status.open("/var/www/BG/bg_server", ios::app);
    f_status << "Running...." << endl;
    try {
        // Create the socket
        ServerSocket server(30000);
        Socket client;
        while (true) {
            f_status << "Waiting for client connection..." << endl;
            try {
                server.accept(client);
                processClientConnection(client);
            } catch (SocketException& se) {
                f_status << "Socket error: " << se.description() << endl;
            } catch (exception& e) {
                f_status << "Error" << endl;
            }
        }
    } catch (SocketException &e) {
        f_status << "Exception (main):" << e.description() << "\nExiting.\n";
    }
    return (EXIT_SUCCESS);
}
