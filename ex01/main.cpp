#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	std::stack<int> stack;
	std::stringstream ss;
	std::string str;
	ss << argv[1];
	int num = 0;
	int result = 0;
	while(ss >> str)
	{
		if (str == "+" || str == "-" || str == "*" || str == "/")
		{
			result = CheckSign(stack , str);
		}
		else if (str.length() == 1 && str[0] <= '9' && str[0] >= '0')
		{
			num = std::atoi(str.c_str());
			stack.push(num);
		}
		else
		{
			std::cout << "Error" << std::endl;
			return 0;
		}
	}
	if (num != 0 && stack.size() >= 2)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	else
		std::cout << result << std::endl;
	return 0;
}
