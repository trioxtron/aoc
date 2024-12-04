#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<char> stringSplit(string s) {
    vector<char> v;
    for (int i = 0; i < s.size(); i++) {
        v.push_back(s[i]);
    }
    return v;
}

int checkWord(vector< vector<char> > grid, string word, int sX, int sY) {
    int count = 0;
    if (grid[sX][sY] != word[0]) {
        return false;
    }

    // Getting all directions
    // 0: top-left, 1: top, 2: top-right, 3: right, 4: bottom-right, 5: bottom, 6: bottom-left, 7: left
    int x[] = {-1, 0, 1, 1, 1, 0, -1, -1 };
    int y[] = {-1, -1, -1, 0, 1, 1, 1, 0 };

    for (int dir = 0; dir < 8; dir++) {
        // Starting position of current direction
        int currX = sX + x[dir], currY = sY + y[dir];
        int i;

        for(i = 1; i < word.size(); i++) {
            if (currX >= grid[0].size() || currY >= grid.size() || currX < 0 || currY < 0) {
                break;
            }

            if (grid[currX][currY] != word[i]) {
                break;
            }

            // Move one step in the direction we are checking
            currX += x[dir];
            currY += y[dir];
        }

        if (i == word.size()) {
            count++;
        }
    }

    return count;
}


int main() {
    ifstream file("input");
    string line;
    vector<char> v;
    vector< vector<char> > grid;
    int result = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            v.clear();

            for (int i = 0; i < line.size(); i++) {
                v.push_back(line[i]);
            }

            grid.push_back(v);
        }
    }

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 'X') {
                int appeared = checkWord(grid, "XMAS", i, j);
                if (appeared > 0) {
                    cout << "X";
                    result += appeared;
                }
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }

    cout << "Result: " << result << endl;
}
