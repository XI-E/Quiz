#ifndef QUIZ_H
#define QUIZ

struct question
{
	char q[200];
	char options[4][100];
	int correct;
};

extern question questions[3][3][3];

void init();

#endif //QUIZ_H
