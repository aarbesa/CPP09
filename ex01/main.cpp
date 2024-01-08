#include "RPN.hpp"

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        std::cerr << "Usage: " << argv[0] << " <Reverse Polish Notation expression>" << std::endl;
        return 1;
    }

    std::string expression = argv[1];

    try 
    {
        RPN calculator;
        int result = calculator.reversePolishNotation(expression);
        std::cout << "Result: " << result << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
