#include "OutputCSV.h"

void OutputCSV::Output()
{
	//读文件：默认csv文件
	std::ifstream csv_data("data.csv", std::ios::in);
	
	if (!csv_data.is_open()) {
		std::cout << "Opening data.csv file fail.\n";
		std::exit(1);
	}

	std::string line;
	std::string outString;

	//写文件
	std::ofstream outFile;

	//读取数据
	while (std::getline(csv_data, line)) {

		outString += line + '\n';
	}
	csv_data.close();

	//写文件
	outFile.open("result.csv", std::ios::out);
	outFile << outString << std::endl;
	outFile.close();
}
