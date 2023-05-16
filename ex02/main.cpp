#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		std::cout << "Error" << std::endl;
	else
	{
		std::stringstream ss(argv[1]);
		VecPart(ss);
		ss.clear();
		ss.seekg(0);
		DeqPart(ss);
	}
	return 0;
}

//3000ソートテスト用
/* int main(void)
{
	system("shuf -i 1-100000 -n 3000 > tmp.txt");
	std::ifstream input("tmp.txt");
	std::stringstream s1;
	s1 << input.rdbuf();
	input.close();
	VecPart(s1);
	s1.clear();
	s1.seekg(0);
	DeqPart(s1);
	input.clear();
	//std::remove("tmp.txt");
	return 0;
} */