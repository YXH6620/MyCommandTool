#include "query.h"

void query::Execute()
{
	//读取.csv或.html，并进行数据排序等处理
	read(this->data_file);
	rank_sort(Chinese_rank);
	rank_sort(English_rank);
	rank_sort(Math_rank);
	rank_sort(Total_rank);


	//根据查询参数返回响应结果
	if (this->arg == "-top") {
		if (this->arg_subject == "-chinese") {
			show_top(Chinese_rank,this->arg_subject);
		}
		else if (this->arg_subject == "-english") {
			show_top(English_rank, this->arg_subject);
		}
		else if (this->arg_subject == "-math") {
			show_top(Math_rank, this->arg_subject);
		}
		else if (this->arg_subject == "-total") {
			show_top(Total_rank, this->arg_subject);
		}
	}
	else if (this->arg == "-lowest") {
		if (this->arg_subject == "-chinese") {
			show_lowest(Chinese_rank, this->arg_subject);
		}
		else if (this->arg_subject == "-english") {
			show_lowest(English_rank, this->arg_subject);
		}
		else if (this->arg_subject == "-math") {
			show_lowest(Math_rank, this->arg_subject);
		}
		else if (this->arg_subject == "-total") {
			show_lowest(Total_rank, this->arg_subject);
		}
	}
	else if (this->arg == "-average") {
		if (this->arg_subject == "-chinese") {
			show_avrage(Chinese_rank, this->arg_subject);
		}
		else if (this->arg_subject == "-english") {
			show_avrage(English_rank, this->arg_subject);
		}
		else if (this->arg_subject == "-math") {
			show_avrage(Math_rank, this->arg_subject);
		}
		else if (this->arg_subject == "-total") {
			show_avrage(Total_rank, this->arg_subject);
		}
	}
	else if (this->arg == "-rank") {
		if (this->arg_subject == "-chinese") {
			show_rank(Chinese_rank, this->arg_subject);
		}
		else if (this->arg_subject == "-english") {
			show_rank(English_rank, this->arg_subject);
		}
		else if (this->arg_subject == "-math") {
			show_rank(Math_rank, this->arg_subject);
		}
		else if (this->arg_subject == "-total") {
			show_rank(Total_rank, this->arg_subject);
		}
	}
	else {
		std::cout << "No such command\n";
	}
}

void query::read(std::string command)
{
	std::ifstream csv_data(command, std::ios::in);
	std::string line;

	if (!csv_data.is_open()) {
		std::cout << "Opening .csv file fail. Please insert a .csv file or input a csv line! \n";
		//std::exit(1);
	}

	std::istringstream ssin;
	std::vector<std::string>words;
	std::string word;

	//读取标题行
	std::getline(csv_data, line);
	//读取数据
	while (std::getline(csv_data, line)) {
		ssin.clear();
		ssin.str(line);
		words.clear();

		//write(line);

		while (std::getline(ssin, word, ',')) {
			words.push_back(word);
			//std::cout << word << " ";
		}
		
		int n = words.size();
		std::string name;
		if (n > 0) {
			name = words[0];
		}
		if (n > 1) {
			std::string chinese_score = words[1];
			Chinese_rank.push_back({ name,stoi(chinese_score) });
		}
		if (n > 2) {
			std::string english_score = words[2];
			English_rank.push_back({ name,stoi(english_score) });
		}
		if (n > 3) {
			std::string math_score = words[3];
			Math_rank.push_back({ name,stoi(math_score) });
		}

		int sum = 0;
		for (int i = words.size() - 1; i >= 1; i--) {
			sum += stoi(words[i]);
		}
		Total_rank.push_back({ name,sum });

	}

	csv_data.close();
}

//void query::write(std::string command)
//{
//	//写文件
//	std::ofstream outFile;
//	outFile.open("data.csv", std::ios::app);
//	outFile << command << std::endl;
//	outFile.close();
//}

void query::rank_sort(std::vector<std::pair<std::string, int>> &x)
{
	std::sort(x.begin(), x.end(), [](std::pair<std::string, int>& p1, std::pair<std::string, int>& p2) {
		return p1.second > p2.second;
		});
}

void query::show_top(std::vector<std::pair<std::string, int>>& x, std::string subject)
{
	if (x.size() == 0)return;
	std::cout << subject << " top: " << x[0].second << std::endl;
}

void query::show_lowest(std::vector<std::pair<std::string, int>>& x, std::string subject)
{
	int n = x.size();
	if (n == 0)return;
	std::cout << subject << " lowest: " << x[n - 1].second << std::endl;
}

void query::show_avrage(std::vector<std::pair<std::string, int>>& x, std::string subject)
{
	float sum = 0.0;
	int n = x.size();
	if (n == 0)return;
	for (auto& it : x) {
		sum += it.second;
	}
	std::cout << subject << " average: " << (float)sum / n << std::endl;
}

void query::show_rank(std::vector<std::pair<std::string, int>>& x, std::string subject)
{
	int n = x.size();
	if (n == 0)return;
	std::cout << "**********************************\n";
	std::cout << subject << " rank: \n";
	for (auto& it : x) {
		std::cout << it.first << " " << it.second << std::endl;
	}
}
