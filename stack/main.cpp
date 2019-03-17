/*
TO DO:
negative numbers
parenthesis
*/

#include "stack.cpp"

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

int calculate(char oprt, int arg1, int arg2)
{
   int sol = 0;
   switch(oprt) {
      case '+':
      sol = arg1+arg2;
      break;
      case '-':
      sol = arg1-arg2;
      break;
      case '*':
      sol = arg1*arg2;
      break;
      case '/':
      sol = arg1/arg2;
      default:
      break;
   }
   return sol;
}

void setArguments(Stack<int>& operands, Stack<char>& operators)
{
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

  string exp = "3   *2  +6 /2";

  // cout << "Type INFIX expression" << endl;
  // getline(cin, exp);

  for (int i = 0; i < exp.length(); i++) {

    if (exp[i] == ' ') {
      continue;
    }

    else if (isdigit(exp[i])) {
      int value = 0;

      value = (value*10) + (exp[i] - '0'); //always sets digit

      while (i < exp.length() && isdigit(exp[i + 1])) { //only sets digit if following is a digit
        value = (value*10) + (exp[i+1] - '0');
        i++;
      }
      operands.push(value);

    } else {
       while(!operators.isEmptyStack() && preference(operators._top()) >= preference(exp[i])) //solves high preference operators
       {
          setArguments(operands, operators);
       }
       operators.push(exp[i]); //pushes operator
    }
} //end of for loop

while(!operators.isEmptyStack()) //solves resolving operators
{
   setArguments(operands, operators);
}
int result = operands._top();
cout << "The result is: " << result << endl;
}
