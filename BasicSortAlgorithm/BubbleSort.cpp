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

void bubbleSort(int arr[], int n){
    cout <<"\nAfter sort by BBSort!\n";
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

int main(){
    srand(time(0));

    int n;
    cin >>n;

    int *arr = new int[n];
    
    myArray(arr, n);
    displayArray(arr, n);

    bubbleSort(arr, n);
    displayArray(arr, n);
    
}