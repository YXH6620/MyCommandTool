#pragma once
#include <string>
#include <vector>

#include "Command.h"

class OutputStrategy
{
	
public:
	virtual void Output() = 0;

public:
	Command* cmd;
};

