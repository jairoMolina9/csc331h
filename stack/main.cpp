/*

*/

#include "stack.cpp"

int preference(char oprt)
{
    int preference = 0;
    switch (oprt)
    {
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

int main()
{
    Stack<int> operands;
    Stack<char> operators;
    
    string exp = "";
    
    cout << "Type INFIX expression" << endl;
    getline(cin, exp);
    
    for(int i = 0 ; i < exp.length() ; i++)
    {
        int value = 0;
        
        if(exp[i] == ' ')
        {
            continue;
        }
        else if (exp[i] == '(')
        {
            operators.push(exp[i]);
        }
        else if(isdigit(exp[i]))
        {
            while(i < exp.length() && isdigit(exp[i]))
            {
                value = (value*10) + exp[i] - '0';
            }
            operands.push(value);
        } else if (exp[i] == ')'){
            while(!operators.isEmptyStack() && operators._top() != '(')
            {
                //
            }
            
        }
        else {
            operators.push(exp[i]);
        }
    }
}
