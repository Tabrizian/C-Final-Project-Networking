# good
## Introduction
Networking phase of Final Project of C Introduction to programming course.
## C Socket Programming in MinGW
For using MinGW in order to socket programming you can use almost all of
BSD socket functions in your program and at the end you must add thses
lines of code in order to load winsock dll.
```c
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
```
and use following command for compiling.
```sh
gcc main.c  -lws2_32
```
