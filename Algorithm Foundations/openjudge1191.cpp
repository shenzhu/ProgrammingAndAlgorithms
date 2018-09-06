/* Copyright Shen Zhu 2018 */

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::min;
using std::sqrt;
using std::memset;

int CalSum(int x1, int y1, int x2, int y2, int sum[9][9]) {
    return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2]
        + sum[x1 - 1][y1 - 1];
}

int RecurSearch(int n, int x1, int y1, int x2, int y2,
    int memo[15][9][9][9][9], int sum[9][9]) {
    if (memo[n][x1][y1][x2][y2] != -1) {
        return memo[n][x1][y1][x2][y2];
    }

    if (n == 1) {
        int rec_sum = CalSum(x1, y1, x2, y2, sum);
        memo[n][x1][y1][x2][y2] = rec_sum * rec_sum;
        return rec_sum * rec_sum;
    }

    int min_sum = 10000000;
    for (int i = x1; i < x2; i++) {
        int left_sum = CalSum(x1, y1, i, y2, sum);
        int right_sum = CalSum(i + 1, y1, x2, y2, sum);
        int rec_sum = min((RecurSearch(n - 1, x1, y1, i, y2, memo, sum) +
            right_sum * right_sum),
            (RecurSearch(n - 1, i + 1, y1, x2, y2, memo, sum)
                + left_sum * left_sum));
        if (rec_sum < min_sum) {
            min_sum = rec_sum;
        }
    }

    for (int i = y1; i < y2; i++) {
        int up_sum = CalSum(x1, y1, x2, i, sum);
        int down_sum = CalSum(x1, i + 1, x2, y2, sum);
        int rec_sum = min((RecurSearch(n - 1, x1, y1, x2, i, memo, sum) +
            down_sum * down_sum),
            (RecurSearch(n - 1, x1, i + 1, x2, y2, memo, sum)
                + up_sum * up_sum));
        if (rec_sum < min_sum) {
            min_sum = rec_sum;
        }
    }

    memo[n][x1][y1][x2][y2] = min_sum;
    return min_sum;
}

int main() {
    int n;
    cin >> n;

    int board[9][9];
    int sum[9][9];
    int memo[15][9][9][9][9];

    memset(sum, 0, sizeof(sum));
    memset(memo, -1, sizeof(memo));

    for (int i = 1; i < 9; i++) {
        int row_sum = 0;
        for (int j = 1; j < 9; j++) {
            cin >> board[i][j];
            row_sum += board[i][j];
            sum[i][j] += sum[i - 1][j] + row_sum;
        }
    }

    double result = n * RecurSearch(n, 1, 1, 8, 8, memo, sum)
        - sum[8][8] * sum[8][8];
    cout << fixed << setprecision(3) << sqrt(result / (n * n)) << endl;

    return 0;
}
