/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::queue;

struct Point {
    int x;
    int y;

    Point() {};
    Point(int x, int y) : x(x), y(y) {}
};

int main() {
    int n, m;
    char matrix[100][100];
    bool visited[100][100] = {false};
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    queue<Point*> bfs_queue;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 'S') {
                bfs_queue.push(new Point(i, j));
                break;
            }
        }
    }

    int last_level_points = 1, curr_level_points = 0;
    int steps = 0;
    while (!bfs_queue.empty()) {
        curr_level_points = 0;
        for (int i = 0; i < last_level_points; i++) {
            Point* curr_point = bfs_queue.front();
            bfs_queue.pop();

            // Check if hits T
            if (matrix[curr_point->x][curr_point->y] == 'T') {
                cout << steps << endl;
                return 0;
            }

            for (int i = 0; i < 4; i++) {
                Point* next_point = new Point(curr_point->x + dirs[i][0], curr_point->y + dirs[i][1]);
                if (next_point->x >= 0 && next_point->x < n && next_point->y >= 0 && next_point->y < m &&
                    !visited[next_point->x][next_point->y] &&
                    matrix[next_point->x][next_point->y] != '#') {
                    bfs_queue.push(next_point);
                    curr_level_points++;
                }
            }

            visited[curr_point->x][curr_point->y] = true;
        }

        last_level_points = curr_level_points;
        steps++;
    }

    return 0;
}
