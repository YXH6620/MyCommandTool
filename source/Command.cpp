#include "Command.h"

void Command::StringSplit(std::string str, const char split, std::vector<std::string>& res)
{
	std::istringstream iss(str);//������
	std::string token;//���ܻ�����
	while (std::getline(iss, token, split)) {
		res.push_back(token);
	}
}

bool Command::isCSV(std::string userInput)
{
	int n = userInput.size();
	if (n <= 3)
		return false;
	if (userInput[n - 3] == 'c' && userInput[n - 2] == 's' && userInput[n - 1] == 'v')
		return true;
	return false;
}


