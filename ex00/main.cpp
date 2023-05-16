#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	(void)argc;
	std::string InputArray;
	std::map<std::string, float> CsvArray;
	std::ifstream file1(argv[1]);
	std::ifstream file2("data.csv");
	CsvArray = CsvData(file2);
	inputData(file1, CsvArray);
	return 0;
}

