#pragma once
#include<WinSock2.h>
#include<WS2tcpip.h>
#include"database.h"
#include<assert.h>
#include<iostream>
#include<string>
#pragma comment(lib,"ws2_32.lib")
class Data_Transmission
{
	using radar_data = big_angle_radar_data;
	using radar_one = big_angle_radar_target_info;
public:
	Data_Transmission(short port, std::string address="127.0.0.1");
	bool init_dll();
	void run();
	~Data_Transmission();
private:
	WSADATA wasData;
	SOCKET sock_listen;
	sockaddr_in sockAddr;
	short addr_port;
	SOCKET sock_recv;
	sockaddr_in sockAddr_client;
	radar_one data;
	char buffer[1024];
	database db;
};

