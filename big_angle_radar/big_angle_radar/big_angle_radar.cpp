

#include"Data_Transmission.h"
#include <iostream>
//#pragma comment(lib,"sqlite3.lib")
using namespace std;
//using radar_one = big_angle_radar_target_info;
int main()
{
	Data_Transmission instance(5100);
	instance.run();
	return 0;
}

