#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

vector<int> parseInts(string str) {
    stringstream ss(str);
    vector<int> result;
    int tmp;
    char ch;

    // The while loop continues as long as an integer can be successfully extracted
    while (ss >> tmp) {
        result.push_back(tmp);
        // Attempt to extract the next character (the comma).
        // If it fails (e.g., at the end of the string), the loop condition will
        // implicitly break on the next iteration when 'ss >> tmp' fails.
        ss >> ch; 
    }
    return result;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    return 0;
}
