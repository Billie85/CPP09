#include "PmergeMe.hpp"
#include <stdlib.h>
int main(int argc, char *argv[]){

	std::vector<VectorUnit> arguments;
	for (int i = 1; i < argc; i++)
	{
		int value = std::atoi(argv[i]);
		arguments.push_back(VectorUnit(value));
	}
	VectorSort(arguments);
	for (std::vector<VectorUnit>::iterator i = arguments.begin(); i != arguments.end(); i++)
	{
		std::cout<< *i <<", ";
	}
	std::cout<< std::endl;
	return 0;
}