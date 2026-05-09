#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void myArray(int arr[], int n){
    for(int i = 0 ;i <n;i++){
        arr[i] = rand() % 10 + 1;
    }
}

void displayArray(int arr[], int n){
    cout <<"Your Array is: ";
    for(int i = 0 ;i <n;i++){
        cout << arr[i] <<" ";
    }
}

void selectionSort(int arr[], int n){
    cout <<"\nAfter sort by SLTSort!\n";
    for(int i = 0;i<n-1;i++){
        int minIdx = i;
        for(int j = i+1;j<n;j++)
            if(arr[j] < arr[minIdx])
            minIdx = j;
        int tmp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = tmp;
    }
}

int main(){
    srand(time(0));

    int n;
    cin >>n;

    int *arr = new int[n];
    
    myArray(arr, n);
    displayArray(arr, n);

    selectionSort(arr, n);
    displayArray(arr, n);
    
}