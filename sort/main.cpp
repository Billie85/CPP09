#include <iostream>
#include <vector>
#include <cstdlib>

int main(int argc, char *argv[]) {
    // コマンドライン引数の数が正確に1つでない場合はエラーメッセージを表示して終了
    if (argc != 2) {
        std::cout << "Argument Error: Please provide one argument." << std::endl;
        return 1;
    }
    std::string arg = argv[1];

    // 文字列が数字のみで構成されていることを確認
    for (size_t i = 0; i < arg.size(); i++) {
        if (!isdigit(arg[i])) {
            std::cout << "Argument Error: Only numbers are allowed." << std::endl;
            return 1;
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
                return 1;
            }
        }
        vectorArray.push_back(digit);
    }
    int result = vectorArray.back();
    std::cout << "double: " << result * 2 << std::endl;


    return 0;
}
