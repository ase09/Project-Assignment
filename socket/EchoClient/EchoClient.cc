/*
 * File:   main.cc
 * Author: sanath
 *
 * Created on July 01, 2009, 3:21 PM
 */

#include <stdlib.h>

#include <iostream>
#include <string>
#include "SocketException.hh"
#include "ClientSocket.hh"

int main(int argc, char* argv[]) {
    try {
        ClientSocket sock("localhost", 30000);
        string message, reply;
        while (true) {
            cout << "Type message to send:" << endl;
            cin >> message;
            sock << message;
            sock >> reply;
            cout << "Received: <" << reply << ">" << endl;
        }
    } catch (SocketException& e) {
        cout << "Exception was caught:" << e.description() << endl;
        cout << "Terminating the application." << endl;
    }
    return (EXIT_SUCCESS);
}
