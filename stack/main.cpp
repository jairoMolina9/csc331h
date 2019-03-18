/*
TO DO:
if negative sign is in first place
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

void setArguments(Stack < int > & operands, Stack < char > & operators) {
  int arg2 = operands._top();
  operands.pop();

  int arg1 = operands._top();
  operands.pop();

  char opt = operators._top();
  operators.pop();

  operands.push(calculate(opt, arg1, arg2));
}

int main() {
  Stack < int > operands;
  Stack < char > operators;

  string exp;
  
  do {
    cout << "Type INFIX expression or 'X' to quit" << endl;
    getline(cin, exp);
    //exp.erase(remove_if(exp.begin(), exp.end(), ::isspace), exp.end()); 
    if (exp == "x" || exp == "X") continue; //skips code
    for (int i = 0; i < exp.length(); i++) {

      if (exp[i] == ' ') {
        continue;
      } else if (exp[i] == '(') {
        operators.push(exp[i]);
      } else if (isdigit(exp[i])) {
        int value = 0;

        value = (value * 10) + (exp[i] - '0'); //always sets digit

        while (i < exp.length() && isdigit(exp[i + 1])) { //only sets digit if following is a digit
          value = (value * 10) + (exp[i + 1] - '0');
          i++;
        }
        operands.push(value);

      } else if (exp[i] == ')') {
        while (!operators.isEmptyStack() && operators._top() != '(') {
          setArguments(operands, operators);
        }
        // pop opening brace. 
        operators.pop();
      } else if (exp[i] == '-') {
        if (i == 0) { //need to do if - 2+1
          while (i < exp.length()) {
            if (exp[i + 1] == ' ') {
              i++;
            } else if (isdigit(exp[i + 1])) {
              int value = 0;

              value = (value * 10) + (exp[++i] - '0'); //always sets digit

              while (i < exp.length() && isdigit(exp[i + 1])) { //only sets digit if following is a digit
                value = (value * 10) + (exp[i + 1] - '0');
                i++;
              }
              operands.push(value * -1);
            }
            break;
          } //need to do if - 2+1
        } else {

          int j = i - 1; //checks index of before '-'
          while (j >= 0) {
            if (exp[j] == ' ') {
              j--;
            } else if (exp[j] >= 40 && exp[j] <= 47) { // if symbol
              if (isdigit(exp[++i])) {
                int value = 0;
                value = (value * 10) + (exp[i] - '0');
                while (i < exp.length() && isdigit(exp[i + 1])) { //only sets digit if following is a digit
                  value = (value * 10) + (exp[i + 1] - '0');
                  i++;
                }
                operands.push(value * -1);

                break;
              }
            } else if (isdigit(exp[j])) {
              operators.push(exp[i]);
              break;
            } else {
              j--;
            }
          }
        }
      } else {
        while (!operators.isEmptyStack() && preference(operators._top()) >= preference(exp[i])) //solves high preference operators
        {
          setArguments(operands, operators);
        }
        operators.push(exp[i]); //pushes operator
      }
    } //end of for loop

    while (!operators.isEmptyStack()) //solves resolving operators
    {
      setArguments(operands, operators);
    }
    cout << "The result is: " << operands._top() << endl;
    operands.pop();
  } while (exp != "x" && exp != "X");
  cout << "Good bye" << endl;
  return 0;
}
