#include <iostream>
#include <stack>
#include <algorithm>

std::string PrefixToPostfix(std::string postfix);

int main()
{
    std::string expression = "+a*bc";
    std::cout << PrefixToPostfix(expression);
    return 0;
}

std::string PrefixToPostfix(std::string prefix)
{
    auto isOperator = [](char c){ return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') ? true : false; };
    auto isOperand = [](char c){ return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? true : false; };
    std::stack<std::string> stack;
    std::reverse(prefix.begin(), prefix.end());
    for(int i = 0; i < prefix.length(); i++)
    {
        if(isOperand(prefix[i]))
        {
            std::string operand(1, prefix[i]);
            stack.push(operand);
        }
        else if(isOperator(prefix[i]))
            {
                std::string op1 = stack.top();
                stack.pop();
                std::string op2 = stack.top();
                stack.pop();
                stack.push(op1 + op2 + prefix[i]);
            }
    }
    return stack.top();
}