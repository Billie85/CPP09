#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <cstdlib>
#include <string>
#include <algorithm>

void removeSpaces(std::string& str)
{
    std::string::iterator position = std::remove(str.begin(), str.end(), ' ');
    str.erase(position, str.end());
}

bool FindMinus(std::string &str)
{
	std::string::iterator position = std::find(str.begin(), str.end(), '-');
	if (position != str.end())
	{
		return false;//0
	}
	else
		return true;//1
}

bool CheckDecimals(std::string &str)
{
		std::string::iterator position = std::find(str.begin(), str.end(), '.');
		if (position != str.end())
		{
			return true;
		}
		else
			return false;
}

std::map<std::string, double> CsvData(std::ifstream &file)
{
	std::map<std::string, double> Array;

	if (file.is_open() == false)
	{
		std::cout << "Error: could not open file." << std::endl;
		return Array;
	}

	std::string str;
	std::string data;
	double num = 0;
	while(getline(file, str, ','))
	{
		getline(file, data, '\n');
		num = atof(data.c_str());
		Array[str] = num;
	}
	file.close();
	return(Array);
}

void inputData(std::ifstream &file, std::map<std::string, double> CsvArray)
{
	if (file.is_open() == false)
	{
		std::cout << "Error: could not open file." << std::endl;
		return;
	}

	std::string str;
	std::string data;
	double num = 0;
	while(getline(file, str, '|'))
	{
		getline(file, data, '\n');
		removeSpaces(str);
		if (FindMinus(data) == false)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		std::map<std::string, double>::iterator find = CsvArray.find(str);
		if (find != CsvArray.end())
		{
			num = atof(data.c_str());
			std::cout << str << " => " << CsvArray[str] << " = " << CsvArray[str] * num << std::endl;
		}
		else
		{
			std::cout << "Error: bad input => " << str << std::endl;
			//continue;
		}
	}
	file.close();
}

int main(int argc, char *argv[])
{
	std::string InputArray;
	std::map<std::string, double> CsvArray;
	std::ifstream file1(argv[1]);
	std::ifstream file2("data.csv");
	CsvArray = CsvData(file2);
	inputData(file1, CsvArray);
	return 0;
}

