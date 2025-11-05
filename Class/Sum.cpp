#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int *myArr(int n)
{
    int *intArr = new int[n];

    for (int i = 0; i < n; i++)
    {
        intArr[i] = rand() % 10 + 1;
        ;
    }
    return intArr;
}

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortArr(int *arr, int n, int isAsc)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((arr[j] * isAsc) > (arr[j + 1] * isAsc))
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int checkSum(int *arr, int n, int s)
{
    int sum = 0;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum<s)
        {
            count++;
        }
        else{
            return count;
        }
    }
    cout << endl;
}

int main()
{
    srand(time(0));

    int n = 10;
    int *intArr = myArr(n);
    printArr(intArr, n);
    int s;
    cout <<"Enter s: ";
    cin >> s;
    sortArr(intArr, n, -1);
    printArr(intArr, n);
    int result = checkSum(intArr, n, s);
    cout << "Number of elements with sum less than " << s << " is: " << result << endl;
}