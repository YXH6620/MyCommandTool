#include "OutputCSV.h"

void OutputCSV::Output()
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

		outString += line + '\n';
	}
	csv_data.close();

	//д�ļ�
	outFile.open("result.csv", std::ios::out);
	outFile << outString << std::endl;
	outFile.close();
}
