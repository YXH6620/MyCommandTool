#pragma once
#include "Command.h"


class insert :public Command
{
private:
	std::string arg;
	std::string arg_subject;
	std::vector<std::string>arg_param;

public:
	virtual void Execute();
	void read(std::string command);
	void write(std::string command);

public:
	insert(std::string userInput) {
		StringSplit(userInput, ' ', arg_param);
		
		this->arg = arg_param.size() < 2 ? "" : arg_param[1];
		this->arg_subject = arg_param.size() < 3 ? "" : arg_param[2];
	}
	
	~insert() {}
};

