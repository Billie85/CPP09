#include "PmergeMe.hpp"

//constructor
PmergeMe::PmergeMe(void){ return; }

PmergeMe::PmergeMe(const PmergeMe& other){ *this = other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other){
     // 自己代入チェック
    if (this == &other) {
        return *this;
    }
     return *this;
}

PmergeMe::~PmergeMe(void) { return; }

///====================sort part==========================

void PmergeMe::sort(std::vector<int> &vectorArray) {
    if (vectorArray.size() <= 1) {
        std::cout << "size is " << vectorArray.size() << std::endl;
        std::cout << "too small size" << std::endl;
        return;
    }

    int remainder = 0;
    // 奇数がどうかを見る。奇数だった場合vectorから最後の要素を取り出す。
    if (vectorArray.size() % 2 != 0) {
        remainder = vectorArray.back();
        vectorArray.pop_back(); // ベクターから最後の要素を削除する。
    }

    // ここからペアにしてあげるけど、基本的に左側が大きくと右側が小さいようにしたいから、
    // 一個ずつ見てあげて、もしも左が右より小さかった時はmake_pairを使って大きい方を左にして小さい方を右に入れてペアにしていく。
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < vectorArray.size(); i += 2) {
        if (vectorArray[i] < vectorArray[i + 1]) {
            std::cout << "top" << std::make_pair(vectorArray[i + 1], vectorArray[i]) << std::endl;
        } else {
            std::cout << "bottom " << std::make_pair(vectorArray[i], vectorArray[i + 1]) << std::endl;
        }
    }
}


///====================check Error part==========================
//引数が重複してるもしくは数字じゃないかどうかを確認してる。（引数のエラー確認）

bool checkValueError(std::string arg) {
    std::istringstream stream(arg);
    std::string array;
    std::vector<int> vectorArray;
    
    while (stream >> array) {
        if (array.find_first_not_of("0123456789") != std::string::npos) {
            std::cout << "Argument Error : Only Numbers" << std::endl;
            return false;
        }
        int num = std::atoi(array.c_str());
        
        // findFunctionを使用して重複を検出
        if (findFunction(vectorArray.begin(), vectorArray.end(), num) != vectorArray.end()) {
            std::cout << "Argument Error : Same value" << std::endl;
            return false;
        }
        vectorArray.push_back(num);
    }
    return true;
}
