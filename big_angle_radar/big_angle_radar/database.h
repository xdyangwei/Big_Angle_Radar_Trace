#pragma once
#include<string>
#include<iostream>
#include"radar_data.h"
#include"SQL_FILE.h"
#include"sqlite/sqlite3.h"
class database
{
	using radar = big_angle_radar_data;
	using radar_one = big_angle_radar_target_info;
	using select_callback = int(*)(void*,//sqlite3_exec function provided its fourth argument
		int,//the number of cloumns in row
		char**,//an array of strings representing fields int the row
		char**// an array of strings representing column names
		);
public:
	database(std::string dbpath);
	void create_table(std::string sqlpath);
	void store(radar r);
	void store_one(radar_one r1);
	void select_data();
	void update_data();
	void delete_data(int id);
	bool getflag();
	~database();
private:
	bool flag;
	select_callback fun1;
	sqlite3* db;
};

