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

#include "stack.cpp"
#include <algorithm>

int preference(char oprt) {
  int preference = 0;
  switch (oprt) {
  case '+':
  case '-':
    preference = 1;
    break;
  case '*':
  case '/':
    preference = 2;
  default:
    break;
  }

  return preference;
}

int calculate(char oprt, int arg1, int arg2) {
  int sol = 0;
  switch (oprt) {
  case '+':
    sol = arg1 + arg2;
    break;
  case '-':
    sol = arg1 - arg2;
    break;
  case '*':
    sol = arg1 * arg2;
    break;
  case '/':
    sol = arg1 / arg2;
  default:
    break;
  }
  return sol;
}

/* gets stack values */
void setArguments(Stack<int> &operands, Stack<char> &operators) {
  int arg2 = operands._top();
  operands.pop();

  int arg1 = operands._top();
  operands.pop();

  char opt = operators._top();
  operators.pop();

  operands.push(calculate(opt, arg1, arg2));
}

int main() {
  Stack<int> operands;
  Stack<char> operators;

  string exp;                                               //holds expression

  do {
    cout << "Type INFIX expression or 'X' to quit" << endl;
    getline(cin, exp);
                                          //algorithm library, erases exp spaces
    exp.erase(remove_if(exp.begin(), exp.end(), ::isspace), exp.end());
    if (exp == "x" || exp == "X")
      continue;                                       //makes sure exp is not X
    for (int i = 0; i < exp.length(); i++) {                 //start of for loop

      if (exp[i] == '(') {
        operators.push(exp[i]);
     } else if (isdigit(exp[i])) {
        int value = 0;

        value = (value * 10) + (exp[i] - '0');              // always sets digit

        while (i < exp.length() &&
               isdigit(exp[i + 1])) {   // for numbers that aren't single digits

          value = (value * 10) + (exp[i + 1] - '0');
          i++;
        }
        operands.push(value);

     } else if (exp[i] == ')') {                                  // end of (..)
        while (!operators.isEmptyStack() && operators._top() != '(') {
          setArguments(operands, operators);  //calculates operations inside (..)
        }

        operators.pop();                             //closes (..) by popping ')'

   /* Finds negative digit if current 'i' is 0 index or if is any symbol besides ')' */
     } else if (exp[i] == '-' && (i == 0 || (exp[i - 1] >= '(' && exp[i - 1] <= '/' && exp[i - 1] != ')'))) {
          while (i < exp.length()) {

            if (isdigit(exp[i + 1])) {  //if char to the right of '-' is a digit
              int value = 0;

              value = (value * 10) + (exp[++i] - '0'); //set value to digit on the right of '-'

              while ( i < exp.length() && isdigit(exp[i + 1])) { // makes sure digit is not a single number
                value = (value * 10) + (exp[i + 1] - '0');
                i++;
              }
              operands.push(value * -1); //makes value negative
            }
            break; //break once digit is pushed
          }
      } else {
      /* solves high preference operators first */
        while (!operators.isEmptyStack() && preference(operators._top()) >= preference(exp[i])) {
          setArguments(operands, operators);
        }

        operators.push(exp[i]); //pushes first operator in expression and then lower preference operators
      }
    } // end of for loop

    while (!operators.isEmptyStack()) // solves remaining low preference operators
    {
      setArguments(operands, operators);
    }

    cout << "The result is: " << operands._top() << endl;
    operands.pop(); //pops final result
  } while (exp != "x" && exp != "X");

  cout << "Good bye" << endl;
  return 0;
}
