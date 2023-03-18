#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

class Command
{
public:
	virtual void Execute()=0;
public:
	void StringSplit(std::string str, const char split, std::vector<std::string>& res);
	bool isCSV(std::string command);
};

