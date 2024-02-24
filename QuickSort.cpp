#include<bits/stdc++.h>

using namespace std;

int partition(int arr[], int low, int high) {
    int i = low - 1;
    int pivot = arr[high];

    for (int j = low; j < high ;j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    }

    i++;
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;

}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
       int pivotIdx = partition(arr, low, high);

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