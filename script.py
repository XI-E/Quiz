# Script to convert questions in a .txt file to a .cpp file where they
# are stored in a struct

lvl1_txt = open("q_lvl1.txt", 'r');
lvl1_cpp = open("q_lvl1.cpp", 'w');

lvl1_cpp.write('#include "quiz.h"\n')
lvl1_cpp.write('#include <string.h>\n\n')
lvl1_cpp.write('struct questions[3][3][3];\n\n')

for i in xrange(0,3):
	for j in xrange(0,3):
		question = lvl1_txt.readline()
		w = "strcpy(questions[0][%d][%d].q, %s) ; \n" % (i, j, question[0:len(question) - 1])
		lvl1_cpp.write(w)
		for k in xrange(0, 4):
			option = lvl1_txt.readline()
			lvl1_cpp.write('strcpy(questions[0][%d][%d].options[%d], %s) ; \n' % (i, j, k, option[0:len(option) - 1]))
			
		answer = lvl1_txt.readline()
		lvl1_cpp.write('questions[0][%d][%d].correct = %s ; \n\n' % (i, j, answer[0:1]))
		blank = lvl1_txt.readline()
		
		

lvl1_txt.close();
