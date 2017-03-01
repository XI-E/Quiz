/*!
 \file helpers.hpp
 \brief Contains helper functions such as wrap	
*/

#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <stdio.h>
#include <string.h>

//! Wraps a string with specified number of characters in each line
/*!
 Takes in an input string and changes the output string with length (or less)
 number of characters, each separated by '\n'
 @param[in]  inp_str The input string
 @param[out] out_str The output string
 @param[in]  length  The max. number of characters in each line
 @return The number of lines contained in out_str
*/
int wrap(char* inp_str, char* out_str, int length);

#endif //HELPERS_HPP
