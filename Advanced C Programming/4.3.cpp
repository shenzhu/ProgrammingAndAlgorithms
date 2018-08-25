/* Copyright Shen Zhu 2018 */

#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;

bool CheckPeak(int x, int y, int mountain[20][20], int m, int n) {
	int left, right, up, down;
	up = max(0, x - 1);
	down = min(m - 1, x + 1);
	left = max(0, y - 1);
	right = min(n - 1, y + 1);

	return (mountain[x][y] >= mountain[up][y]) &&
		(mountain[x][y] >= mountain[down][y]) &&
		(mountain[x][y] >= mountain[x][left]) &&
		(mountain[x][y] >= mountain[x][right]);
}

int main() {
	int m, n;
	cin >> m >> n;

	int mountain[20][20];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mountain[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (CheckPeak(i, j, mountain, m, n)) {
				cout << i << " " << j << endl;
			}
		}
	}

	return 0;
}