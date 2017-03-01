/*!
 \file quiz.hpp
 \brief Contains prototypes of all functions required
*/

#ifndef QUIZ_HPP
#define QUIZ_HPP

#include "helpers.hpp"
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <fstream.h>

//! The maximum number of subjects
#define SUB_MAX 5

//! Standard string length
#define STDSTRLEN 100
//! Increases standard string length factor times
#define BIGSTRLEN(factor) (STDSTRLEN * factor)
//! Decreases standard string length factor time
#define SMALLSTRLEN(factor) (STDSTRLEN / factor) 

//! Title of the quiz
#define TITLE "TEST YOUR KNOWLEDGE!"

//! Maximum number of questions allowed per level
#define MAXQPERLVL 10

//! Structure to represent a question
struct question
{
	char q[BIGSTRLEN(2)]; //!< The question
	char options[4][BIGSTRLEN(2)]; //!< The options
	int correct; //!< The correct option (option count starts from 1)
};

//! Structure to represent information pertaining to a particular subject
struct sub
{
	char fname[SMALLSTRLEN(2)]; //!< The name of file from where to access questions of this subject
	char sub_name[BIGSTRLEN(2)]; //!< The name of subject
	char short_name[SMALLSTRLEN(2)]; //!< Short name of subject to print when space is less
	int q_per_level[3]; //!< Questions in the subject per level
};

//! Structure to represent a coordinate of type (x,y)
struct coord
{
	//! Constructor with inputs
	/*!
	 @param[in] x_inp The x-coordinate to be set
	 @param[in] y_inp The y-coordinate to be set
	*/
	coord(int x_inp, int y_inp)
	{
		x = x_inp;
		y = y_inp;
	}
	
	//! Default constructor
	/*!
	 Sets both x and y coordinates to 0 
	*/
	coord()
	{
		x = 0;
		y = 0;
	}
	int x; //!< x coordinate
	int y; //!< y coordinate
};

//ques.cpp

//! Copies the question indicated by the parameters into a question parameter
/*!
 @param[in]  lvl   Level (zero indexed)
 @param[in]  sub   Subject Number (zero indexed)
 @param[in]  q_num Question number for the particular lvl and sub (zero indexed)
 @param[out] ques  Stores the question into this variable
 \sa question
 @return void
*/
void init_ques(int lvl, int sub, int q_num, question& ques);

extern sub subs[SUB_MAX]; //!< Stores the information pertaining to all subjects
extern int num_subs; //!< The number of subjects

//! Gets Information on subjects from file
/*!
 Reads a file called q_info.txt and reads the information on subjects from it
 @return void
*/
void init_qinfo();

//uihelp.cpp

//! Initialises the User Interface by setting general requirements for other UI functions
/*!
 @return void
*/
void init_ui();

extern int height; //!< Height of the screen
extern int width; //!< Width of the screen

//! Prints the input string at center of line
/*
 Prints the input string at center; If ws is defined, it prints the string with ws
 number of ' ' characters before the string. The text color and background color are
 specified through t_color and b_color respectively.
 @param[in] str     The input string to be printed
 @param[in] ws      Amount of whitespace from left end (-1, if not specified)
 @param[in] t_color Text color (LIGHTGRAY, if not specified)
 @param[in] b_color Background color (BLACK, if not specified)
 @return void
*/
void printc(char* str, int ws = (-1), int t_color = LIGHTGRAY, int b_color = BLACK);

//! Defines the modes from printing the frame
enum frame_modes {NOSIDES, SIDES};

//! Generates a frame
/*!
 @param[in] up_left  Upper left coordinate of frame; upper-left corner of window, if not specified
 @param[in] f_height Height of frame
 @param[in] f_width  Width of frame
 @param[in] f_mode   Specifies the mode for printing frame
 @return void
 \sa coord, frame_modes
*/
void frame (coord up_left = coord(-1,-1), int f_height = -1, int f_width = -1, int f_mode = SIDES);

//! Defines what type of key will invoke the select function to return a value
/*!
 \sa select()
*/
enum select_modes { 
					NO_NAV, //!< No navigation
				    BCKSPC, //!< Backspace key
				    ESC //!< Escape key
				  };

//! Makes the user select the option
/*!
 Takes in coordinates of first bullet, number of options and prints the bullets
 according to the height of each option. 
 It takes in the character to be printed as a bullet
 Mode specifies what it will return if that key is pressed
 BCKSPC -1
 ESC    -2
 
 @param[in] bullet1    Co-ordinate of first bullet
 @param[in] num_ops    Number of options
 @param[in] height_ops Height of each option
 @param[in] mode       Specifies if navigation is to be allowed or not
 @param[in] bullet     Character to be printed as bullet
 @return The selected option (starts from 0)
 \sa coord, select_modes
*/
int select(coord bullet1, int num_ops, int* height_ops, int mode = NO_NAV, char bullet = (char) 175);

//! The print modes of options for props()
/*!
 \sa props()
*/
enum print_modes {
					NUM, //!< Numbered (1,2,3)
					ALPHA, //!< Alphabets (A,B,C)
					SROM, //!< Small Roman Numerals (i, ii, iii)
					CROM, //!< Capital Roman Numerals (I, II, III)
					NONUM //!< No numbering
				 };

//! Prints the options
/*!
 @param[in]  num_ops    The number of options
 @param[in]  ops        2D array containing options: ops[num_ops][STRLEN]
 @param[in]  head       Heading of the options
 @param[out] f_uleft    Upper left coordinate of frame enclosing options
 @param[out] ops_height Height (Number of lines) of options
 @param[in]  print_mode Specifies if the options are to numbered or not
 @return Coordinate of the first bullet
 \sa coord, print_modes
*/
coord props(const int num_ops, char ops[][BIGSTRLEN(2)], char head[], coord& f_uleft, int ops_height[], int print_mode = NONUM);

//! Prints the header
/*!
 It assumes that there is an outer frame and there is enough 
 space to print left, middle, and right strings
 @param[in] left   Left aligned header
 @param[in] middle Centre aligned header
 @param[in] right  Right aligned header
 @return void
*/
void prhead(char left[], char middle[], char right[]);

//! Prints the footer
/*!
 It assumes that there is an outer frame and there is enough 
 space to print left, middle, and right strings
 @param[in] left   Left aligned footer
 @param[in] middle Centre aligned footer
 @param[in] right  Right aligned footer
 @return void
*/
void prfoot(char left[], char middle[], char right[]);

//ui.cpp

//! Wrapper for the UI functions
/*!
 @return If the user wants to play again (1 for yes, 0 for no)
*/
int play();

//! Gets the mode in which the user wants to play the quiz
/*!
 @return The mode selected (0 indexed)
*/
int getmode();

//! Play according to subject and level
/*!
 Invoked when the mode is set to 0 (zero)
 The function prints questions, keeps track of total questions
 attempted & attempted correctly, prints the result and also 
 asks if user wants to play again. It will exit the round if
 ESC key is pressed
 Value of screen_num Function
 1		  			 Gets difficulty from user and returns it
 2		  			 Gets subject from user and returns it
 3		  			 Asks the questions pertaining to the lvl and sub
 4		  			 Asks if user wants to play again and returns choice
 		  			 (1 for yes, 0 for no)
 @return Depends on screen_num
 \sa askq()
*/
int prscr_m1(int screen_num);

//! Play with random questions
/*!
 Invoked when the mode is set to 1
 The function prints questions randomly from all subjects and 
 difficulty levels. It exits the round on pressing ESC and/or
 the question set is exhausted and then proceeds to show the 
 result i.e Number of questions attempted correctly
 @return If the user wants to play again (1 for yes, 0 for no)
 \sa askq()
*/
int prscr_m2();

//! Prints the question, gets response and displays the result
/*!
 It asks the question as specified by the parameters lvl, sub_num
 and q_num. It randomises the order in which the options of the
 question are displayed.
 @param[in] lvl     Difficulty level (zero indexed)
 @param[in] sub_num Subject number (zero indexed)
 @param[in] q_num   Question number for accessing info (zero indexed)
 @param[in] q_num2  Question number for printing purposes (1 indexed)
*/
int askq(int lvl, int sub_num, int q_num, int q_num2);
				  
#endif /* QUIZ_HPP */
