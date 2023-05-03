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

//やるべきことリスト
//現在上手く行ってない場所として、もしもパイプとかがないとき次のパイプのある処理が認識されない。
//int と double	の時の処理が必要。<-ここを完成させる。
//同じ日付が2つ以上あった場合対応させるべきなのか？

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
	int numInt = 0;
	double numDouble = 0;
	while(getline(file, str, '|'))
	{
		getline(file, data, '\n');
		removeSpaces(str);
		if (FindMinus(data) == false)//マイナスがあったら。
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		std::map<std::string, double>::iterator find = CsvArray.find(str);
		if (CheckDecimals(data) == false && find != CsvArray.end())//少数じゃない。&& キーがなかった場合
		{
			numInt = atoi(data.c_str());
			std::cout << str << " => " << CsvArray[str] << " = " << CsvArray[str] * numInt << std::endl;
		}
		if (CheckDecimals(data) == true && find != CsvArray.end())//少数。&& キーがなかった場合
		{
			numDouble = atof(data.c_str());
			std::cout << str << " => " << CsvArray[str] << " = " << CsvArray[str] * numDouble << std::endl;
		}
		if (find == CsvArray.end())
		{
			std::cout << "Error: bad input => " << str << std::endl;
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

