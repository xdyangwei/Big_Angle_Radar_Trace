

#include"Data_Transmission.h"
#include"Data_Client.h"
#include <iostream>
//#pragma comment(lib,"sqlite3.lib")
using namespace std;
//using radar_one = big_angle_radar_target_info;
int main()
{
	Data_Transmission instance(5100,"0.0.0.0");
	Data_Client client("0.0.0.0",5100);
	client.send_data();
	instance.run();
	return 0;
}

