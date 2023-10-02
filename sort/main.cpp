#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

// ペアの大きい方を前にする関数
void arrangePairs(std::pair<int, int>& pair) {
    if (pair.first < pair.second) {
        std::swap(pair.first, pair.second);
    }
}

// ペアを作成する関数
std::vector<std::pair<int, int> > createPairs(const std::vector<int>& input) {
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < input.size(); i += 2) {
        if (i + 1 < input.size()) {
            std::pair<int, int> current_pair = std::make_pair(input[i], input[i + 1]);
            arrangePairs(current_pair); // 大きい方を前にする
            pairs.push_back(current_pair);
        } else {
            pairs.push_back(std::make_pair(input[i], input[i]));
        }
    }
    return pairs;
}

// ペアを大きい要素を基準に比較してソートする関数
bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return std::max(a.first, a.second) < std::max(b.first, b.second);
}

// 再帰的にペアをソートする関数
void recursiveSort(std::vector<std::pair<int, int> >& pairs, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        recursiveSort(pairs, left, mid);
        recursiveSort(pairs, mid + 1, right);
        
        // 一時的なベクターを作成してソートし、ソートされたペアをコピー
        std::vector<std::pair<int, int> > temp;
        for (int i = left; i <= right; ++i) {
            temp.push_back(pairs[i]);
        }
        
        std::sort(temp.begin(), temp.end(), comparePairs);
        for (int i = left; i <= right; ++i) {
            pairs[i] = temp[i - left];
        }
    }
}

int main() {
    std::vector<int> input;
    input.push_back(3);
    input.push_back(9);
    input.push_back(2);
    input.push_back(5);
    input.push_back(7);
    input.push_back(8);
    input.push_back(1);
    input.push_back(6);

    // ペアを作成
    std::vector<std::pair<int, int> > pairs = createPairs(input);

    std::cout << "Pairs: ";
    for (size_t i = 0; i < pairs.size(); ++i) {
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
    }
    std::cout << std::endl;

    // 再帰的にペアをソート
    recursiveSort(pairs, 0, pairs.size() - 1);

    std::cout << "Sorted pairs: ";
    for (size_t i = 0; i < pairs.size(); ++i) {
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
    }
    std::cout << std::endl;

    return 0;
}
