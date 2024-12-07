#include <fstream>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>
#include <string>

using namespace std;

struct Point {
    int x;
    int dir;
};

struct Guard {
    int x, y;
    int startX, startY;
    map<int, vector<Point> > path;
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

map<int, vector<Point> > getPath(vector< vector<char> > grid, Guard g) {
    // Getting all directions
    // 0: up, 1: right, 2: down, 3: left
    int x[] = {0, 1, 0, -1};
    int y[] = {-1, 0, 1, 0};

    // Current direction
    int dir = 0;
    while (true) {
        // Starting position of current direction
        int nextX = g.x + x[dir], nextY = g.y + y[dir];
        if (grid[g.y][g.x] != 'X') {
            grid[g.y][g.x] = 'X';
            Point p;
            p.x = g.x;
            p.dir = dir;
            g.path[g.y].push_back(p);
        }

        if (nextX >= grid[0].size() || nextY >= grid.size() || nextX < 0 || nextY < 0) {
            break;
        } else if (grid[nextY][nextX] == '#') {
            dir = (dir + 1) % 4;
            continue;
        }

        g.x = nextX;
        g.y = nextY;
    }
    return g.path;
} 

int checkRun(vector< vector<char> > grid, Guard g) {
    // Getting all directions
    // 0: up, 1: right, 2: down, 3: left
    int x[] = {0, 1, 0, -1};
    int y[] = {-1, 0, 1, 0};

    int gridsize = grid.size() * grid[0].size();
    int steps = 0;

    // Current direction
    int dir = 0;
    while (true) {
        if (steps == gridsize) {
            return 1;
        }
        // Starting position of current direction
        int nextX = g.x + x[dir], nextY = g.y + y[dir];
        if (grid[g.y][g.x] != 'X') {
            grid[g.y][g.x] = 'X';
            Point p;
            p.x = g.x;
            p.dir = dir;
            g.path[g.y].push_back(p);
        }

        if (nextX >= grid[0].size() || nextY >= grid.size() || nextX < 0 || nextY < 0) {
            break;
        } else if (grid[nextY][nextX] == '#') {
            dir = (dir + 1) % 4;
            continue;
        }

        if (g.path.find(nextX) != g.path.end()) {
            for (auto point : g.path[nextY]) {
                if (point.x == nextX && dir == point.dir) {
                    return 1;
                }
            }
        }

        g.x = nextX;
        g.y = nextY;
        steps++;
    }

    return 0;
}


int main() {
    ifstream file("input");
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
                g.startX = pos;
                g.startY = pos;
                g.dir = 0;
            }
            grid.push_back(v);
            idx++;
        }
    }
    //cout << "Guard x: " << g.x << " Guard y: " << g.y << endl;
    map<int, vector<Point> > path = getPath(grid, g);
    int res = 0;
    for (auto [k, v] : path) {
        for (auto point : v) {
            vector< vector<char> > copy = grid;
            copy[k][point.x] = '#';
            res += checkRun(copy, g);
        }
    }
    cout << res << endl;
}

