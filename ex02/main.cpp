#include "PmergeMe.hpp"
#include "mage_insersion.hpp"
#include <stdlib.h>
int main(int argc, char *argv[]){
	
	MyList<Unit> ListArg;

	for (int i = 1; i < argc; i++)
	{
		int value = std::atoi(argv[i]);
		ListArg.push_back(Unit(value));
	}
	FordJohnsonAlgorithm(ListArg);
	for(MyList<Unit>::iterator it = ListArg.begin(); it != ListArg.end(); it++){
		std::cout<< *it <<", ";
	}
	std::cout<< std::endl;
	return 0;
}



//int main(int argc, char *argv[]){
//	
//	std::vector<Unit> ListArg;
//
//	for (int i = 1; i < argc; i++)
//	{
//		int value = std::atoi(argv[i]);
//		ListArg.push_back(Unit(value));
//	}
//	FordJohnsonAlgorithm(ListArg);
//	for(std::vector<Unit>::iterator it = ListArg.begin(); it != ListArg.end(); it++){
//		std::cout<< *it <<", ";
//	}
//	std::cout<< std::endl;
//	return 0;
//}
