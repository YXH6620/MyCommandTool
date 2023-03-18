#pragma once
#include "Command.h"

class query :public Command
{
private:
	std::string arg;//��߷�/��ͷ�/ƽ����
	std::string arg_subject;//����/��ѧ/Ӣ��
	std::string data_file;//�����ļ�
	std::vector<std::string>arg_param;

private:

	//���Ƴɼ�����
	std::vector<std::pair<std::string, int>>Chinese_rank;
	std::vector<std::pair<std::string, int>>English_rank;
	std::vector<std::pair<std::string, int>>Math_rank;
	std::vector<std::pair<std::string, int>>Total_rank;

public:
	virtual void Execute();
	void read(std::string command);
	//void write(std::string command);

public:
	void rank_sort(std::vector<std::pair<std::string, int>> &x);
	void show_top(std::vector<std::pair<std::string, int>>& x,std::string subject);
	void show_lowest(std::vector<std::pair<std::string, int>>& x, std::string subject);
	void show_avrage(std::vector<std::pair<std::string, int>>& x, std::string subject);
	void show_rank(std::vector<std::pair<std::string, int>>& x, std::string subject);

public:
	query(std::string userInput) {
		Command::StringSplit(userInput, ' ', arg_param);

		this->arg = arg_param.size() < 2 ? "" : arg_param[1];
		this->arg_subject = arg_param.size() < 3 ? "" : arg_param[2];
		this->data_file = arg_param.size() < 4 ? "" : arg_param[3];
	}
	~query() {}
};

