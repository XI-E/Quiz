# Script to convert questions in a .txt file to a .cpp file where they
# are stored in a struct

ques_cpp = open("ques.cpp", 'w');

ques_cpp.write('#include "quiz.h"\n')
ques_cpp.write('#include <string.h>\n\n')
ques_cpp.write('question questions[3][3][3];\n\n')

for n in xrange(0,3):
	if n == 0:
		ques_txt = open("q_lvl1.txt");
	elif n == 1:
		ques_txt = open("q_lvl2.txt");
	elif n == 2:
		ques_txt = open("q_lvl3.txt");
		
	for i in xrange(0,3):
		for j in xrange(0,3):
			question = ques_txt.readline()
			w = "strcpy(questions[%d][%d][%d].q, %s) ; \n" % (n, i, j, question[0:len(question) - 1])
			ques_cpp.write(w)
			for k in xrange(0, 4):
				option = ques_txt.readline()
				ques_cpp.write('strcpy(questions[%d][%d][%d].options[%d], %s) ; \n' % (n, i, j, k, option[0:len(option) - 1]))
			
			answer = ques_txt.readline()
			ques_cpp.write('questions[%d][%d][%d].correct = %s ; \n\n' % (n, i, j, answer[0:1]))
			blank = ques_txt.readline()
			
	ques_txt.close()
		
		


