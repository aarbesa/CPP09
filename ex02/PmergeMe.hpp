#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <iomanip>
# include <deque>
# include <ctime>
# include <cstdlib>
# include <limits>
# ifndef CLASS
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

class PmergeMe
{
    private:
		void isSorted(std::deque<int>& deq) const;



		void insertionSort(std::vector<int> & vec);
		void insertionSort(std::deque<int> & deq);


		std::vector<int> sortRight(const std::vector<std::pair<int, int> > & pairs);
		std::deque<int> sortRight(const std::deque<std::pair<int, int> > & pairs);


		static bool pairComparator(const std::pair<int, int> & a, const std::pair<int, int> & b);

		void fordJohnsonSort(std::vector<int>& vec);
		void fordJohnsonSort(std::deque<int>& deq);

		double getTime();

		bool duplicatesNumbers(const std::vector<int> & vec) const;


    public:
	
        PmergeMe();
        PmergeMe(const PmergeMe&);
        PmergeMe& operator= (const PmergeMe&);
        ~PmergeMe();
		
		int	execution(int argc, char *argv[]);

};

#endif
