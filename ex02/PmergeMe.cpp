#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    // CLASS("Constructor", "PmergeMe");
}

PmergeMe::~PmergeMe()
{
    // CLASS("Destructor", "PmergeMe");
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    CLASS("Constructor by copy", "PmergeMe");
    if (this == &other)
        return ;
}

PmergeMe& PmergeMe::operator= (const PmergeMe& other)
{
    CLASS("Operand = Constructor", "PmergeMe");
    if (this == &other)
        return (*this);
    return (*this);
}



void PmergeMe::insertionSort(std::vector<int>& vec)
{
    int size = vec.size();

    for (int i = 1; i < size; ++i) 
    {
        int pos = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] > pos) 
        {
            vec[j + 1] = vec[j];
            --j;
        }

        vec[j + 1] = pos;
    }
}



void PmergeMe::insertionSort(std::deque<int>& deq)
{
    int size = deq.size();

    for (int i = 1; i < size; ++i) 
    {
        int pos = deq[i];
        int j = i - 1;

        while (j >= 0 && deq[j] > pos) 
        {
            deq[j + 1] = deq[j];
            --j;
        }

        deq[j + 1] = pos;
    }
}


std::vector<int> PmergeMe::sortRight(const std::vector<std::pair<int, int> > & pairs)
{
    std::vector<int> rightNumbers;
    std::vector<std::pair<int, int> > sortedPairs = pairs;

    std::sort(sortedPairs.begin(), sortedPairs.end(), &PmergeMe::pairComparator);

    for (size_t i = 0; i < sortedPairs.size(); ++i) 
    {
        rightNumbers.push_back(sortedPairs[i].second);
    }

    return (rightNumbers);
}

std::deque<int> PmergeMe::sortRight(const std::deque<std::pair<int, int> > & pairs)
{
    std::deque<int> rightNumbers;
    std::deque<std::pair<int, int> > sortedPairs = pairs;


    std::sort(sortedPairs.begin(), sortedPairs.end(), &PmergeMe::pairComparator);


    for (size_t i = 0; i < sortedPairs.size(); ++i) 
    {
        rightNumbers.push_back(sortedPairs[i].second);
    }

    return rightNumbers;
}

bool PmergeMe::pairComparator(const std::pair<int, int> & a, const std::pair<int, int> & b)
{
    return a.second < b.second;
}

void PmergeMe::fordJohnsonSort(std::vector<int> & vec)
{
    bool oddSequence = (vec.size() % 2 != 0);


    std::vector<std::pair<int, int> > pairs;
    size_t pairCount = vec.size() / 2;

    int lastElement = 0;
    if (oddSequence) 
    {
        lastElement = vec.back();
        vec.pop_back();
    }

    for (size_t i = 0; i < pairCount * 2 - 1; i += 2) 
    {
        pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
    }

    for (size_t i = 0; i < pairCount; ++i) 
    {
        if (pairs[i].first > pairs[i].second) {
            std::swap(pairs[i].first, pairs[i].second);
        }
    }

    std::vector<int> sortedRight = sortRight(pairs);

    if (oddSequence) 
    {
        vec.push_back(lastElement);
    }

    insertionSort(vec);
}

void PmergeMe::fordJohnsonSort(std::deque<int> & deq)
{
    
    bool oddSequence = (deq.size() % 2 != 0);

    
    std::deque<std::pair<int, int> > pairs;
    size_t pairCount = deq.size() / 2;


    int lastElement = 0;
    if (oddSequence) 
    {
        lastElement = deq.back();
        deq.pop_back(); 
    }

        
    for (size_t i = 0; i < pairCount * 2 - 1; i += 2) 
    {
        pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
    }

    
    for (size_t i = 0; i < pairCount; ++i) 
    {
        if (pairs[i].first > pairs[i].second) 
        {
            std::swap(pairs[i].first, pairs[i].second);
        }
    }

    std::deque<int> sortedRight = sortRight(pairs);

    
    if (oddSequence) 
    {
        deq.push_back(lastElement);
    }


    insertionSort(deq);
    // isSorted(deq);
}

double PmergeMe::getTime() 
{
    return static_cast<double>(std::clock()) / CLOCKS_PER_SEC * 1e6;
}

bool PmergeMe::duplicatesNumbers(const std::vector<int> & vec) const
{
    for (size_t i = 0; i < vec.size(); ++i) 
    {
        for (size_t j = i + 1; j < vec.size(); ++j)
        {
            if (vec[i] == vec[j]) 
            {
                return (true);
            }
        }
    }
    return (false);
    
}

void    PmergeMe::isSorted(std::deque<int> & deq) const
{
    std::deque<int>::iterator it = deq.begin();
    std::deque<int>::iterator ite = it + 1;

    while (ite != deq.end())
    {
        if (*it > *ite)
        {
            std::cout << "Stack is not ordered: " << *it << " is bigger than " << *ite << std::endl;
            return ;
        }
        it++;
        ite++;
    }
    std::cout << "Stack is ordered !" << std::endl;
}

int PmergeMe::execution(int argc, char *argv[])
{
    const int maxInt = std::numeric_limits<int>::max();

    std::vector<int> numbers;

    for (int i = 1; i < argc; ++i) 
    {
        char *endptr;
        long num = std::strtol(argv[i], &endptr, 10);

        if (*endptr != '\0' || num > maxInt || num < 0)
        {
            std::cerr << "Erreur : the value '" << argv[i] << "' is not a valid number" << std::endl;
            return (1);
        }

        numbers.push_back(static_cast<int>(num));
    }
    
    if (this->duplicatesNumbers(numbers)) 
    {
        std::cerr << "Error : the sequence contains duplicates." << std::endl;
        return (1);
    }

    std::cout << "Before : ";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) 
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    std::vector<int> vectorNumbers;
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) 
    {
        vectorNumbers.push_back(*it);
    }

    std::deque<int> dequeNumbers;
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) 
    {
        dequeNumbers.push_back(*it);
    }

    long long startTimeVector = this->getTime();
    this->fordJohnsonSort(vectorNumbers);
    long long endTimeVector = this->getTime();

    std::cout << "After : ";
    for (std::vector<int>::iterator it = vectorNumbers.begin(); it != vectorNumbers.end(); ++it) 
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    long long startTimeDeque = this->getTime();
    this->fordJohnsonSort(dequeNumbers);
    long long endTimeDeque = this->getTime();
    std::cout << "Time to process with std::vector: " << endTimeVector - startTimeVector << " us" << std::endl;

    std::cout << "Time to process with std::deque: " << endTimeDeque - startTimeDeque << " us" << std::endl;

    return (0);
}