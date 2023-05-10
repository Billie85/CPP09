#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <cstdlib>
#include <string>
#include <cctype> 
#include <cfloat>
#include <climits>
#include <algorithm>

//対応していないエラー
//アルファベットが入ってきたときのエラーは対応しなくていいと思ってるなぜならdoubleの最大値とかにアルファベットが入ってて、対応したら最大値とかが出来なくなる。
//うるう年とかのエラーが対応していない。->必要ないと思ってる。
//doubleをfloatに変換する。pdfに指定あり。

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
	int numInt = 0;
	double numDouble = 0;
	std::string ignoredLine;
	getline(file, ignoredLine);

	std::string str;
	std::string data;
	while(getline(file, str))
	{
		std::stringstream ss;//常に初期化してあげる。
		ss << str;
		getline(ss, str, '|');
		getline(ss, data, '\n');
		removeSpaces(str);
		std::map<std::string, double>::iterator find = CsvArray.find(str);
		if (CheckDecimals(data) == false && find != CsvArray.end())//少数じゃない。&& キーがある場合。
		{
			numInt = atoi(data.c_str());
			int n = CsvArray[str] * numInt;
			if (n <= INT_MIN || n >= INT_MAX)
			{
				std::cout << "Error: too large a number." << std::endl;
				continue;
			}
			else
				std::cout << str << " => " << CsvArray[str] << " = " << n << std::endl;
		}
		if (CheckDecimals(data) == true && find != CsvArray.end())//少数。&& キーがある場合。
		{
			numDouble = atof(data.c_str());
			double d = CsvArray[str] * numDouble;
			if (d <= DBL_MIN || d >= DBL_MAX)
			{
				std::cout << "Error: too large a number." << std::endl;
				continue;
			}
			else
				std::cout << str << " => " << CsvArray[str] << " = " << d << std::endl;
		}
		if (find == CsvArray.end())
		{
			std::cout << "Error: bad input => " << str << std::endl;
			continue;
		}
		if (FindMinus(data) == false)//マイナスがあったら。
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
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

