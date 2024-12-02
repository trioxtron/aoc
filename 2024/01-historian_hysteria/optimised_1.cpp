#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
    int lefti, righti;

    if (file.is_open()) {
        while (file >> lefti >> righti) {
            left.push_back(lefti);
            right.push_back(righti);
        }
    }

    bubbleSort(left);
    bubbleSort(right);
    for (int i = 0; i < left.size(); i++) {
        result += getDiff(left[i], right[i]);
    }

    cout << result << "\n";
}
