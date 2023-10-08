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

void PmergeMe::sort(std::vector<int> &array){
    if (array.size() <= 1){
        std::cout << "to small size" << std::endl;
    }
}
	
///====================check Error part==========================
//引数が重複してるもしくは数字じゃないかどうかを確認してる。
bool checkValueError(const std::string& arg){

     // 文字列が数字のみで構成されていることを確認
    for (size_t i = 0; i < arg.size(); i++) {
        if (!isdigit(arg[i])) {
            std::cout << "Argument Error: Only numbers are allowed." << std::endl;
            return false;
        }
    }
    std::vector<int> vectorArray;

    // 文字列を一文字ずつ処理して重複を確認
    for (size_t i = 0; i < arg.size(); i++) {
        int digit = arg[i] - '0'; // 文字を数字に変換

        // 重複する数字がベクターに存在する場合はエラーメッセージを表示して終了
        for (size_t j = 0; j < vectorArray.size(); j++) {
            if (vectorArray[j] == digit) {
                std::cout << "Argument Error: Duplicate numbers are not allowed." << std::endl;
                return false;
            }
        }
        vectorArray.push_back(digit);
    }
    return true;
}