#include <iostream>
#include <ctime>

int main() {
    std::clock_t start = std::clock();
	std::cout << "Start Time " << start << std::endl;
	int count = 5;
    for (size_t i = 0; i < count; i++)
	{
		std::cout << "hello" << std::endl;
	}
    std::clock_t end = std::clock();
	std::cout << "End Time " << end << std::endl;
    double elapsed_time = (end - start) / static_cast<double>(CLOCKS_PER_SEC);
    std::cout << "経過時間: " << elapsed_time << "秒" << std::endl;
    return 0;
}
