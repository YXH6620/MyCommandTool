#pragma once

#include "insert.h"
#include "query.h"
#include "update.h"
#include "output.h"

#include "OutputContext.h"

class CommandFactory
{
private:
	char c;
public:
	Command* getCommandType(std::string userInput,std::string cmd_type) {
		if (userInput.empty())return nullptr;
		if (cmd_type == "insert") {
			return new insert(userInput);
		}
		else if (cmd_type == "query") {
			return new query(userInput);
		}
		else if (cmd_type == "update") {
			return new update(userInput);
		}
		else if (cmd_type == "output") {
			return new output(userInput);
		}
		return nullptr;
	}
public:
	CommandFactory() {
		c = ' ';
	}
	~CommandFactory() {}
};

