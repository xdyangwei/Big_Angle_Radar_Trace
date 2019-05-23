#include "Data_Client.h"




Data_Client::Data_Client(std::string ipaddr, short port):
	addr_ip(ipaddr),addr_port(port)
{
	assert(init_dll());
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	sockAddr.sin_addr.S_un.S_addr = inet_addr(addr_ip.c_str());
	sockAddr.sin_port = htons(addr_port);
	sockAddr.sin_family = AF_INET;
	std::cout << inet_ntoa(sockAddr.sin_addr) << " " << ntohs(sockAddr.sin_port) << std::endl;
	connect(sock,(SOCKADDR*)&sockAddr,sizeof(sockAddr));
	int len = sizeof(sock_server);
	getpeername(sock, (SOCKADDR*)&sock_server, &len);
	std::cout << inet_ntoa(sock_server.sin_addr) << " " << ntohs(sock_server.sin_port) << std::endl;
}

bool Data_Client::init_dll()
{
	if (WSAStartup(MAKEWORD(2, 2), &wasData) == 0)
		return true;
	else
		return false;
}

void Data_Client::send_data()
{
	data.targetid = 1; data.x = 6; data.y = 8; data.v = 100; data.acc = 50;
	memset(buffer, 0, sizeof(buffer));
	memcpy(buffer, &data, sizeof(buffer));
	send(sock,buffer,sizeof(buffer),0);
}

Data_Client::~Data_Client()
{
	closesocket(sock);
	WSACleanup();
}
