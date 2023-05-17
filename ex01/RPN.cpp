#include "RPN.hpp"

//参照渡しにすることで関数内で stack に要素を追加したり、削除したりできるようになる。
//呼び出し元の stack も同じように変更される。
int CheckSign(std::stack<int> &stack, std::string str)
{
	int result = 0;
	if (stack.size() < 2)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	else
	{
		int n1 = stack.top();
		stack.pop();
		int n2 = stack.top();
		stack.pop();
		if (str == "+")
			result = n1 + n2;
		else if (str == "-")
			result = n2 - n1;
		else if (str == "/")
			result = n2 / n1;
		else if (str == "*")
			result = n1 * n2;
		else
		{
			std::cout << "Error" << std::endl;
			exit (1);
		}
	}
	stack.push(result);
	return (result);
}