/*
 * main.cpp
 *
 *  Created on: Mar 21, 2019
 *      Author: Jairo Molina
 *
 *        Purpose: The purpose of this file is to set stack structure and its
 *                 functions.
 */

#ifndef SOLVEEXPRESSION_H
#define SOLVEEXPRESSION_H

#include "stack.cpp"

class ExpressionEvaluator{

private:
   Stack<char> operators;                          //Stores symbols
   Stack<int> operands;                            //Stores numbers
   string exp;                                     //Contains expression

public:
   ExpressionEvaluator(string);                    //Receives expression

   int preference(char oprt);                      //Sets preference in operators
   int calculate(char oprt, int arg1, int arg2);   //Solves single calculation

   void setArguments();                            //Gets arguments from stacks
   void solve();                                   //Solves entire expression

};
#endif /* SOLVEEXPRESSION_H */
