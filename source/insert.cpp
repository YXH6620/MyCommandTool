#include "insert.h"

void insert::Execute()
{
	if (this->arg == "-csv" ) {
		if (!isCSV(this->arg_subject)) {
			std::cout << "this is not .csv file, please re-enter \n";
		}
		else {
			std::cout << "OK!" << std::endl;

			read(this->arg_subject);
		}
	}
	else if (this->arg == "-data") {
		write(this->arg_subject);
	}
	else {
		std::cout << "No such command\n";
	}
}


void insert::read(std::string command)
{
	std::ifstream csv_data(command, std::ios::in);
	std::string line;
	
	if (!csv_data.is_open()) {
		std::cout << "Opening .csv file fail.\n";
		std::exit(1);
	}

	std::istringstream ssin;
	std::vector<std::string>words;
	std::string word;

	//读取标题行
	std::getline(csv_data, line);
	write(line);
	//读取数据
	while (std::getline(csv_data, line)) {
		ssin.clear();
		ssin.str(line);
		words.clear();

		write(line);

		while (std::getline(ssin, word, ',')) {
			words.push_back(word);
			//std::cout << word << " ";
		}
		//std::cout << std::endl;
	}
	csv_data.close();
}

void insert::write(std::string command)
{
	//写文件
	std::ofstream outFile;
	outFile.open("data.csv", std::ios::app);
	outFile << command << std::endl;
	outFile.close();
}


