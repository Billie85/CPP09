#include <iostream>
#include <vector>
#include <algorithm>

// 二分探索を使用してソートされたベクトルに要素を挿入する関数
template <typename T>
void binaryInsert(std::vector<T>& vec, const T& element) {
    typename std::vector<T>::iterator it = std::lower_bound(vec.begin(), vec.end(), element);
    vec.insert(it, element);
}

// マージ挿入ソートアルゴリズムを実装する関数
template <typename T>
void mergeInsertionSort(std::vector<T>& arr) {
    int n = arr.size();
    
    if (n <= 1)
        return;

    std::vector<T> largerElements;  // 大きな要素を保持するベクトル
    std::vector<T> smallerElements; // 小さな要素を保持するベクトル
    
    // ステップ1: 要素をペアにグループ化し、大きな要素を見つける
    for (int i = 0; i < n - 1; i += 2) {
        if (arr[i] < arr[i + 1]) {
            smallerElements.push_back(arr[i]);
            largerElements.push_back(arr[i + 1]);
        } else {
            smallerElements.push_back(arr[i + 1]);
            largerElements.push_back(arr[i]);
        }
    }

    // ステップ3: 大きな要素を再帰的にソート
    mergeInsertionSort(largerElements);

    // ステップ4: 最小の要素とペアにされた要素の先頭に挿入
    arr.clear();
    arr.push_back(smallerElements[0]);
    
    // ステップ5: 特別に選ばれた挿入順序を使用して残りの要素を挿入
    for (int i = 1; i < n - 1; ++i) {
        if (i % 2 == 1)
            binaryInsert(arr, largerElements[i / 2]);
        else
            arr.push_back(smallerElements[i / 2]);
    }
}

int main() {
    std::vector<int> arr = {5, 3, 7, 1, 9, 2, 8, 4, 6};
    
    mergeInsertionSort(arr);

    std::cout << "ソートされた配列: ";
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
