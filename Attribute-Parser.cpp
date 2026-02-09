#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    cin.ignore(); // Consume the newline after integers

    map<string, string> hrml; // Stores "tag1.tag2~attr" -> "value"
    vector<string> tag_stack;  // Keeps track of the current nesting level

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        // Remove opening/closing brackets and extra quotes for easier parsing
        line.erase(remove(line.begin(), line.end(), '<'), line.end());
        line.erase(remove(line.begin(), line.end(), '>'), line.end());
        line.erase(remove(line.begin(), line.end(), '\"'), line.end());

        if (line[0] == '/') {
            // Closing tag: remove the last tag from the stack
            tag_stack.pop_back();
        } else {
            // Opening tag: parse tag name and attributes
            stringstream ss(line);
            string tag_name, attr, eq, val;
            
            ss >> tag_name;
            tag_stack.push_back(tag_name);

            // Construct the current hierarchical prefix (e.g., tag1.tag2)
            string current_path = "";
            for (size_t j = 0; j < tag_stack.size(); j++) {
                current_path += (j == 0 ? "" : ".") + tag_stack[j];
            }

            // Extract all attribute-value pairs in this line
            while (ss >> attr >> eq >> val) {
                hrml[current_path + "~" + attr] = val;
            }
        }
    }

    // Process Queries
    for (int i = 0; i < q; i++) {
        string query;
        getline(cin, query);
        if (hrml.count(query)) {
            cout << hrml[query] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}
