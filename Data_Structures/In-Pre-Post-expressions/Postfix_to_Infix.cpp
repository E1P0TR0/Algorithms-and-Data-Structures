#include <iostream>
#include <stack>

std::string PostfixToInfix(std::string);

int main()
{
    std::string expression = "ab+c-def^^*g/";
    std::cout << PostfixToInfix(expression);
    return 0;
}

std::string PostfixToInfix(std::string postfix)
{
    auto isOperator = [](char c){ return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') ? true : false; };
    auto isOperand = [](char c){ return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? true : false; };
    std::stack<std::string> stack;
    for(int i = 0; i < postfix.length(); i++)
    {
        if(isOperand(postfix[i]))
        {
            std::string operand(1, postfix[i]);
            stack.push(operand);
        }
        else if(isOperator(postfix[i]))
            {
                std::string op1 = stack.top();
                stack.pop();
                std::string op2 = stack.top();
                stack.pop();
                stack.push("(" + op2 + postfix[i] + op1 + ")");
            }
    }
    return stack.top();
}