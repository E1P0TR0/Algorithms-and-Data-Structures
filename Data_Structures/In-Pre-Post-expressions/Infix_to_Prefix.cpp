#include <iostream>
#include <stack>
#include <algorithm>

std::string InfixToPrefix(std::stack<char>, std::string);

int main()
{
    std::stack<char> s;
    std::string expression = "((a+b-c)*d^e^f)/g";

    std::cout << InfixToPrefix(s, expression);
    return 0;
}

std::string InfixToPrefix(std::stack<char> stack, std::string infix)
{
    auto isOperator = [](char c){ return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') ? true : false; };
    auto precedence = [](char c)
    { 
        if(c == '^') return 3;
        else if(c == '*' || c == '/') return 2;
        else if(c == '+' || c == '-') return 1;
        else 
            return -1;
    };
    std::string prefix;
    std::reverse(infix.begin(), infix.end());
    for(int i = 0; i < infix.length(); ++i)
    {
        if(infix[i] == '(') 
            infix[i] = ')';
        else if(infix[i] == ')') 
                infix[i] = '(';
    }
    for(int i = 0; i < infix.length(); ++i)
    {
        if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
            prefix += infix[i];
        else if(infix[i] == '(')
                stack.push(infix[i]);
        else if(infix[i] == ')')
            {
                while(stack.top() != '(' && !stack.empty())
                {
                    prefix += stack.top();
                    stack.pop();
                }
                if(stack.top() == '(')
                    stack.pop();
            }
        else if(isOperator(infix[i]))
                if(stack.empty())
                    stack.push(infix[i]);
                else
                    if(precedence(infix[i]) > precedence(stack.top()))
                        stack.push(infix[i]);
                    else if(precedence(infix[i]) == precedence(stack.top()) && infix[i] == '^')
                        {
                            while(precedence(infix[i]) == precedence(stack.top()) && infix[i] == '^')
                            {
                                prefix += stack.top();
                                stack.pop();
                            }
                            stack.push(infix[i]);
                        }
                    else if(precedence(infix[i]) == precedence(stack.top()))
                            stack.push(infix[i]);
                    else
                    {
                        while(!stack.empty() && precedence(infix[i]) < precedence(stack.top()))
                        {
                            prefix += stack.top();
                            stack.pop();
                        }
                        stack.push(infix[i]);
                    }
    }
    while(!stack.empty())
    {
        prefix += stack.top();
        stack.pop();
    }
    std::reverse(prefix.begin(), prefix.end());
    return prefix;  
}