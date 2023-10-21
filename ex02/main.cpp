#include "PmergeMe.hpp"
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

//vector part
	//std::vector<Unit> VectorArg;
// for (int i = 1; i < argc; i++)
	// {
	// 	int value = std::atoi(argv[i]);
	// 	VectorArg.push_back(Unit(value));
	// }
//FordJohnsonAlgorithm(VectorArg);
// for (std::vector<Unit>::iterator i = VectorArg.begin(); i != VectorArg.end(); i++)
	// {
	// 	std::cout<< *i <<", ";
	// }