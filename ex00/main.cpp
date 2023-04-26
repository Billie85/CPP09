#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <map>

int main(int argc, char *argv[])
{
	std::map<std::string, std::string> Array;
	Array["date"] = "date,exchange_rate";

	std::ifstream file(argv[1]);
	if (file.is_open() == false)
		std::cout << "Error: could not open file." << std::endl;
	std::string str;
	while(getline(file, str))
	{
		int i = 0;
		while(str[i])
		{
			std::cout << str[i];
			i++;
		}
		std::cout << std::endl;
	}
	file.close();
	return 0;
}