#include "BitcoinExchange.hpp"

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

//実際のデータ。
std::map<std::string, float> CsvData(std::ifstream &file)
{
	std::map<std::string, float> Array;

	if (file.is_open() == false)
	{
		std::cout << "Error: could not open file." << std::endl;
		return Array;
	}
	std::string str;
	std::string data;
	float num = 0;
	while(getline(file, str, ','))
	{
		getline(file, data, '\n');
		num = atof(data.c_str());
		Array[str] = num;
	}
	file.close();
	return(Array);
}

void IntPart(std::string &str, std::map<std::string, float> CsvArray, std::string data)
{
	std::map<std::string, float>::iterator find = CsvArray.find(str);//実際のデータの情報
	if (find != CsvArray.end())//キーがある場合。
		{
			long num = atol(data.c_str());
			float n = CsvArray[str] * num;
			if (num >= 1000)
				std::cout << "Error: too large a number. "<< std::endl;
			else if (num < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else
				std::cout << str << " => " << num << " = " << n << std::endl;
		}
}

void FloatPart(std::string &str, std::map<std::string, float> CsvArray, std::string data)
{
	std::map<std::string, float>::iterator find = CsvArray.find(str);//実際のデータの情報
	if (find != CsvArray.end())//キーがある場合。
		{
			float num = atof(data.c_str());
			float d = CsvArray[str] * num;
			if (num >= 1000)
				std::cout << "Error: too large a number. "<< std::endl;
			else if (num <= 0)
				std::cout << "Error: not a positive number." << std::endl;
			else
				std::cout << str << " => " << num << " = " << d << std::endl;
		}
}

//検索するデータ
void inputData(std::ifstream &file, std::map<std::string, float> CsvArray)
{
	if (file.is_open() == false)
	{
		std::cout << "Error: could not open file." << std::endl;
		return;
	}
	std::string ignoredLine;
	getline(file, ignoredLine);

	std::string str;
	std::string data;
	while(getline(file, str))
	{
		std::stringstream ss;//初期化忘れずに
		ss << str;
		getline(ss, str, '|');
		getline(ss, data, '\n');
		removeSpaces(str);
		if (CheckDecimals(data) == false)//少数じゃない
			IntPart(str, CsvArray, data);
		else
			FloatPart(str, CsvArray, data);
		if (CsvArray.find(str) == CsvArray.end())//キーが無かった場合はここに来る
		{
			std::cout << "Error: bad input => " << str << std::endl;
			continue;
		}
	}
	file.close();
}