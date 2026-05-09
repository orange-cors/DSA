#include <iostream>
#include <cmath>
using namespace std;

int tinh(int n){
    if(n==0) return 1;
    else return 2*tinh(n-1);
}

int tinh2(int n){
    if(n==0) return 1;
    else return 2*tinh2(n-1) + pow(-1,n);
}

int main(){
    int n;
    cin >>n;
    cout <<tinh(n)<<endl;
    cout <<tinh2(n);
}