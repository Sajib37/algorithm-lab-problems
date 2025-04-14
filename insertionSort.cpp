#include<iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter how many number you want to enter: ";
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;i++) {
        cout << "Enter " << i + 1 << " Number element : ";
        cin >> a[i];
        cout << endl;
    }

    return 0;

}