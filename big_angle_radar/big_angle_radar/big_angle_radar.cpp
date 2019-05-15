#include "pch.h"
#include "sqlite/sqlite3.h"
#include "SQL_FILE.h"
#include <iostream>
#pragma comment(lib,"sqlite3.lib")
using namespace std;
int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	return 0;
}
int main()
{
	sqlite3 *db;
	int rc = 0;
	rc = sqlite3_open("data.db", &db);
	if (rc)
		cout << "connection failed!";
	else {
		cout << "connection success";
		char* msg = nullptr;
		SQL_FILE s1("sql/create_table.sql");
		const char* sql = s1.getsql().c_str();
		auto x = s1.getsql();
		cout << x << endl;
		rc = sqlite3_exec(db, sql, callback, nullptr, &msg);
		if (rc == 0)
			cout << "yes" << endl;
		else {
			cout << "No" << endl;
		}
		sqlite3_close(db);
	}
	return 0;
}

