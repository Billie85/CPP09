#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <map>

std::map<std::string, std::string> CsvData(std::ifstream &file)
{
	std::map<std::string, std::string> Array;

	if (file.is_open() == false)
		std::cout << "Error: could not open file." << std::endl;

	std::string str;
	std::string data;
	while(getline(file, str, ','))
	{
		getline(file, data, '\n');
		Array[str] = data;
	}
	file.close();
	return(Array);
}

std::map<std::string, std::string> inputData(std::ifstream &file)
{
	std::map<std::string, std::string> Array;

	if (file.is_open() == false)
		std::cout << "Error: could not open file." << std::endl;

	std::string str;
	std::string data;
	while(getline(file, str, '|'))
	{
		getline(file, data, '\n');
		Array[str] = data;
	}
	file.close();
	return(Array);
}

int main(int argc, char *argv[])
{
	std::map<std::string, std::string> InputArray;
	std::map<std::string, std::string> CsvArray;
	std::string str;
	std::ifstream file1(argv[1]);
	std::ifstream file2("data.csv");
	InputArray = inputData(file1);
	CsvArray = CsvData(file2);

	//first secondはstd::pairのメンバーですが、std::mapの要素にstd::pairが使われている。
	//そしてstd::mapの要素にアクセスするにはiteratorが必要
	for (std::map<std::string, std::string>::iterator i = InputArray.begin(); i != InputArray.end(); i++)
{
     std::cout << i->first << "=>" << i->second << std::endl;
}
	return 0;
}