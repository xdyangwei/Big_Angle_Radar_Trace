

#include "database.h"
#include <iostream>
//#pragma comment(lib,"sqlite3.lib")
using namespace std;
using radar_one = big_angle_radar_target_info;
int main()
{
	database db("data.db");
	db.create_table("sql/create_table.sql");
	radar_one r1;
	r1.targetid = 1;
	r1.x = 5;
	r1.y = 6;
	r1.v = 10.0;
	r1.acc = 5.0;
	db.store_one(r1);
	return 0;
}

