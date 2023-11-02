#include "BitcoinExchange.hpp"

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
    std::map<std::string, float>::iterator find = CsvArray.upper_bound(str);
    if (find == CsvArray.begin()) {
        std::cout << "Error: no data." << std::endl;
		return ;
    }
    else {
        --find;
    }
    long num = atol(data.c_str());
    float n = find->second * num;
    if (num >= 1000)
        std::cout << "Error: too large a number." << std::endl;
    else if (num < 0)
        std::cout << "Error: not a positive number." << std::endl;
    else
        std::cout << str<< " ("<< find->first <<")" << " => " << num << " = " << n << std::endl;
}

void FloatPart(std::string &str, std::map<std::string, float> CsvArray, std::string data)
{
    std::map<std::string, float>::iterator find = CsvArray.upper_bound(str);
    if (find == CsvArray.begin()) {
		if (find->first != str)
        	std::cout << "Error: no data." << std::endl;
		return ;
    }
    else {
        --find;
    }
    float num = atof(data.c_str());
    float n = find->second * num;
    if (num >= 1000)
        std::cout << "Error: too large a number." << std::endl;
    else if (num < 0)
        std::cout << "Error: not a positive number." << std::endl;
    else
        std::cout << str<< " ("<< find->first <<")" << " => " << num << " = " << n << std::endl;
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
		std::string buff1;
		std::string buff2;
		ss << str;
		ss >> str >> buff1 >> data >> buff2;
		if (buff1 != "|" || buff2.length()){
			std::cout << "Error: bad input => " << str << std::endl;
			continue;	
		}
		if (CheckDecimals(data) == false)//少数じゃない
			IntPart(str, CsvArray, data);
		else
			FloatPart(str, CsvArray, data);
	}
	file.close();
}