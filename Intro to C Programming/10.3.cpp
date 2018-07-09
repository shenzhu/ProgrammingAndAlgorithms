/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::sqrt;
using std::pow;
using std::fixed;
using std::setprecision;

struct Point {
    double x;
    double y;
};

double CalculateDist(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    int n;
    Point points[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double max_dist = 0.0, curr_dist = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            curr_dist = CalculateDist(points[i], points[j]);
            if (curr_dist > max_dist) {
                max_dist = curr_dist;
            }
        }
    }

    cout << fixed << setprecision(4) << max_dist << endl;
    return  0;
}
