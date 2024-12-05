#include <iostream>
#include <fstream>
#include <map>
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


bool isCorrect(vector<string> update, map<string, vector<string> > rules) {
    for (int i = 0; i < update.size() - 1; i++) {
        if (rules.find(update[i]) == rules.end()) {
            return false;
        }
        for (int j = i+1; j < update.size() - 1; j++) {
            if (rules.find(update[j]) == rules.end()) {
                return false;
            }
            vector<string> values = rules[update[j]];
            for (int k = 0; k < values.size(); k++) {
                if (values[k] == update[i]) {
                    return false;
                }
            }
        }
    }
    return true;
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
            int middle = stoi(update[(update.size() - 1) / 2]);


            if (isCorrect(update, rules)) {
                idx++;
                result += middle;
            }

        }


        // printMap(rules);

        cout << result << " " << idx << endl;
    } 
}
