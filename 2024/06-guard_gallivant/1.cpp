#include <fstream>
#include <iostream>
#include <tuple>
#include <vector>
#include <string>

using namespace std;

struct Guard {
    int x, y;
    int dir;
};

tuple<vector<char>, int> stringSplit(string s) {
    vector<char> v;
    int pos = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '^') {
            pos = i;
        }
        v.push_back(s[i]);
    }
    return {v, pos};
}

void moveGuard(Guard &g, int x, int y) {
    g.x += x;
    g.y += y;
}

int runGuard(vector< vector<char> > grid, Guard g) {
    int count = 0;

    // Getting all directions
    // 0: up, 1: right, 2: down, 3: left
    int x[] = {0, 1, 0, -1};
    int y[] = {-1, 0, 1, 0};

    // Current direction
    int dir = 0;

    bool hit = false;

    while (true) {
        // Starting position of current direction
        int nextX = g.x + x[dir], nextY = g.y + y[dir];
        if (grid[g.y][g.x] != 'X') {
            grid[g.y][g.x] = 'X';
            count++;
        }

        //cout << "Next x: " << nextX << " Next y: " << nextY << endl;

        if (nextX >= grid[0].size() || nextY >= grid.size() || nextX < 0 || nextY < 0) {
            break;
        } else if (grid[nextY][nextX] == '#') {
            dir = (dir + 1) % 4;
            continue;
        }

        g.x = nextX;
        g.y = nextY;
        //cout << "Guard x: " << g.x << " Guard y: " << g.y << endl;
        //cout << "Guard x: " << g.x << " Guard y: " << g.y << endl;
    }

    return count;
}


int main() {
    ifstream file("input_test");
    string line;
    vector< vector<char> > grid;
    int idx = 0;
    Guard g;

    if (file.is_open()) {
        while (getline(file, line)) {
            auto [v, pos] = stringSplit(line);
            if (pos != -1) {
                g.x = pos;
                g.y = idx;
                g.dir = 0;
            }
            grid.push_back(v);
            idx++;
        }
    }
    //cout << "Guard x: " << g.x << " Guard y: " << g.y << endl;
    cout << runGuard(grid, g) << endl;
}

