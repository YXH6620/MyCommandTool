#pragma once
#include "Command.h"

class update :public Command {
private:
	std::string para_name;
	std::string para_subject;
	std::string para_scoreToUpdate;
	
	std::vector<std::string>arg_param;

public:
	virtual void Execute();

public:
	update(std::string userInput) {
		Command::StringSplit(userInput, ' ', arg_param);

		this->para_name = arg_param.size() < 2 ? "" : arg_param[1];
		this->para_subject = arg_param.size() < 3 ? "" : arg_param[2];
		this->para_scoreToUpdate = arg_param.size() < 4 ? "" : arg_param[3];
	}
	~update() {}
};

