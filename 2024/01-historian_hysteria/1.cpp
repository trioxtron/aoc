#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<string> stripString(string str, string del) {
    vector<string> result;
    size_t pos = 0;
    string token;

    while((pos = str.find(del)) != string::npos) {
        token = str.substr(0, pos); // Get the current substring
        result.push_back(token); // Push the substring to the result vector
        str = str.erase(0, pos + del.length()); // Delete the current substring so in the next iteration we continue to the next
    }

    // Push the last part of the string to the vector
    result.push_back(str);

    return result;
}

void bubbleSort(vector<int>& list) {
    bool swapped; 

    for (int i = 0; i < list.size() - 1; i++) {
        swapped = false;
        for (int j = 0; j < list.size() - 1 - i; j++) {
            int store = 0;
            if (list[j] > list[j+1]) {
                store = list[j];
                list[j] = list[j+1];
                list[j+1] = store;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int getDiff(int a, int b) {
    if (a > b) {
        return a-b;
    }
    return b-a;
}

int main() {
    ifstream file("input");
    string line;
    vector<string> currentLine;
    vector<int> left;
    vector<int> right;
    int result = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            currentLine = stripString(line, "   ");
            left.push_back(stoi((currentLine[0])));
            right.push_back(stoi((currentLine[1])));
        }
    }

    bubbleSort(left);
    bubbleSort(right);
    for (int i = 0; i < left.size(); i++) {
        result += getDiff(left[i], right[i]);
    }

    cout << result << "\n";
}
