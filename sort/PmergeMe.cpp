#include "PmergeMe.hpp"
	
	template <typename T>
void Sort(T start, int len)
{
	if (len <= 1)
		return ;
	T mid = start + len / 2;//真ん中を探してあげる。
	Sort(start, len / 2);//前の部分をここで完全にソートする魔法の再帰
	Sort(mid, len / 2 + len % 2);//後ろの部分をここで完全にソートする魔法の再帰,　奇数だった場合後ろの方が数が大きくなる。

	//ここに入るときは　"7 8 9 10    1 2 3 4 5"　前と後ろが完全にソートされてる状態でfor文の中に入ってあげる。 
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
	clock_t  STimeVec = clock();//時間を計る必要があるから。sort関数の前と後ろに入れてあげてる。
	Sort(start, VecStr.size());
	clock_t  ETimeVec = clock();
	double Total = (double)(ETimeVec - STimeVec) / CLOCKS_PER_SEC;//戻り値が整数だからdoubleにしてあげる必要がある。
	//print(VecStr.begin(), VecStr.end(), "After");
	std::cout << "Time to process a range of " << VecStr.size() << " elements with std::[..] : " << std::fixed << std::setprecision(6) << Total << " us" << std::endl;
}
