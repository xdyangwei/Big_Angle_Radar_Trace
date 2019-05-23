#include "Data_Transmission.h"


Data_Transmission::Data_Transmission(short port, std::string address):
	addr_port(port),db(database("data.db"))
{
	assert(init_dll());
	sock_listen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	memset(&sockAddr, 0, sizeof(sockAddr));
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_port = htons(port);
	sockAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	bind(sock_listen, (SOCKADDR*)&sockAddr, sizeof(sockAddr));
	listen(sock_listen, 5);
	std::cout << "The server is listening connection from " <<inet_ntoa((sockAddr.sin_addr)) << " at port " << ntohs(sockAddr.sin_port) << std::endl;
}

bool Data_Transmission::init_dll()
{
	if (WSAStartup(MAKEWORD(2,2),&wasData) == 0)
		return true;
	else
		return false;
}

void Data_Transmission::run()
{
	int sock_client_size = sizeof(sockAddr_client);
	sock_recv=accept(sock_listen, (SOCKADDR*)&sockAddr_client, &sock_client_size);
	std::cout << "connection from " << inet_ntoa(sockAddr_client.sin_addr) << " at port " << ntohs(sockAddr_client.sin_port) << std::endl;
	memset(buffer, 0, sizeof(buffer));
	recv(sock_recv,buffer,sizeof(buffer),0);
	memcpy(&data,buffer,sizeof(buffer));
	std::cout <<"targetid:"<<data.targetid<<" x:" << data.x << " y:" << data.y << " speed:" << data.v << " acc:" << data.acc << std::endl;
	//db = database("data.db");
	db.store_one(data);
}

Data_Transmission::~Data_Transmission()
{
	closesocket(sock_listen);
	closesocket(sock_recv);
	WSACleanup();
}
