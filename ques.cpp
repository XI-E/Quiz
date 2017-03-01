#include "quiz.hpp"

int num_subs;
sub subs[SUB_MAX];

void init_ques(int lvl, int sub, int q_num, question& ques)
{
	ifstream subfile(subs[sub].fname);
	
	//gotoline
	int curr_line = 1; subfile.seekg(ios::beg);
	int desired_line = 1 + 1; int lines_per_q = 7;
	for(int i = 0; i < lvl; i++)
	{
		desired_line += lines_per_q * subs[sub].q_per_level[i]; //Navigating to beginning of the questions of level lvl
	}
	desired_line += (q_num) * lines_per_q; //Navigating to that question
	
	char line[350];
	while(desired_line > curr_line)
	{
		subfile.getline(line, 350);
		curr_line++;
	}
	// end of gotoline
	
	subfile.getline(ques.q, 200);
	for(i = 0; i < 4; i++)
	{
		subfile.getline(ques.options[i], 200);
	}
	subfile >> ques.correct;
	ques.correct--; //Making it zero indexed
	subfile.ignore(100, '\n');
}

void init_qinfo()
{
	ifstream qinfo("q_info.txt");
	qinfo >> num_subs;
	qinfo.ignore(100, '\n');
	for(int i = 0; i < num_subs; i++)
	{
		qinfo.getline(subs[i].fname, 50);
		qinfo.getline(subs[i].sub_name, 75);
		qinfo.getline(subs[i].short_name, 50);
		
		ifstream subfile(subs[i].fname);
		for(int j = 0; j < 3; j++)
		{
			subfile >> subs[i].q_per_level[j];
		}
	}
}
