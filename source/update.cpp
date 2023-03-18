#include "update.h"

void update::Execute()
{
	std::ifstream csv_data("data.csv", std::ios::in);
	std::string line;

	if (!csv_data.is_open()) {
		std::cout << "Opening .csv file fail. Please insert a .csv file or input a csv line! \n";
		//std::exit(1);
	}

	std::istringstream ssin;
	std::vector<std::string>words;
	std::string word;
	
	bool isFind = false;
	std::string outString="����,����,Ӣ��,��ѧ\n";

	//��ȡ������
	std::getline(csv_data, line);
	//��ȡ����
	while (std::getline(csv_data, line)) {
		ssin.clear();
		ssin.str(line);
		words.clear();

		while (std::getline(ssin, word, ',')) {
			words.push_back(word);
		}
		if (!words.empty() && words[0] == this->para_name) {
			isFind = true;

			if (this->para_subject == "chinese") {
				words[1] = this->para_scoreToUpdate;
			}
			else if (this->para_subject == "english") {
				words[2] = this->para_scoreToUpdate;
			}
			else if (this->para_subject == "math") {
				words[3] = this->para_scoreToUpdate;
			}

			line.clear();
			for (auto& x : words) {
				line += x + ',';
			}
			line.pop_back();
			std::cout << "Update success! Now this line is: \n";
			std::cout << line << std::endl;
		}

		outString += line + '\n';
	}
	csv_data.close();

	if (!isFind) {
		std::cout << "No this name! Please input [show] command to list which student's score to change.\n";
	}

	//д�ļ�
	std::ofstream outFile;
	outFile.open("data.csv", std::ios::out);
	outFile << outString ;
	outFile.close();
}
