#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <utility>
#include <fstream>
#include <sstream>
#include <climits>
#include <string>
#include <vector>
#include <string>
#include <cctype> 
#include <cfloat>
#include <map>
#include <queue>

//参照渡しにすることで関数内で stack に要素を追加したり、削除したりできるようになる。
//呼び出し元の stack も同じように変更される。
int CheckSign(std::queue<int> &stack, int symbol)
{
	int result = 0;
	if (stack.size() < 2)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	else
	{
		int n1 = stack.front();
		stack.pop();
		int n2 = stack.front();
		stack.pop();
		if (symbol == 1)
			result = n1 + n2;
		else if (symbol == 2)
			result = n1 - n2;
		else if (symbol == 3)
			result = n1 / n2;
		else if (symbol == 4)
			result = n1 * n2;
	}
	stack.push(result);
	return (result);
}

int main(int argc, char *argv[])
{
	std::queue<int> stack;
	std::stringstream ss;
	std::string str;

	std::map<std::string, int> sign = {
		{"+", 1}, {"-", 2}, {"/", 3}, {"*", 4}
	};
	ss << argv[1];
	int num = 0;
	int result = 0;
	while(ss >> str)
	{
		num = std::atoi(str.c_str());
		if (num == 0)
		{
			std::map<std::string, int>::iterator it = sign.find(str);
			if (it != sign.end())
			{
				int symbol = it->second;
				result = CheckSign(stack ,symbol);
			}
			else
			{
				std::cout << "Error" << std::endl;
				return 0;
			}
		}
		else
			stack.push(num);
	}
	std::cout << result << std::endl;
	return 0;
}
