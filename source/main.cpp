#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "CommandFactory.h"
#include "OutputContext.h"

std::string getArg0(std::string command);
void show_data();

int main() {

	std::cout << "Command-Line Tool for miHoYo Pipeline TD test~\n";
	std::cout << "Author: YanXi hang from Beijing Jiaotong University\n\n";


	try {
		//每次读取输入
		while (true) {
			std::cout << "MyCmd/cli> ";

			//Input prompt
			std::string userInput;
			std::getline(std::cin, userInput);
			if (userInput.empty() || userInput == " ")continue;

			//对大小写不敏感,全部转为小写
			std::transform(userInput.begin(), userInput.end(), userInput.begin(), tolower);

			if (getArg0(userInput) == "show") {
				show_data();
				continue;
			}

			CommandFactory *cmd_fac = new CommandFactory();
			Command* cmd = cmd_fac->getCommandType(userInput, getArg0(userInput));
			if (cmd)cmd->Execute();
			else std::cout << "No this Command!\n";

		}
	}
	catch (std::exception ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}

std::string getArg0(std::string command) {
	std::string arg0;
	for (char& c : command) {
		if (c == ' ')break;
		arg0 += c;
	}
	return arg0;
}

void show_data()
{
	std::ifstream csv_data("data.csv", std::ios::in);
	std::string line;

	if (!csv_data.is_open()) {
		std::cout << "Opening .csv file fail. Please insert a .csv file or input a csv line! \n";
		//std::exit(1);
	}

	std::istringstream ssin;
	std::string word;

	//读取标题行
	std::getline(csv_data, line);
	//读取数据
	while (std::getline(csv_data, line)) {
		ssin.clear();
		ssin.str(line);

		while (std::getline(ssin, word, ',')) {
			std::cout << word << " ";
		}
		std::cout << std::endl;
	}
	csv_data.close();
}