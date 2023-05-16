#include "BitcoinExchange.hpp"

//対応していないエラー
//アルファベットが入ってきたときのエラーは対応しなくていいと思ってるなぜならfloatの最大値とかにアルファベットが入ってて、対応したら最大値とかが出来なくなる。
//うるう年とかのエラーが対応していない。->必要ないと思ってる。
//floatをfloatに変換する。pdfに指定あり。


//質問内容INT_MIN INT_MAXに対応はしてないけど引数で渡すと上手く行く。
//マイナスが来た時の処理が甘い。not positive number になるべき。
//少数の時もそうでないときもfloatにしてる。なら小数点がある時ない時で分ける必要性ないかも...
//コードが汚い。

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


void inputData(std::ifstream &file, std::map<std::string, float> CsvArray)
{
	if (file.is_open() == false)
	{
		std::cout << "Error: could not open file." << std::endl;
		return;
	}
	int numInt = 0;
	float numfloat = 0;
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
		std::map<std::string, float>::iterator find = CsvArray.find(str);
		if (CheckDecimals(data) == false && find != CsvArray.end())//少数じゃない。&& キーがある場合。
		{
			numInt = atoi(data.c_str());
			float n = CsvArray[str] * numInt;
			if (n <= FLT_MIN || n >= FLT_MAX)
			{
				std::cout << "Error: too large a number. ->"<< n << std::endl;
				continue;
			}
			else
				std::cout << str << " => " << numInt << " = " << n << std::endl;
		}
		if (CheckDecimals(data) == true && find != CsvArray.end())//少数。&& キーがある場合。
		{
			numfloat = atof(data.c_str());
			float d = CsvArray[str] * numfloat;
			if (d <= FLT_MIN || d >= FLT_MAX)
			{
				std::cout << "Error: too large a number. ->"<< d << std::endl;
				continue;
			}
			else
				std::cout << str << " => " << numfloat << " = " << d << std::endl;
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