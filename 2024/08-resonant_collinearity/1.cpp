#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;


struct Point {
    int x;
    int y;
};

bool isFree(Point p, int x, int y, vector<Point> nodes) {
    if (p.x > x || p.y > y || p.x < 0 || p.y < 0) {
        return false;
    }
    for (auto n : nodes) {
        if (n.x == p.x && n.y == p.y) {
            return false;
        }
    }
    return true;
}

Point getDistance(Point p1, Point p2) {
    return {(p2.x - p1.x), (p2.y - p1.y)};
}

Point addPoints(Point p1, Point p2) {
    return {p1.x + p2.x, p1.y + p2.y};
}

Point subPoints(Point p1, Point p2) {
    return {p1.x - p2.x, p1.y - p2.y};
}


int main() {
    ifstream file("input_test");
    string line;
    map<char, vector<Point> > antennas;
    vector<Point> nodes;
    int idx = 0;
    int xSize = 0;
    int res = 0 ;

    if (file.is_open()) {
        while (getline(file, line)) {
            xSize = line.size() - 1;
            for (int i = 0; i < line.size(); i++) {
                char currChar = line[i];
                if (line[i] != '.') {
                    antennas[currChar].push_back({i, idx});
                }
            }
            idx++;
        }
    }

    for (auto a : antennas) {
        for (int i = 0; i < a.second.size() - 1; i++) {
            for (int j = i+1; j < a.second.size(); j++) {
                Point p1 = a.second[i];
                Point p2 = a.second[j];

                Point dist = getDistance(p1, p2);
                Point add = addPoints(p2, dist);
                Point sub = subPoints(p1, dist);

                if (isFree(add, xSize, idx, nodes)) {
                    nodes.push_back(add);
                }
                if (isFree(sub, xSize, idx, nodes)) {
                    nodes.push_back(sub);
                }
            }
        }
    }
    
    for (auto n : nodes) {
        cout << n.x << " " << n.y << endl;
        res += 1;
    }

    cout << "Result: " << res << endl;
}
