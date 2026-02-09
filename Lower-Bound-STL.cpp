#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int val;
        cin >> val;

        // lower_bound returns an iterator to the first element >= val
        auto it = lower_bound(v.begin(), v.end(), val);

        // Check if the element found is actually the value we searched for
        if (*it == val) {
            // iterator - vector.begin() gives the 0-based index
            cout << "Yes " << (it - v.begin() + 1) << endl;
        } else {
            // If not found, it points to the smallest element > val
            cout << "No " << (it - v.begin() + 1) << endl;
        }
    }

    return 0;
}
