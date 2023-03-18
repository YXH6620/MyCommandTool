#include "OutputHTML.h"

void OutputHTML::Output()
{
	//���ļ���Ĭ��csv�ļ�
	std::ifstream csv_data("data.csv", std::ios::in);

	if (!csv_data.is_open()) {
		std::cout << "Opening data.csv file fail.\n";
		std::exit(1);
	}

	std::string line;
	std::string outString;

	//д�ļ�
	std::ofstream outFile;		

	//��ȡ����
	while (std::getline(csv_data, line)) {

		outString += line + "<br>";
	}
	csv_data.close();

	//д�ļ�
	outFile.open("result.html", std::ios::out);

	outFile << "<!DOCTYPE html>";
	outFile << "<html>";
	outFile << "	<head>";
	outFile << "		<meta charset = \"utf - 8\">";
	outFile << "		<title> MyCommand-HTML </title>";
	outFile << "	</head>";

	outFile << "	<body>";
	outFile << "		<h1>�ɼ���ѯ�����</h1>";

	outFile << outString << std::endl;

	outFile << "	</body>";
	outFile << "</html>";

	outFile.close();
}
