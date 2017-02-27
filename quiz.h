/*!
 \file quiz.h
 \brief Contains prototypes of all functions required
*/

#ifndef QUIZ_H
#define QUIZ_H

#include "helpers.h"
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


//! Structure to represent a question
struct question
{
	char q[200]; //!< The question
	char options[4][100]; //!< The options
	int correct; //!< The correct option (option count starts from 1)
};

//ques.cpp

//! Initialises the struct questions
/*!
 \sa question
 @return void
*/
void init_ques();

//ui.cpp

//! Initialises the User Interface by setting general requirements for other UI functions
/*!
 @return void
*/
void init_ui();

//! Prints the input string at center of line
/*!
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


//! Generates a frame
/*!
 @param[in] up_left  Upper left coordinate of frame; upper-left corner of window, if not specified
 @param[in] f_height Height of frame
 @param[in] f_width  Width of frame
 @param[in] f_sides  Specifies whether sides of frame should be printed (1 = true, 0 = false)
 @return void
 \sa coord
*/
void frame (coord up_left = coord(-1,-1), int f_height = -1, int f_width = -1, int f_sides = 1);

//! Generates UI for specified screen
/*!
 The UI generated includes selection of option and putting them in a frame
 @param[in] screen_num Screen Number (1: Difficulty, 2: Subject)
 @return The line selected (starting from 0)
 \sa frame(), printc(), coord, select()
*/
int generate_ui(int screen_num);

//! Generates UI for question screen
/*!
 The UI generated includes selection of option and putting them in a frame
 @param[in] lvl   Difficulty Level
 @param[in] sub   Subject
 @param[in] q_num Question Number (starts from 0)
 @return The option selected (starting from 0)
 \sa frame(), printc(), coord, select()
*/
int generate_ui(int lvl, int sub, int q_num);

//askq.cpp

//! Asks questions
/*!
 Uses generate_ui() to ask questions, keeps track of correct answers, prints
 it at the end of quiz and asks the user whether to continue playing.
 @param[in] lvl   Difficulty Level
 @param[in] sub   Subject
 @return Whether user wants to play again (0: no, 1: yes)
 \sa generate_ui(), frame(), printc()
*/
int ask_q(int lvl, int sub);

//! Makes the user select the option
/*!
 Takes in coordinates of first bullet, number of options and prints the bullets
 according to the height of each option. Also, takes in the character to be printed
 as a bullet
 @param[in] bullet1    Co-ordinate of first bullet
 @param[in] num_ops    Number of options
 @param[in] height_ops Height of each option
 @param[in] bullet     Character to be printed as bullet
 @return The selected option (starts from 0)
 \sa coord
*/
int select(coord bullet1, int num_ops, int* height_ops, char bullet = (char) 175);

/*!
 \overload
 @param[in] bullet1    Co-ordinate of first bullet
 @param[in] num_ops    Number of options
 @param[in] bullet     Character to be printed as bullet
 @return The selected option (starts from 0)
*/
int select(coord bullet1, int num_ops, char bullet = (char) 175);


#endif //QUIZ_H
