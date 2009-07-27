/* 
 * File:   main.cpp
 * Author: sanath
 *
 * Created on July 20, 2009, 3:17 PM
 */

#include <stdlib.h>
#include <iostream>
#include <string>
#include "ServerSocket.hh"
#include "SocketException.hh"

using namespace std;

int main(int argc, char* argv[]) {

    cout << "EchoServer is Running...." << endl;
    try {
        // Create the socket
        ServerSocket server(30000);
        while (true) {
            cout << "Waiting for a client connection..." << endl;
            Socket sock;
            server.accept(sock);
            try {
                while (true) {
                    string data;
                    sock >> data;
                    cout << "Received <" << data << ">... echoing back to client." << endl;
                    sock << data;
                }
            } catch (SocketException& e) {
                cout << "Error in data stream:" << e.description() << endl;
                cout << "Terminating current connection." << endl;
            }
        }
    } catch (SocketException& e) {
        cout << "Error creating server or accepting client connection" << e.description() << endl;
        cout << "Terminating the application" << endl;
    }

    return (EXIT_SUCCESS);
}

