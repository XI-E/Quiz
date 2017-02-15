/* Generated from script.py */ 

#include "quiz.h"
#include <string.h>

question questions[3][3][3];

void init_ques()
{

strcpy(questions[0][0][0].q, "Select the INCORRECT keyword in C++") ; 
strcpy(questions[0][0][0].options[0], "asm") ; 
strcpy(questions[0][0][0].options[1], "virtual") ; 
strcpy(questions[0][0][0].options[2], "statics") ; 
strcpy(questions[0][0][0].options[3], "float") ; 
questions[0][0][0].correct = 3 ; 

strcpy(questions[0][0][1].q, "String literal \"abc\" will be represented in the memory as _____") ; 
strcpy(questions[0][0][1].options[0], "abc\\0") ; 
strcpy(questions[0][0][1].options[1], "abc/0") ; 
strcpy(questions[0][0][1].options[2], "abc|0") ; 
strcpy(questions[0][0][1].options[3], "abc_0") ; 
questions[0][0][1].correct = 1 ; 

strcpy(questions[0][0][2].q, "Which of the following header files contains the exit () function to terminate the current program in C++?") ; 
strcpy(questions[0][0][2].options[0], "<string.h>") ; 
strcpy(questions[0][0][2].options[1], "<process.h>") ; 
strcpy(questions[0][0][2].options[2], "<iomanip.h>") ; 
strcpy(questions[0][0][2].options[3], "<ctype.h>") ; 
questions[0][0][2].correct = 2 ; 

strcpy(questions[0][1][0].q, "Entomology is the science that studies ______") ; 
strcpy(questions[0][1][0].options[0], "Behavior of human beings") ; 
strcpy(questions[0][1][0].options[1], "Insects") ; 
strcpy(questions[0][1][0].options[2], "The origin and history of technical and scientific terms") ; 
strcpy(questions[0][1][0].options[3], "The formation of rocks") ; 
questions[0][1][0].correct = 2 ; 

strcpy(questions[0][1][1].q, "Hitler party which came into power in 1933 is known as") ; 
strcpy(questions[0][1][1].options[0], "Labour Party") ; 
strcpy(questions[0][1][1].options[1], "Nazi Party") ; 
strcpy(questions[0][1][1].options[2], "Ku-Klux-Klan") ; 
strcpy(questions[0][1][1].options[3], "Democratic Party") ; 
questions[0][1][1].correct = 2 ; 

strcpy(questions[0][1][2].q, "The ozone layer restricts") ; 
strcpy(questions[0][1][2].options[0], "Visible light") ; 
strcpy(questions[0][1][2].options[1], "Infrared radiation") ; 
strcpy(questions[0][1][2].options[2], "X-rays and gamma rays") ; 
strcpy(questions[0][1][2].options[3], "Ultraviolet radiation") ; 
questions[0][1][2].correct = 4 ; 

strcpy(questions[0][2][0].q, "Find the correct spelling") ; 
strcpy(questions[0][2][0].options[0], "Treachrous") ; 
strcpy(questions[0][2][0].options[1], "Trecherous") ; 
strcpy(questions[0][2][0].options[2], "Trechearous") ; 
strcpy(questions[0][2][0].options[3], "Treacherous") ; 
questions[0][2][0].correct = 4 ; 

strcpy(questions[0][2][1].q, "Find the synonym of Frugal") ; 
strcpy(questions[0][2][1].options[0], "invention") ; 
strcpy(questions[0][2][1].options[1], "economical") ; 
strcpy(questions[0][2][1].options[2], "to whisper") ; 
strcpy(questions[0][2][1].options[3], "explore") ; 
questions[0][2][1].correct = 2 ; 

strcpy(questions[0][2][2].q, "Complete the sentence: Despite his best efforts to conceal his anger ________") ; 
strcpy(questions[0][2][2].options[0], "people came to know that he was annoyed") ; 
strcpy(questions[0][2][2].options[1], "he failed to give us an impression of his agony") ; 
strcpy(questions[0][2][2].options[2], "he succeeded in camouflaging his emotions") ; 
strcpy(questions[0][2][2].options[3], "he could succeed in doing it easily") ; 
questions[0][2][2].correct = 1 ; 

strcpy(questions[1][0][0].q, "The pointer which always stores the current active object address is _____") ; 
strcpy(questions[1][0][0].options[0], "auto_ptr") ; 
strcpy(questions[1][0][0].options[1], "this") ; 
strcpy(questions[1][0][0].options[2], "p") ; 
strcpy(questions[1][0][0].options[3], "None of the above") ; 
questions[1][0][0].correct = 2 ; 

strcpy(questions[1][0][1].q, "Which of the following is a valid real constant in exponent form in C++?") ; 
strcpy(questions[1][0][1].options[0], "172.E5") ; 
strcpy(questions[1][0][1].options[1], "1.52E07") ; 
strcpy(questions[1][0][1].options[2], "13,2E05") ; 
strcpy(questions[1][0][1].options[3], "17.17E2.3") ; 
questions[1][0][1].correct = 2 ; 

strcpy(questions[1][0][2].q, "In C++, the header file required to use setpricision() is ______") ; 
strcpy(questions[1][0][2].options[0], "<iostream.h>") ; 
strcpy(questions[1][0][2].options[1], "<math.h>") ; 
strcpy(questions[1][0][2].options[2], "<iomanip.h>") ; 
strcpy(questions[1][0][2].options[3], "<utility.h>") ; 
questions[1][0][2].correct = 3 ; 

strcpy(questions[1][1][0].q, "Which of the following are the members of SAARC (South Asian Association for Regional Cooperation)?") ; 
strcpy(questions[1][1][0].options[0], "Bhutan, Bangladesh, India and Pakistan") ; 
strcpy(questions[1][1][0].options[1], "Bhutan, Bangladesh, the Maldives, Nepal, India, Pakistan, Afghanistan and Sri Lanka") ; 
strcpy(questions[1][1][0].options[2], "Afghanistan, Pakistan, Thailand, Indonesia, Nepal and Sri Lanka") ; 
strcpy(questions[1][1][0].options[3], "None of the above") ; 
questions[1][1][0].correct = 2 ; 

strcpy(questions[1][1][1].q, "India's first satellite is named after ______") ; 
strcpy(questions[1][1][1].options[0], "Aryabhatta") ; 
strcpy(questions[1][1][1].options[1], "Bhaskara II") ; 
strcpy(questions[1][1][1].options[2], "Bhaskara I") ; 
strcpy(questions[1][1][1].options[3], "Albert Einstein") ; 
questions[1][1][1].correct = 1 ; 

strcpy(questions[1][1][2].q, "In which year, terrorists crash two planes into New York's World Trade Centre on September 11 in a sequence of destruction?") ; 
strcpy(questions[1][1][2].options[0], "2000") ; 
strcpy(questions[1][1][2].options[1], "2001") ; 
strcpy(questions[1][1][2].options[2], "2002") ; 
strcpy(questions[1][1][2].options[3], "2003") ; 
questions[1][1][2].correct = 2 ; 

strcpy(questions[1][2][0].q, "What is the antonym of HUAGHTY?") ; 
strcpy(questions[1][2][0].options[0], "Cowardly") ; 
strcpy(questions[1][2][0].options[1], "Scared") ; 
strcpy(questions[1][2][0].options[2], "Pitiable") ; 
strcpy(questions[1][2][0].options[3], "Humble") ; 
questions[1][2][0].correct = 4 ; 

strcpy(questions[1][2][1].q, "Complete the statement: He is so lazy that he ______") ; 
strcpy(questions[1][2][1].options[0], "cannot depend on others for getting his work done") ; 
strcpy(questions[1][2][1].options[1], "dislike to postpone the work that he undertakes to do") ; 
strcpy(questions[1][2][1].options[2], "cannot delay the schedule of completing the work") ; 
strcpy(questions[1][2][1].options[3], "can seldom complete his work on time") ; 
questions[1][2][1].correct = 4 ; 

strcpy(questions[1][2][2].q, "Choose the correct spelling") ; 
strcpy(questions[1][2][2].options[0], "Palate") ; 
strcpy(questions[1][2][2].options[1], "Palet") ; 
strcpy(questions[1][2][2].options[2], "Palete") ; 
strcpy(questions[1][2][2].options[3], "Pelate") ; 
questions[1][2][2].correct = 1 ; 

strcpy(questions[2][0][0].q, "In C++, which of the statements is valid?") ; 
strcpy(questions[2][0][0].options[0], "int &refs[10] ;") ; 
strcpy(questions[2][0][0].options[1], "int a2[] = a ;") ; 
strcpy(questions[2][0][0].options[2], "a + b = c ;") ; 
strcpy(questions[2][0][0].options[3], "None of the above") ; 
questions[2][0][0].correct = 4 ; 

strcpy(questions[2][0][1].q, "Which of the following statement is correct?") ; 
strcpy(questions[2][0][1].options[0], "A reference has to be de-referenced to access a value.") ; 
strcpy(questions[2][0][1].options[1], "A reference does not need to be de-referenced to access a value.") ; 
strcpy(questions[2][0][1].options[2], "A reference has to be double de-referenced to access a value.") ; 
strcpy(questions[2][0][1].options[3], "Whether a reference should be de-referenced or not depends on the type of the reference.") ; 
questions[2][0][1].correct = 2 ; 

strcpy(questions[2][0][2].q, "Which of the following is correct?") ; 
strcpy(questions[2][0][2].options[0], "A reference is declared using * operator.") ; 
strcpy(questions[2][0][2].options[1], "Once a reference variable has been defined to refer to a particular variable it can refer to any other variable.") ; 
strcpy(questions[2][0][2].options[2], "A reference must always be initialized within classes.") ; 
strcpy(questions[2][0][2].options[3], "A variable can have multiple references.") ; 
questions[2][0][2].correct = 4 ; 

strcpy(questions[2][1][0].q, "In which of the following years, the membership of the Security Council was increased from 11 to 15 (under Article 23)?") ; 
strcpy(questions[2][1][0].options[0], "1960") ; 
strcpy(questions[2][1][0].options[1], "1965") ; 
strcpy(questions[2][1][0].options[2], "1972") ; 
strcpy(questions[2][1][0].options[3], "1975") ; 
questions[2][1][0].correct = 2 ; 

strcpy(questions[2][1][1].q, "ICAO stands for ______") ; 
strcpy(questions[2][1][1].options[0], "International Civil Aviation Organization") ; 
strcpy(questions[2][1][1].options[1], "Indian Corporation of Agriculture Organization") ; 
strcpy(questions[2][1][1].options[2], "Institute of Company of Accounts Organization") ; 
strcpy(questions[2][1][1].options[3], "None of the above") ; 
questions[2][1][1].correct = 1 ; 

strcpy(questions[2][1][2].q, "India's first Technicolor film ____ in the early 1950s was produced by ____") ; 
strcpy(questions[2][1][2].options[0], "\'Jhansi Ki Rani\', Sohrab Modi") ; 
strcpy(questions[2][1][2].options[1], "\'Jhansi Ki Rani\', Sir Syed Ahmed") ; 
strcpy(questions[2][1][2].options[2], "\'Mirza Ghalib\', Sohrab Modi") ; 
strcpy(questions[2][1][2].options[3], "\'Mirza Ghalib\', Sir Syed Ahmed") ; 
questions[2][1][2].correct = 1 ; 

strcpy(questions[2][2][0].q, "Choose the correct spelling: ") ; 
strcpy(questions[2][2][0].options[0], "Vetarinary") ; 
strcpy(questions[2][2][0].options[1], "Vetinary") ; 
strcpy(questions[2][2][0].options[2], "Veteninary") ; 
strcpy(questions[2][2][0].options[3], "Veterinary") ; 
questions[2][2][0].correct = 4 ; 

strcpy(questions[2][2][1].q, "Pick the synonym of FECUND: ") ; 
strcpy(questions[2][2][1].options[0], "fertile") ; 
strcpy(questions[2][2][1].options[1], "hostile") ; 
strcpy(questions[2][2][1].options[2], "immature") ; 
strcpy(questions[2][2][1].options[3], "entangle") ; 
questions[2][2][1].correct = 1 ; 

strcpy(questions[2][2][2].q, "Pick the most appropriate word to complete the sentence: These slums are disgrace ________ the civic authorities.") ; 
strcpy(questions[2][2][2].options[0], "towards") ; 
strcpy(questions[2][2][2].options[1], "on") ; 
strcpy(questions[2][2][2].options[2], "for") ; 
strcpy(questions[2][2][2].options[3], "to") ; 
questions[2][2][2].correct = 4 ; 

}