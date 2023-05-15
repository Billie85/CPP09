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

/* template <typename T>
void Sort(T start, int len)
{
	if (len <= 1)
		return ;
	std::vector<int>::iterator mid = start + len / 2;
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
} */

int main(int argc, char * argv[])
{
	/* std::stringstream ss(argv[1]);
	int tmp = 0; */
	std::vector<int> str;
	/* while(ss >> tmp)
	{
		str.push_back(tmp);
	} */
	//std::vector<int>::iterator start = str.begin();
	/* std::cout << "Before: ";
	for (std::vector<int>::iterator it = str.begin(); it != str.end(); it++)
	{
		std::cout << *it << " ";
	} */
	//std::cout << std::endl;
	clock_t  StartTime = clock();
	//std::cout << "Start Time " << StartTime << std::endl;
	int count = 5;
    for (size_t i = 0; i < count; i++)
	{
		std::cout << "hello" << std::endl;
	}
	//Sort(start, str.size());
	clock_t  EndTime = clock();
	//std::cout << "End Time " << EndTime << std::endl;
	double Total = (EndTime - StartTime) / CLOCKS_PER_SEC;
	std::cout << "Total is " << Total << std::endl;
	/* std::cout << "After:  ";
	for (std::vector<int>::iterator it = str.begin(); it != str.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl; */
	std::cout << "Time to process a range of " << str.size() << " elements with std::[..] : " <<  Total  << " us" << std::endl;
}