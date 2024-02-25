#include<bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int n) {
    int maxValue = arr[0];

    for (int i = 1;i < n;i++) {
        maxValue = max(maxValue, arr[i]);
    }

    int countArr[maxValue + 1]={0};

    for (int i = 0; i < n;i++) {
        ++countArr[arr[i]];
    }
    for (int i = 1; i <= maxValue; i++) {
        countArr[i] += countArr[i - 1];
    }
    int sortedArr[n];

    for (int i = n - 1;i >= 0;i--) {
        sortedArr[--countArr[arr[i]]] = arr[i];
    }
    for (int i = 0; i < n;i++) {
        arr[i] = sortedArr[i];
    }
}
int main()
{
    int n;
    cout << "Enter the length of array: ";
    cin >> n;
    int arr[n];

    cout << endl << "Enter your numbers: " << endl;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    } 

    cout << "Sorted array is: " << endl;
    quickSort(arr, n);

    int i = 0;
    while (i < n) {
        cout << arr[i] << endl;
        i++;
    }
}