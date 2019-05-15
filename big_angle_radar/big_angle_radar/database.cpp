#include "database.h"

database::database(std::string filename)
{
	auto res = sqlite3_open(filename.c_str(), &db);
	if (!res)
		flag = true;
	else
		flag = false;
}

void database::create_table(std::string sqlpath)
{
	SQL_FILE s(sqlpath);
	std::string msg = "create table failed";
	auto pmsg = const_cast<char*>(msg.c_str());
	auto res = sqlite3_exec(db, s.getsql().c_str(), nullptr, nullptr, &pmsg);
	if (res == SQLITE_OK)
		flag = true;
	else
		flag = false;
}

void database::store(radar r)
{
	auto data = r.targets;
	for (int i = 0; i < 59; i++) {
		store_one(data[i]);
		if (flag == false)
			break;
	}
}

void database::store_one(radar_one r1)
{
	char buffer[1024];
	char* err = 0;
	sprintf_s(buffer,"Insert into radar_data(targetid,x,y,speed,acc) values (%d,%f,%f,%f,%f)",r1.targetid,r1.x,r1.y,r1.v,r1.acc);
	auto res = sqlite3_exec(db, buffer, nullptr, nullptr, &err);
	if (res != SQLITE_OK)
		flag = false;
}


bool database::getflag()
{
	return flag;
}

database::~database() {
	sqlite3_close(db);
}
