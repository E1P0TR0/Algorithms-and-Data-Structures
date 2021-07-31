#include <iostream>
#include <stack>
#include <algorithm>

std::string PrefixToInfix(std::string);

int main()
{
    std::string expression = "/*-+abc^d^efg";
    std::cout << PrefixToInfix(expression);
    return 0;
}

std::string PrefixToInfix(std::string postfix)
{
    auto isOperator = [](char c){ return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') ? true : false; };
    auto isOperand = [](char c){ return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? true : false; };
    std::stack<std::string> stack;
    std::reverse(postfix.begin(), postfix.end());
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
                stack.push("(" + op1 + postfix[i] + op2 + ")");
            }
    }
    return stack.top();
}