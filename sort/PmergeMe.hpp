#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <utility>
#include <fstream>
#include <sstream>
#include <climits>
#include <vector>
#include <string>
#include <cctype> 
#include <cfloat>
#include <map>
#include <queue>
#include <ctime>
#include <iomanip>


class PmergeMe {
    public:
    // コンストラクタ：デフォルトコンストラクタ
    PmergeMe(void);

    // コピーコンストラクタ
    PmergeMe(const PmergeMe& other);

    // 代入演算子
    PmergeMe& operator=(const PmergeMe& other);

    // デストラクタ
    ~PmergeMe();
    void sort(std::vector<int> &array);
    private:
};

bool checkValueError(const std::string& arg);
template <typename T>
// istringstreamを使うと、リダイレクション記号（>>）
// で文字列から簡単に数値を取り出すことができます。std::istringstream はデフォルトでスペースを区切り文字として使用し、数値が読み取れる限りスペースで区切って読み取ります
T pushToContainer(const std::string& value) {
    T container;
    std::istringstream array(value);
    
    int num;
    while (array >> num) {
        container.push_back(num);
    }
    return container;
}

#endif


