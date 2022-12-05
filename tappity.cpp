#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
using namespace std;
#include "tappity.h"
/**
 * Class for tappity
**/

//Constructor sets the reference phrase
tappity::tappity(std::string reference)
{
  m_ref = reference;
}

//Provide the input to be compared to the reference. Before this 
//function is called, the input should be considered an empty string
void tappity::entry(std::string input)
{
  m_input = input;
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference()
{
  if(m_ref.length() > m_input.length()){
    return abs(m_ref.length() - m_input.length());
  }
  return abs(m_input.length() - m_ref.length());
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each 
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function 
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy()
{
  int dif = length_difference();
  int num_correct = 0;
  double acc;
  if(!dif){
    //calculate difference in characters
    if(m_input.length() == 0 and m_ref.length() == 0){return (double)100;}
    for(int i=0; i<m_input.length(); ++i){
      if(m_input[i] == m_ref[i]){
        ++num_correct;
      }
    }
    acc = ((double)num_correct / (double)m_ref.length()) * (double)100;
  }
  else{
    //calculate the difference in characters with magic
    if(m_ref.length() > m_input.length()){// this means the reference has more characters than the input
      for(int i=0; i<m_input.length(); ++i){//we loop through the shorter string and divide by the longer string
        if(m_input[i] == m_ref[i]){
          ++num_correct;
        }
      }
      acc = ((double)num_correct / (double)m_ref.length()) * (double)100;
    }
    else{//this means the input has more characters than the reference
      for(int i=0; i<m_ref.length(); ++i){
        if(m_input[i] == m_ref[i]){
          ++num_correct;
        }
      }
      acc = ((double)num_correct / (double)m_input.length()) * (double)100;
    }
  }
  return acc;
}