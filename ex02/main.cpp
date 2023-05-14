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

template<typename T>
void Sort(T start, int len)
{
	if(len <= 1)
		return;
	std::vector<int>::iterator mid = start + len / 2;
/* 	std::cout << "mid is -> " << *mid << std::endl;
	std::cout << "start is -> " << *start << std::endl;
	std::cout << "len is -> " << len << std::endl; */
	Sort(start, len / 2);
	Sort(mid, len / 2 + len % 2);//奇数の場合もあるから、%2してあげてる。
	for (int i = len / 2; i < len; i++)
	{
		for (int j = i; j && start[j - 1] > start[j]; j--)
		{
			std::swap(start[j - 1], start[j]);
		}
	}
	return ;
}

int main(int argc, char *argv[])
{
	std::stringstream ss(argv[1]);
	std::vector<int> str;
	int tmp = 0;
	while (ss >> tmp)
	{
		str.push_back(tmp);
	}
	std::vector<int>::iterator start = str.begin();
	std::vector<int>::iterator end = str.end();
	Sort(str.begin(), str.size());

	for (auto it = str.begin(); it != str.end(); it++)
	{
		std::cout << *it << " ";
	}
	return 0;
}
