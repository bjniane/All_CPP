#include "RPN.hpp"

bool isOperator(const std::string& token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool    validToken(const std::string& c)
{
    if (c[1])
        return false;
    if (!std::isdigit(c[0]))
    {
        if (isOperator(c))
            return true;
        else
            return false;
    }
    return true;
}

int convertInt(std::string& str)
{
    std::stringstream s(str);
    int value;
    s >> value;
    return value;
}


void    RPN(const std::string &s)
{
    std::stringstream   str(s);
    std::string token;
    std::stack<int> stack;
    while (str >> token)
    {
        if (!validToken(token))
        {
            std::cerr << "Error: invalid token ==> " << token << std::endl;
            return;
        }
        if (!isOperator(token))
        {
            int value = convertInt(token);
            stack.push(value);
        }
        else
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: invlid operands." << std::endl;
                return;
            }
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            int result;
            if (token[0] == '+')
                result = a + b;
            else if (token[0] == '-')
                result = a - b;
            else if (token[0] == '*')
                result = a * b;
            else
            {
                if (b == 0)
                {
                    std::cerr << "Error: division by 0." << std::endl;
                    return;
                }
                result = a / b;
            }
            stack.push(result);
        }
    }
    if (stack.size() != 1)
    {
        std::cerr << "Error: should be a final result in the stack." << std::endl;
        return;
    }
    std::cout << stack.top() << std::endl;
}   