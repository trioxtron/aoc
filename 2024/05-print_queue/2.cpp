#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <vector>
#include <string>

using namespace std;

vector<string> splitString(string str, string del) {
    vector<string> result;
    string token;
    int pos = 0;

    while ((pos = str.find(del)) != string::npos) {
        token = str.substr(0, pos);
        result.push_back(token);
        str.erase(0, pos + del.length());
    }

    result.push_back(str);

    return result;
}


int isCorrect(vector<string> update, map<string, vector<string> > rules, int idx = 0) {

    for (int i = 0; i < update.size() - 1; i++) {
        if (rules.find(update[i]) == rules.end()) {
            return 0;
        }
        int j = i+1;
        for (int j = i+1; j < update.size(); j++) {
            vector<string> values = rules[update[j]];
            for (int k = 0; k < values.size(); k++) {
                if (values[k] == update[i]) {
                    swap(update[i], update[j]);
                    return isCorrect(update, rules, idx+1);
                }
            }
        }
    }
    if (idx == 0) {
        return 0;
    }
    return stoi(update[(update.size() - 1) / 2]);
} 

void printMap(map<string, vector<string> > rules) {
    for(auto it = rules.cbegin(); it != rules.cend(); ++it) {
        cout << it->first << ": ";
        for (int i = 0; i < it->second.size(); i++) {
            cout << it->second[i] << ", ";
        }
        cout << endl;
        cout << endl;
    }
}

int main() {
    ifstream file("input");
    string line;
    map<string, vector<string> > rules;
    vector<string> update;
    bool isUpdate = false;
    int result = 0;
    int idx = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line == "") {
                isUpdate = true;
                continue;
            }

            if (!isUpdate) {
                vector<string> rule = splitString(line, "|");
                vector<string> values;
                if (rules.find(rule[0]) != rules.end()) {
                    values = rules[rule[0]];
                }
                values.push_back(rule[1]);

                rules[rule[0]] = values;
                continue;
            }

            update = splitString(line, ",");

            int middle = isCorrect(update, rules);
            cout << middle << endl;

            result += middle;
            if (middle != 0) {
                idx++;
            }
        }

        // printMap(rules);

        cout << result << " " << idx << endl;
    } 
}
