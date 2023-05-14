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

int main(int argc, char * argv[])
{
	std::vector<int> str = {1, 5 ,7, 8};
	/* for (int i = 0; i < str.size(); i++)
	{
		std::cout << str[i] << std::endl;
	} */
	std::vector<int>::iterator it;
	for (it = str.begin(); it != str.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}