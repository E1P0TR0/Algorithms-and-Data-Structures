#include <iostream>
#include <string>
#include <stack>

std::string InfixToPostfix(std::stack<char>, std::string);

int main()
{
    std::string expression = "((a+b-c)*d^e^f)/g";
    std::stack<char> s;
   
    std::cout << InfixToPostfix(s, expression);
    return 0;
}

std::string InfixToPostfix(std::stack<char> stack, std::string infix)
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
    std::string postfix;
    for(int i = 0; i < infix.length(); ++i)
    {
        if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
            postfix += infix[i];
        else if(infix[i] == '(')
                stack.push(infix[i]);
        else if(infix[i] == ')')
            {
                while(stack.top() != '(' && !stack.empty())
                {
                    postfix += stack.top();
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
                            stack.push(infix[i]);
                    else
                    {
                        while(!stack.empty() && precedence(infix[i]) <= precedence(stack.top()))
                        {
                            postfix += stack.top();
                            stack.pop();
                        }
                        stack.push(infix[i]);
                    }
    }
    while(!stack.empty())
    {
        postfix += stack.top();
        stack.pop();
    }
    return postfix;
}


