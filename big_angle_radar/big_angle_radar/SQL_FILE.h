#pragma once
#include<string>
class SQL_FILE
{
public:
	SQL_FILE(std::string path);
	~SQL_FILE();
	void read_file(std::string path);
	std::string getsql();
	void write_file(std::string path);
private:
	std::string sql_statement;
};

