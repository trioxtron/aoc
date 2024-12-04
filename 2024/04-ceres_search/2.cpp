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

bool checkWord(vector< vector<char> > grid, int sY, int sX) {
    if (grid[sY][sX] != 'A') {
        return false;
    } else if (sY == grid.size() || sX == grid[0].size() || sX == 0 || sY == 0) {
        return false;
    }

    // Declare the 4 corners
    char tl = (grid[sY-1][sX-1]);
    char tr = (grid[sY-1][sX+1]);
    char bl = (grid[sY+1][sX-1]);
    char br = (grid[sY+1][sX+1]);


    // Check if the corners are valid
    if (tl == 'M' && br == 'S' || tl == 'S' && br == 'M') {
        if (tr == 'M' && bl == 'S' || tr == 'S' && bl == 'M') {
            return true;
        }
    } 

    return false;
}


int main() {
    ifstream file("input");
    string line;
    vector<char> v;
    vector< vector<char> > grid;
    int result = 0;

    // Load your grid from the input
    if (file.is_open()) {
        while (getline(file, line)) {
            v.clear();

            for (int i = 0; i < line.size(); i++) {
                v.push_back(line[i]);
            }

            grid.push_back(v);
        }
    }

    // Loop over the grid
    for (int i = 1; i < grid.size() - 1; i++) {
        for (int j = 1; j < grid[0].size() - 1; j++) {
            if (grid[i][j] == 'A') {
                if (checkWord(grid, i, j)) {
                    result++;
                }
            }
        }
    }

    cout << "Result: " << result << endl;
}
