#pragma once
#include "Command.h"
#include "OutputContext.h"

class output :public Command
{
private:
	std::string arg_format;
	std::vector<std::string>arg_param;

public:
	virtual void Execute();

public:
	OutputContext* out_cxt;

public:
	output(std::string userInput) {
		Command::StringSplit(userInput, ' ', arg_param);

		this->arg_format = arg_param.size() < 2 ? "" : arg_param[1];
	}
	~output() {}
};

