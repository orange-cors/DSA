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

void insertionSort(int arr[], int n){
    cout <<"\nAfter sort by ISTSort!\n";
    for(int i = 1;i<n;i++){
        int key = arr[i];
        int j = i - 1;
        while(j>=0&&arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }arr[j+1] = key;
    }
}

int main(){
    srand(time(0));

    int n;
    cin >>n;

    int *arr = new int[n];
    
    myArray(arr, n);
    displayArray(arr, n);

    insertionSort(arr, n);
    displayArray(arr, n);
    
}