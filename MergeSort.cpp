#include<bits/stdc++.h>

using namespace std;

void conquer(int arr[], int si,int mid, int ei) {
    int merged[ei - si + 1];
    int x = 0, i = si, j = mid + 1;

    while (i <= mid && j <= ei) {
        if (arr[i] < arr[j]) {
            merged[x++] = arr[i++];
        }
        else {
            merged[x++] = arr[j++];
        }
    }

    while (i <= mid) {
        merged[x++] = arr[i++];
    }
    while (j <= ei) {
        merged[x++] = arr[j++];
    }

    for (int k = 0, p = si; k < ei - si + 1; k++, p++) {
        arr[p] = merged[k];
    }
}

void divide(int arr[], int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = si + (ei - si) / 2;
    divide(arr, si, mid);
    divide(arr, mid + 1, ei);

    conquer(arr, si, mid, ei);
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

    divide(arr, 0, n - 1);


    cout << "Sorted array is: " << endl;
    for (int i = 0; i < n;i++) {
        cout << arr[i] << endl;
    }
}