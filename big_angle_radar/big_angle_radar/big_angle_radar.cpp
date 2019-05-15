#include "pch.h"
#include "sqlite/sqlite3.h"
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
		const char* sql= "CREATE TABLE COMPANY("  \
			"ID INT PRIMARY KEY     NOT NULL," \
			"NAME           TEXT    NOT NULL," \
			"AGE            INT     NOT NULL," \
			"ADDRESS        CHAR(50)," \
			"SALARY         REAL );";

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

