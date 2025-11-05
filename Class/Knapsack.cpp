#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    double weight;
    double value;
};

bool cmp(Item a, Item b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

double fractionalKnapsack(Item items[], int n, double W) {
    sort(items, items + n, cmp); 

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (W == 0) break;

        if (items[i].weight <= W) {
            // Lấy hết vật
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Lấy một phần vật
            totalValue += items[i].value * (W / items[i].weight);
            W = 0;
        }
    }
    return totalValue;
}

int main() {
    int n;
    double W;

    cout << "Nhap so luong vat: ";
    cin >> n;
    cout << "Nhap khoi luong toi da cua ba lo: ";
    cin >> W;

    Item* items = new Item[n]; // cấp phát mảng động

    for (int i = 0; i < n; i++) {
        cout << "Vat " << i + 1 << " (khoi luong, gia tri): ";
        cin >> items[i].weight >> items[i].value;
    }

    double result = fractionalKnapsack(items, n, W);
    cout << "Gia tri toi da co the dat duoc: " << result << endl;

    delete[] items; // giải phóng bộ nhớ
    return 0;
}
