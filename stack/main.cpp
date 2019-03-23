/*
 * main.cpp
 *
 *  Created on: Mar 21, 2019
 *      Author: Jairo Molina
 *
 *        Purpose: The purpose of this file is to calculate infix expressions
 *                 following PEMDAS and including negative numbers using two
 *                 stacks.
 */

#include "solveExpression.h"
#include <algorithm>

int main() {

  string exp;  //math expression

  do {
         cout << "Type INFIX expression or 'X' to quit" << endl;
         getline(cin, exp);

         if (exp == "x" || exp == "X")
            continue;

            //algorithm library, erases every space in string 'exp'
         exp.erase(remove_if(exp.begin(), exp.end(), ::isspace), exp.end());

         ExpressionEvaluator expression(exp); //sets expression

         expression.solve(); //solves expression

  } while (exp != "x" && exp != "X");

  cout << "Good bye" << endl;

  return 0;
}
