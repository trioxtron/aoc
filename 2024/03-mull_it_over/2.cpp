#include <fstream>
#include <string>
#include <regex>
#include <iostream>

using namespace std;

int main() {
    ifstream file("input");
    string line;
    regex pattern("mul\\((\\d{1,3}),(\\d{1,3})\\)|do\\(\\)|don't\\(\\)");

    int result = 0;
    bool enabled = true;

    if(file.is_open()) {
        while(getline(file, line)) {
            smatch match;
            while (regex_search(line, match, pattern, regex_constants::match_any)) {
                cout << match[0] << match[1] << match[2] << match[3] << endl;
                if(match[0] == "do()") {
                    enabled = true;
                } else if (match[0] == "don't()") {
                    enabled = false;
                } else {
                    if(enabled) {
                        int a = stoi(match[1]);
                        int b = stoi(match[2]);

                        result += a * b; 
                    } 
                }


                line = match.suffix().str();
            }
        }
    }

    cout << result << endl;
}
