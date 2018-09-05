/* Copyright Shen Zhu 2018 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::getchar;

const int maxn = 75;
const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void Search(int now_x, int now_y, int end_x, int end_y,
            int step, int direction, int* min_step,
            int w, int h, char board[maxn + 2][maxn + 2],
            bool visited[maxn + 2][maxn + 2]) {
    if (step > *min_step) return;
    if (now_x == end_x && now_y == end_y) {
        if (*min_step > step) {
            *min_step = step;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int x = now_x + dirs[i][0];
        int y = now_y + dirs[i][1];
        if ((x > -1) && (x < h + 2) && (y > -1) && (y < w + 2) &&
            (((board[x][y] == ' ') && (!visited[x][y])) ||
            ((x == end_x) && (y == end_y) && (board[x][y] == 'X')))) {
            visited[x][y] = true;
            if (direction == i) {
                Search(x, y, end_x, end_y, step, i, min_step,
                w, h, board, visited);
            } else {
                Search(x, y, end_x, end_y, step + 1, i, min_step,
                w, h, board, visited);
            }
            visited[x][y] = false;
        }
    }
}

int main() {
    int board_num = 0;
    int w, h;

    while (cin >> w >> h) {
        if (w == 0 && h == 0) break;

        board_num++;
        cout << "Board #" << board_num << ":" << endl;

        char board[maxn + 2][maxn + 2];
        for (int i = 1; i <= h; i++) {
            getchar();
            for (int j = 1; j <= w; j++) {
                board[i][j] = getchar();
            }
        }

        for (int i = 0; i <= w + 1; i++) {
            board[h + 1][i] = board[0][i] = ' ';
        }
        for (int i = 0; i <= h + 1; i++) {
            board[i][w + 1] = board[i][0] = ' ';
        }

        int begin_x, begin_y, end_x, end_y, count = 0;
        while ((cin >> begin_y >> begin_x >> end_y >> end_x) && (begin_x > 0)) {
            count++;
            int min_step = 100000;
            bool visited[maxn + 2][maxn + 2] = { false };
            Search(begin_x, begin_y, end_x, end_y, 0, -1, &min_step,
                w, h, board, visited);

            if (min_step < 100000) {
                cout << "Pair " << count << ": " << min_step
                      << " segments." << endl;
            } else {
                cout << "Pair " << count << ": impossible." << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
