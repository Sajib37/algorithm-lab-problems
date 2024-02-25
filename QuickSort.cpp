#include<bits/stdc++.h>

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int j = low - 1;
    for (int i = low; i < high;i++) {
        if (arr[i] < pivot) {
            j++;
            swap(arr[j], arr[i]);
        }
    }

    j++;
    swap(arr[j], arr[high]);

    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int  pivotIdx = partition(arr, low, high);

        quickSort(arr, low, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, high);
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

    quickSort(arr, 0, n - 1);


    cout << "Sorted array is: " << endl;
    for (int i = 0; i < n;i++) {
        cout << arr[i] << endl;
    }
}