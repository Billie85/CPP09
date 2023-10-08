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
    //文字列に問題が無かったら、ここにはいる。
   else {
        std::cout << "This arugument is Success" << std::endl;

        // ここから、テンプレート関数を使って、std::vectorにいれていく。
        std::vector<int> ArrayVector = pushToContainer<std::vector<int> >(argv[1]);
        ArrayVector.sort();
        for (size_t i = 0; i < ArrayVector.size(); i++)
        {
           std::cout << ArrayVector[i] << std::endl;
        }
        
    }
    return 0;
}
