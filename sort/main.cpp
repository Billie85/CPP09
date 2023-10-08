#include "PmergeMe.hpp"


int main(int argc, char *argv[]) {
    // コマンドライン引数の数が正確に1つでない場合はエラーメッセージを表示して終了
    if (argc != 2) {
        std::cout << "Argument Error: Please provide one argument." << std::endl;
        return 1;
    }
    std::string arg = argv[1];
    if (checkValueError(argv[1]) == false){
        std:: cout << "This arugument is Failed" << std::endl;
    }
    //引数に問題が無かったら、ここにはいる。
   else {
        // ここから、テンプレート関数を使って、std::vectorにいれていく。
        PmergeMe pmergeMe;
        std::vector<int> ArrayVector = pushToContainer<std::vector<int> >(argv[1]);
        pmergeMe.sort(ArrayVector);
    }
    return 0;
}
