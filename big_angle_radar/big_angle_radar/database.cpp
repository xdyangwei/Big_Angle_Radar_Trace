#include "database.h"

database::database(std::string filename)
{
	auto res = sqlite3_open(filename.c_str(), &db);
	if (!res)
		flag = true;
	else
		flag = false;
	auto x = [](void *data, int argc, char **argv, char **azColName)->auto {
		for (int i = 1; i < argc; i++) {
			std::cout << azColName[i] << "=" << (argv[i] ? argv[i] : "error") << " ";
		}
		std::cout << std::endl;
		return 0;
	};
	fun1 = x;
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
	std::cout << r1.targetid << std::endl;
	sprintf_s(buffer,"Insert into radar_data(targetid,x,y,speed,acc) values (%f,%f,%f,%f,%f)",r1.targetid,r1.x,r1.y,r1.v,r1.acc);
	std::cout << buffer << std::endl;
	auto res = sqlite3_exec(db, buffer, nullptr, nullptr, &err);
	if (res != SQLITE_OK)
		flag = false;
}

void database::select_data()
{
	const char* sql = "select * from radar_data";
	auto x=sqlite3_exec(db,sql,fun1,nullptr,nullptr);
	if (x == 0)
		flag = true;
	else
		flag = false;
}

void database::update_data()
{
	const char* sql = "UPDATE radar_data set targetid = 2 where ID=1; " \
		"SELECT * from radar_data";
	auto res = sqlite3_exec(db, sql, nullptr, nullptr, nullptr);
	if (res == 0)
		flag = true;
	else
		flag = false;
}

void database::delete_data(int id)
{
	char buffer[1024];
	sprintf_s(buffer, "delete from radar_data where targetid=%d", id);
	auto res = sqlite3_exec(db, buffer, nullptr, nullptr, nullptr);
	if (res == 0)
		flag = true;
	else
		flag = false;
}


bool database::getflag()
{
	return flag;
}

database::~database() {
	sqlite3_close(db);
}
