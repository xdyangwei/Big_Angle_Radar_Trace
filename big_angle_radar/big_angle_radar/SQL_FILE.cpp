#include "pch.h"
#include <fstream>
#include<iostream>
#include "SQL_FILE.h"
using namespace std;
SQL_FILE::SQL_FILE(string path)
{
	read_file(path);
}


SQL_FILE::~SQL_FILE() = default;

void SQL_FILE::read_file(std::string path) {
	ifstream file(path);
	string s; string s1;
	while (getline(file,s1))
	{
		s += s1;
	}
	sql_statement = s;
}

string SQL_FILE::getsql() {
	return sql_statement;
}

void SQL_FILE::write_file(std::string path)
{
	ofstream file(path);
	std::cout << sql_statement.size();
	file.write(sql_statement.c_str(),sql_statement.size());
}
