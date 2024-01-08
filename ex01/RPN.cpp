#include "RPN.hpp"

RPN::RPN()
{
    // CLASS("Constructor", "RPN");
}

RPN::~RPN()
{
    // CLASS("Destructor", "RPN");
}

RPN::RPN(const RPN& other)
{
    CLASS("Constructor by copy", "RPN");
    if (this == &other)
        return ;
}

RPN& RPN::operator= (const RPN& other)
{
    CLASS("Operand = Constructor", "RPN");
    if (this == &other)
        return (*this);
    return (*this);
}


int RPN::reversePolishNotation(const std::string& expression) 
{

    std::string token;
    std::size_t index = 0;

    while (index < expression.size()) 
    {
        while (index < expression.size() && expression[index] == ' ') 
        {
            ++index;
        }

        std::size_t endIndex = index;
        while (endIndex < expression.size() && expression[endIndex] != ' ') 
        {
            ++endIndex;
        }

        token = expression.substr(index, endIndex - index);

        if (!token.empty()) 
        {
            if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && isdigit(token[1]))) 
            {
                int number = atoi(token.c_str());

                if (number > 9 || number < 0) 
                {
                    throw RPN::BadNumbers();
                }

                numbersStack.push(number);

            } 
            else if (token.size() == 1 && std::string("+-*/").find(token[0]) != std::string::npos) 
            {
                if (numbersStack.size() < 2) 
                {
                    throw RPN::MissingOp();
                }

                int operand2 = numbersStack.top();
                numbersStack.pop();
                int operand1 = numbersStack.top();
                numbersStack.pop();

                
                int result = applyOperation(operand1, operand2, token[0]);
                numbersStack.push(result);
            } 
            else 
            {
                throw RPN::BadArguments();
            }
        }

        index = endIndex;
    }

    if (numbersStack.size() != 1) 
    {
        throw RPN::BadArguments();
    }

    return (numbersStack.top());
}


int RPN::applyOperation(long long operand1, long long operand2, char op)
{
    long long result = 0;
     switch (op) 
     {
        case '+':
            result = operand1 + operand2;
            break ;
        case '-':
            result = operand1 - operand2;
            break ;
        case '*':
            result = operand1 * operand2;
            break ;
        case '/':
            if (operand2 != 0)
            {
                return operand1 / operand2;
            }
            else 
            {
                throw RPN::DivisionByZero();
            }
        default:
            throw RPN::invalidOp();
    }
    if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
    {
        throw RPN::ResultOutOfRange();
    }
    return (result);
}

const char * RPN::DivisionByZero::what() const throw()
{
	return ("Unallowed divsion by zero");
}

const char * RPN::BadNumbers::what() const throw()
{
	return ("Number must be between 0 and 9");
}

const char * RPN::MissingOp::what() const throw()
{
	return ("Not enough operands for operator");
}

const char * RPN::BadArguments::what() const throw()
{
	return ("Invalid token");
}

const char * RPN::invalidOp::what() const throw()
{
	return ("Invalid operator");
}

const char* RPN::ResultOutOfRange::what() const throw()
{
    return ("Result out of range for int");
}