#include <fstream>
#include <string>
#include <regex>
#include <iostream>

using namespace std;

int main() {
    ifstream file("input_test");
    string line;
    regex pattern("mul\\((\\d{1,3}),(\\d{1,3})\\)");

    int result = 0;

    if(file.is_open()) {
        while(getline(file, line)) {
            smatch match;
            while (regex_search(line, match, pattern, regex_constants::match_any)) {
                int a = stoi(match[1]);
                int b = stoi(match[2]);

                result += a*b;

                line = match.suffix().str();
            }
        }
    }

    cout << result << endl;
}
