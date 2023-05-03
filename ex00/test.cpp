#include <iostream>
#include <utility>

int main()
{
    std::pair<std::string, int> p = std::make_pair("apple", 5);
    std::cout << "The pair is (" << p.first << ", " << p.second << ")" << std::endl;
    return 0;
}
