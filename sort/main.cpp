#include <cstdlib>
#include <iostream>
#include <vector>


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
   else {
        std::cout << "This arugument is Success" << std::endl;
        // ここから、テンプレート関数を使って、std::vectorにいれていく。
        std::vector<int> ArrayVector =
    }
    return 0;
}
