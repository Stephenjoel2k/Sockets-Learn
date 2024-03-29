#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include<netinet/in.h>

int main(){

    //create a socket
    int network_socket;

    //Internet constant IPv4 is AF_INET, TCP is SOCK_STREAM, You would define the protocol if using raw socket
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    //specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;        //IPv4
    server_address.sin_port = htons(9002);      //htons converts it to the port data format
    server_address.sin_addr.s_addr = INADDR_ANY; //connect to IP 0.0.0.0


    //2nd param type cast to right data type, 3rd param is size
    int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    //check if the connect is okay
    if(connection_status == -1) 
    {
        printf("Error making a connection to the remote server");
    }

    // receive data from the server
    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response), 0);

    //print out the server response
    printf("The server sent the data: %s\n", server_response);


    //close the socket
    close(network_socket);

    return 0;



}