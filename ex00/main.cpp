#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	else
	{
		std::map<std::string, float> CsvArray;
		std::ifstream file1(argv[1]);
		std::ifstream file2("data.csv");
		CsvArray = CsvData(file2);
		inputData(file1, CsvArray);
	}
	return 0;
}

