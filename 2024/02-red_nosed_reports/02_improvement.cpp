#include "iostream"
#include "vector"
#include "string"
#include <cstddef>
#include <cstdlib>
#include <fstream>

using namespace std;


vector<string> splitString(string str, string del) {
    vector<string> result;
    string token;
    size_t pos;

    while((pos = str.find(del)) != string::npos) {
        token = str.substr(0, pos);
        result.push_back(token);
        str = str.erase(0, pos + del.size());
    }

    result.push_back(str);

    return result;
}


int abs(int a, int b) {
    if (a > b){
        return a - b;
    }
    return b -a;
}


bool isSafe(vector<int> lvl, int probs = 0) {
    bool increase = true;

    for (int i = 0; i < lvl.size(); i++) {
        cout << lvl[i] << " ";
    }
    cout << "\n";

    if (probs > 1) {
        return false;
    }

    if (lvl[0] > lvl[1]) {
        increase = false;
    }

    for (int i = 0; i < lvl.size() - 1; i++) {
        if(increase && lvl[i] > lvl[i+1] || !increase && lvl[i] < lvl[i+1]) {
            if (probs > 0) {
                return false;
            }
            cout << lvl[i] << " inc " << lvl[i+1] << "\n";
            swap(lvl[i], lvl[i+1]);
            return isSafe(lvl, probs + 1);
        } else if (abs(lvl[i], lvl[i+1]) < 1 || abs(lvl[i], lvl[i+1]) > 3) {
            if (probs > 0) {
                return false;
            }
            cout << lvl[i] << " abs " << lvl[i+1] << "\n";
            lvl.erase(lvl.begin()+i+1);
            return isSafe(lvl, probs + 1);
        }
    }

    return true;
}


int main() {
    ifstream file ("test");
    string line;
    int result;
    vector<int> lvl;
    int idx = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            lvl.clear();
            vector<string> report = splitString(line, " ");

            for (int i = 0; i < report.size(); i++) {
                lvl.push_back(stoi(report[i]));
            }

            cout << "\n" << idx << endl;


            bool reportSafe = isSafe(lvl);

            cout << "Safe: " << reportSafe << endl;

            if (reportSafe) {
                result++;
            } 
            idx++;
        }
    }

    cout << result << "\n";
}
