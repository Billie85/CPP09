#include "PmergeMe.hpp"
#include "mage_insersion.hpp"


int main(int argc, char *argv[]){

	for (int i = 1; i < argc; i++)
	{
		if(argv[i][0] == '-' || argv[i][0] == '"' || !std::isdigit(argv[i][0]))
		{
			std::cout << "error" << std::endl;
			return 1;
		}
	}
		//list part
	// std::cout << "List Before: ";
	// for (int i = 1; i < argc; i++)
	// {
	// 	std::cout << argv[i] << " ";
	// }
	// std::cout << std::endl;

//	std::cout << "List After:  ";
 	MyList<Unit> ListArg;

	for (int i = 1; i < argc; i++)
	{
		int value = std::atoi(argv[i]);
		ListArg.push_back(Unit(value));
	}
	//clock_t ListStartTime = clock();
	FordJohnsonAlgorithm(ListArg);
	//clock_t ListEndTime = clock();

	for(MyList<Unit>::iterator it = ListArg.begin(); it != ListArg.end(); it++){
		std::cout<< *it <<" ";
	}
	std::cout << std::endl;

	//double ListTime = (//double)(ListEndTime - ListStartTime) / (CLOCKS_PER_SEC / 1000.0); // ミリ秒に変換
	//std::cout << "Time to process a range of " << Count(ListArg) << " elements with std::[..] : " << ListTime << "us" << std::endl;
	//std::cout<< std::endl;

//vector part
	// std::cout << "Vector Before: ";
	// for (int i = 1; i < argc; i++)
	// {
	// 	std::cout << argv[i] << " ";
	// }
	// std::cout << std::endl;

//	std::cout << "Vector After:  ";
// 	std::vector<Unit> VectorArg;
//
//	for (int i = 1; i < argc; i++)
//	{
//		int value = std::atoi(argv[i]);
//		VectorArg.push_back(Unit(value));
//	}
//	//clock_t VectorStartTime = clock();
//	FordJohnsonAlgorithm(VectorArg);
//	//clock_t VectorEndTime = clock();
//
//
//	for(std::vector<Unit>::iterator it = VectorArg.begin(); it != VectorArg.end(); it++){
//		std::cout<< *it <<" ";
//	}
//
//	std::cout << std::endl;
	//double VectorTime = (//double)(VectorEndTime - VectorStartTime) / (CLOCKS_PER_SEC / 1000.0); // ミリ秒に変換
	//std::cout << "Time to process a range of " << Count(ListArg) << " elements with std::[..] : " << VectorTime << "us" << std::endl;
	//std::cout<< std::endl;
	return 0;
}