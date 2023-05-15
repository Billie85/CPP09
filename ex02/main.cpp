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
#include <ctime>
#include <iomanip>

	template <typename T>
void Sort(T start, int len)
{
	if (len <= 1)
		return ;
	T mid = start + len / 2;
	Sort(start, len / 2);
	Sort(mid, len / 2 + len % 2);
	for (int i = len / 2; i < len; i++)
	{
		for (int j = i; j && start[j - 1] > start[j]; j--)
		{
			std::swap(start[j - 1], start[j]);
		}
	}
	return ;
}

	template <typename T>
void print(T start, T end, std::string str)
{
	if (str == "Before")
	{
		std::cout << "Before: ";
		for (T it = start; it != end; it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	else if (str == "After")
	{
		std::cout << "After:  ";
		for (T it = start; it != end; it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
}

void VecPart(std::stringstream &ss)
{
	int tmp = 0;
	std::vector<int> VecStr;
	while(ss >> tmp)
	{
		VecStr.push_back(tmp);
	}
	std::vector<int>::iterator start = VecStr.begin();
	print(VecStr.begin(), VecStr.end(), "Before");
	clock_t  STimeVec = clock();
	Sort(start, VecStr.size());
	clock_t  ETimeVec = clock();
	double Total = (double)(ETimeVec - STimeVec) / CLOCKS_PER_SEC;//戻り値が整数だからdoubleにしてあげる必要がある。
	print(VecStr.begin(), VecStr.end(), "After");
	std::cout << "Time to process a range of " << VecStr.size() << " elements with std::[..] : " << std::fixed << std::setprecision(6) << Total << " us" << std::endl;
}

void DeqPart(std::stringstream &ss)
{
	int tmp = 0;
	std::deque<int> VecStr;
	while(ss >> tmp)
	{
		VecStr.push_back(tmp);
	}
	std::deque<int>::iterator start = VecStr.begin();
	//print(VecStr.begin(), VecStr.end(), "Before");
	clock_t  STimeVec = clock();
	Sort(start, VecStr.size());
	clock_t  ETimeVec = clock();
	double Total = (double)(ETimeVec - STimeVec) / CLOCKS_PER_SEC;//戻り値が整数だからdoubleにしてあげる必要がある。
	//print(VecStr.begin(), VecStr.end(), "After");
	std::cout << "Time to process a range of " << VecStr.size() << " elements with std::[..] : " << std::fixed << std::setprecision(6) << Total << " us" << std::endl;
}

int main(int argc, char * argv[])
{
	std::stringstream ss(argv[1]);
	VecPart(ss);
	DeqPart(ss);
	return 0;
}

//疑問に思ってること、Deqの部分で出力をすると表示されない。
//`shuf -i 1-100000 -n 3000 | tr "\n" " "`　に対応できてない。SPの問題かも。
//マイナスのエラー処理未対応