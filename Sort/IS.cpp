#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();

    // Bắt đầu từ phần tử thứ hai (chỉ mục 1)
    for (int i = 1; i < n; ++i) {
        int key = arr[i]; // Lấy phần tử hiện tại để chèn
        int j = i - 1;

        // Di chuyển các phần tử của arr[0..i-1], lớn hơn key,
        // sang một vị trí trước vị trí hiện tại của chúng
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Chèn key vào vị trí đúng của nó
    }
}