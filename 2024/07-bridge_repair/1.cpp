#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> stringSplit(string s, string del) {
    vector<string> v;
    string token;
    size_t pos = 0;
    while ((pos = s.find(del)) != string::npos) {
        token = s.substr(0, pos);
        v.push_back(token);
        s.erase(0, pos + del.length());
    }
    v.push_back(s);

    return v;
}


vector<long long int> getResults(vector<long long int> nums, int i = 0, vector<long long int> input = {}) {
    vector<long long int> result;
    if (i == nums.size() - 1) {
        return input;
    } else if (i == 0) {
        result.push_back(nums[i] + nums[i + 1]);
        result.push_back(nums[i] * nums[i + 1]);
        return getResults(nums, i + 1, result);
    } 
    for (auto n : input) {
        result.push_back(n + nums[i + 1]);
        result.push_back(n * nums[i + 1]);
    }
    return getResults(nums, i + 1, result);
}


int main() {
    ifstream file("input");
    string line;
    vector<long long int> nums;
    long long int value = 0;
    long long int res = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            nums.clear();
            value = 0;

            auto v = stringSplit(line, ": ");
            vector<string> numstring = stringSplit(v[1], " ");

            value = stol(v[0]);
            for (auto n : numstring) {
                nums.push_back(stol(n));
            }

            auto results = getResults(nums);
            for (auto r : results) {
                if (r == value) {
                    res += value;
                    break;
                }
            }
        }
    }
    cout << "Result: " << res << endl;
}
