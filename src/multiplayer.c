//
// Created by dell-iman on 1/6/2016.
//

#include "multiplayer.h"

#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 1373

static int socket_fd;

int cell_new()
{
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;

	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(SERVER_PORT);
	inet_aton(SERVER_ADDR, &client_addr.sin_addr);

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	if (!connect(socket_fd, (struct sockaddr *) &client_addr,
		sizeof(client_addr))) {
		return 0;
	}

	printf("Starting server ....\n");

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(SERVER_PORT);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket_fd == -1)
		perror("socket()");

	if (bind(server_socket_fd, (struct sockaddr *) &server_addr,
		sizeof(server_addr)) == -1)
		perror("bind()");

	if (listen(server_socket_fd, 10) == -1)
		perror("listen()");

	socket_fd = accept(server_socket_fd, NULL, NULL);

	return 0;
}


struct cell_move_data cell_move(struct cell_move_data your_move)
{
	struct cell_move_data result;
	return result;
}
