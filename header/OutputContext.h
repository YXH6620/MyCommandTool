#pragma once

#include "OutputCSV.h"
#include "OutputHTML.h"
#include "OutputTXT.h"


class OutputContext
{
private:
	char c;
public:
	OutputStrategy* getOutputFormat( std::string out_format) {
		if (out_format.empty())return nullptr;
		if (out_format == "-csv") {
			return new OutputCSV();
		}
		else if (out_format == "-html") {
			return new OutputHTML();
		}
		else if (out_format == "-txt") {
			return new OutputTXT();
		}
		return nullptr;
	}

public:
	OutputContext() {
		c = ' ';
	}
	~OutputContext() {}
};

