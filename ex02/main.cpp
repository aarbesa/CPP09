#include "PmergeMe.hpp"


int main(int argc, char *argv[]) 
{
    if (argc <= 2) 
    {
        std::cerr << "Usage: " << argv[0] << " <num1> <num2> <num3> ..." << std::endl;
        return (1);
    }

    PmergeMe sorter;
    
    if (sorter.execution(argc, argv) == 1)
        return (1);
    return (0);
}