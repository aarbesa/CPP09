#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>
# include <limits>

# ifndef CLASS
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

class RPN
{
    private:

    int applyOperation(long long operand1, long long operand2, char op);
    std::stack<int> numbersStack;


    public:
        RPN();
        ~RPN();
        RPN(const RPN&);
        RPN& operator= (const RPN&);

        int reversePolishNotation(const std::string& expression);

        class DivisionByZero: public std::exception
		{
			const char* what() const throw();
		};

        class  BadNumbers: public std::exception
		{
			const char* what() const throw();
		};

        class  MissingOp: public std::exception
		{
			const char* what() const throw();
		};

        class  BadArguments: public std::exception
		{
			const char* what() const throw();
		};

        class   invalidOp: public std::exception
		{
			const char* what() const throw();
		};

        class   ResultOutOfRange: public std::exception
		{
			const char* what() const throw();
		};

};

#endif
