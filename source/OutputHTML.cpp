#include "OutputHTML.h"

void OutputHTML::Output()
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

		outString += line + "<br>";
	}
	csv_data.close();

	//写文件
	outFile.open("result.html", std::ios::out);

	outFile << "<!DOCTYPE html>";
	outFile << "<html>";
	outFile << "	<head>";
	outFile << "		<meta charset = \"utf - 8\">";
	outFile << "		<title> MyCommand-HTML </title>";
	outFile << "	</head>";

	outFile << "	<body>";
	outFile << "		<h1>成绩查询命令工具</h1>";

	outFile << outString << std::endl;

	outFile << "	</body>";
	outFile << "</html>";

	outFile.close();
}
