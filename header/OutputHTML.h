#pragma once
#include "OutputStrategy.h"

class OutputHTML:public OutputStrategy
{
public:
	char c;

public:
	virtual void Output();

public:
	OutputHTML() {
		c = ' ';
	}
	~OutputHTML() {}
};

