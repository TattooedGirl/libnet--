// new netserver.h
#ifndef netserver_H
#define netserver_H

//
//      Class for starting a network server: bind a socket, listen on a port
//          handle client connections, etc.
//

//
//  Remember that sockets are stream based... the second half of a message may be delayed!
//

#include "netbase.h"

//
// Class definition
//

class netserver : public netbase {

public:
    netserver(unsigned int max);
    ~netserver();
    sock_t openPort(int16_t port);   //open *port*, return socket descriptor
    void closePort();        //close the server (and server.log)
    int run();         //Check the network: read sockets, handle callbacks

protected:
    bool ready;             //Ready to continue?
    fd_set listenSet;   //set of port listening file descriptors
    int16_t serverPort;   //Listening port number
    sock_t sdListen;       //Listening socket number
    
    int closeSocket(sock_t);   //Overloaded function....
    int buildListenSet();   //Rebuild listenSet
    int checkPort();        //Examine port for connections
    sock_t acceptConnection(); //Handle an incoming connection
    
};

#endif
