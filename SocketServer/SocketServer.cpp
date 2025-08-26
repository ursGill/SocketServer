// SocketServer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<winsock.h>
using namespace std;
#define PORT 9909

struct sockaddr_in srv;
fd_set fr,fw, fe;
int main()
{
    int nRet = 0;
    // Initialize the WSA variables
    WSADATA ws;
    if (WSAStartup(MAKEWORD(2, 2), &ws) < 0)
    {
        cout << endl << "WSA Failed to initialize";
        exit(EXIT_FAILURE);
    }
    else {
        cout << endl << "WSA intialized Successfully";
    
    }
    //Initialize the socket
    int nSocket = socket(AF_INET,SOCK_STREAM, IPPROTO_TCP);
    if(nSocket < 0) {
        cout << endl << "The socket not opened";
    }
    else {
        cout << endl << "The socket opened successfully";
    }

    // Initilize the environment for sockaddr structure
    srv.sin_family = AF_INET;
    srv.sin_port = htons(PORT);
   // srv.sin_addr.s_addr = inet_addr("127.0.0.1");
    srv.sin_addr.s_addr = INADDR_ANY;
    memset(&(srv.sin_zero), 0, 8);

    // Bind the socket to the local port
    nRet = bind(nSocket, (sockaddr*)&srv, sizeof(sockaddr));
    if (nRet < 0) {
        cout << endl << "Fail to bind to local port";
        exit(EXIT_FAILURE);
    }
    else {
        cout << endl << "Successfully bind to local port";
    }

    // Listen the request from client (queues the requests)
    nRet = listen(nSocket, 5);
    if (nRet < 0) {
        cout << endl << "Fail to start listen to local port";
        exit(EXIT_FAILURE);
    }
    else {
        cout << endl << "Started listening to local port";
    }

    int n = 100;
    for (int nIndex = 0; nIndex < 65; nIndex++) {
        FD_SET(n, &fr);
        n++;
    }

    cout << endl << fr.fd_count << endl;


    for (int nIndex = 0; nIndex < 65; nIndex++)
    {
        cout << fr.fd_array[nIndex];
    }
    //keep waiting for new requests and proceed as per the request
    
}



