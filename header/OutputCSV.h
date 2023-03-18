#pragma once
#include "OutputStrategy.h"

class OutputCSV:public OutputStrategy
{
public:
	char c;

public:
	virtual void Output();

public:
	OutputCSV() {
		c = ' ';
	}
	~OutputCSV() {}
};

