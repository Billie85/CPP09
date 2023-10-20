#include "PmergeMe.hpp"
#include <stdlib.h>
int main(int argc, char *argv[]){
	
	//vector part
	std::vector<Unit> arguments;
	for (int i = 1; i < argc; i++)
	{
		int value = std::atoi(argv[i]);
		arguments.push_back(Unit(value));
	}
	VectorSort(arguments);
	for (std::vector<Unit>::iterator i = arguments.begin(); i != arguments.end(); i++)
	{
		std::cout<< *i <<", ";
	}
	std::cout<< std::endl;
	return 0;
}