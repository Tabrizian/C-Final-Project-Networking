/*
 * In The Name Of God
 * ========================================
 * [] File Name : multiplayer.c
 *
 * [] Creation Date : 19-01-2016
 *
 * [] Created By : Iman Tabrizian (tabrizian@outlook.com)
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani and Iman Tabrizian.
*/
#include "multiplayer.h"

#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 1373

static int socket_fd;

struct cell_position cell_new(struct cell_position your_initial_position)
{
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;

	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(SERVER_PORT);
	inet_aton(SERVER_ADDR, &client_addr.sin_addr);

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	if (!connect(socket_fd, (struct sockaddr *) &client_addr,
		sizeof(client_addr))) {

        // Solving the problem of initial location....
        struct cell_position result;

        FILE *sk = fdopen(socket_fd, "w");
        fprintf(sk, "%d %d\n", your_initial_position.x, your_initial_position.y);
        fflush(sk);

        sk = fdopen(socket_fd, "r");
        fscanf(sk, "%d %d", &result.x, &result.y);

        return result;
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

    // Solving the problem of initial location....
    struct cell_position result;

    FILE *sk = fdopen(socket_fd, "w");
    fprintf(sk, "%d %d\n", your_initial_position.x, your_initial_position.y);
    fflush(sk);

    sk = fdopen(socket_fd, "r");
    fscanf(sk, "%d %d", &result.x, &result.y);

    return result;


}


struct cell_move_data cell_move(struct cell_move_data your_move)
{
	FILE *sk = fdopen(socket_fd, "w");
	fprintf(sk, "%d %d\n", your_move.cell_id, your_move.move_direction);
	fflush(sk);

	sk = fdopen(socket_fd, "r");
	struct cell_move_data result;
	fscanf(sk, "%d %d", &result.cell_id, &result.move_direction);
	return result;
}
