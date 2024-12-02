#include "iostream"
#include "vector"
#include "string"
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>

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

bool isSafe(vector<int> lvl) {
    bool increase = true;


    if (lvl[0] > lvl[1]) {
        increase = false;
    }

    for (int i = 0; i < lvl.size() - 1; i++) {
        if(increase && lvl[i] > lvl[i+1] || !increase && lvl[i] < lvl[i+1]) {
            return false;
        } else if (abs(lvl[i], lvl[i+1]) < 1 || abs(lvl[i], lvl[i+1]) > 3) {
            return false;
        }
    }

    return true;
}


int main() {
    ifstream file ("input");
    string line;
    int result;
    vector<string> report;
    vector<int> lvl;

    if (file.is_open()) {
        while (getline(file, line)) {
            lvl.clear();
            report = splitString(line, " ");

            for (int i = 0; i < report.size(); i++) {
                lvl.push_back(stoi(report[i]));
            }

            bool reportSafe = isSafe(lvl);
            vector<int> fulllvl = lvl;

            if (!reportSafe) {
                for (int i = 0; i < lvl.size(); i++) {
                    lvl.erase(lvl.begin() + i);
                    if (isSafe(lvl)) {
                        reportSafe = true;
                        break;
                    }
                    lvl = fulllvl;
                }
            }
            
            if (reportSafe) {
                result++;
            }
        }
    }

    cout << result << "\n";
}
