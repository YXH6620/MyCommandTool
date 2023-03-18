#pragma once
#include "OutputStrategy.h"

class OutputTXT:public OutputStrategy
{
public:
	char c;

public:
	virtual void Output();

public:
	OutputTXT() {
		c = ' ';
	}
	~OutputTXT() {}
};

