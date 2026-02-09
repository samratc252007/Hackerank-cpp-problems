#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    // Read the size of the array
    if (!(cin >> n)) return 0;

    // Create an array (or vector) of size n
    int arr[n];

    // Read n integers into the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Print the integers in reverse order
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i];
        if (i > 0) {
            cout << " "; // Add a space between numbers
        }
    }

    return 0;
}
