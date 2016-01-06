//
// Created by dell-iman on 1/6/2016.
//

#include "multiplayer.h"

#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>

#define SERVER_ADDR 0x100000FE
#define SERVER_PORT 1373

static int socket_fd;

int cell_new()
{
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(SERVER_PORT);
	client_addr.sin_addr.s_addr = htonl(SERVER_ADDR);
	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (!connect(socket_fd, (struct sockaddr *) &client_addr,
		sizeof(client_addr))) {
		printf("Harfe kheili khoooob");
		return 0;
	}
	printf("na omidi ... :(\n");

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(SERVER_PORT);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket_fd == -1)
		perror("Foshe zesht");
	if (bind(server_socket_fd, (struct sockaddr *) &server_addr,
		sizeof(server_addr)) == -1)
		perror("Foshe bad");
	if (listen(server_socket_fd, 10) == -1)
		perror("Foshe kheili bad");
	socket_fd = accept(server_socket_fd, NULL, NULL);
	printf("Harfe khoooob");
	return 0;
}


struct cell_move_data cell_move(struct cell_move_data your_move)
{
	struct cell_move_data result;
	return result;
}
