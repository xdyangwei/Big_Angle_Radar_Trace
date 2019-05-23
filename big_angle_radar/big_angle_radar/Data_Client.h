#pragma once
#include<WinSock2.h>
#include"radar_data.h"
#include<assert.h>
#include<string>
#include<iostream>
#pragma comment(lib,"ws2_32.lib")
class Data_Client
{
	using radar_one = big_angle_radar_target_info;
public:
	Data_Client(std::string ipaddr,short port);
	bool init_dll();
	void send_data();
	~Data_Client();
private:
	SOCKET sock;
	sockaddr_in sockAddr;
	radar_one data;
	WSADATA wasData;
	std::string addr_ip;
	short addr_port;
	char buffer[1024];
	sockaddr_in sock_server;
};

