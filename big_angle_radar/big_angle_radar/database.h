#pragma once
#include<string>
#include"radar_data.h"
#include"SQL_FILE.h"
#include"sqlite/sqlite3.h"
class database
{
	using radar = big_angle_radar_data;
	using radar_one = big_angle_radar_target_info;
public:
	database(std::string dbpath);
	void create_table(std::string sqlpath);
	void store(radar r);
	void store_one(radar_one r1);
	bool getflag();
	~database();
private:
	bool flag;
	sqlite3* db;
};

