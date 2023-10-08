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

// テンプレート関数じゃない関数たち
bool checkValueError(std::string arg);


// ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝テンプレート関数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}



//重複しているかどうかを探す関数。
template <typename array, typename T>
array findFunction(array first, array last, const T& value) {
    while (first != last) {
        if (*first == value) {
            return first;
        }
        ++first;
    }
    return last;
}

template <typename T>
// コンテナに入れてあげる関数
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