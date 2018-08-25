/* Copyright Shen Zhu 2018 */

#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::sort;

struct Point {
    int x;
    int y;
    bool is_maxima = false;

    bool operator<(const Point& rhs) {
        if (x == rhs.x) return y < rhs.y;
        return x < rhs.x;
    }
};

int main() {
    int n;
    Point points[100];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points, points + n);

    int max_y = -1;
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (points[i].y > max_y) {
            points[i].is_maxima = true;
            max_y = points[i].y;
            count++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (points[i].is_maxima) {
            count--;
            cout << "(" << points[i].x << "," << points[i].y << ")";
            if (count != 0) cout << ",";
        }
    }

    return 0;
}
