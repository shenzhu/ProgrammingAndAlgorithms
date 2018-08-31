/* Copyright Shen Zhu 2018 */

#include <algorithm>
#include <iostream>

using std::binary_search;
using std::cin;
using std::cout;
using std::endl;
using std::sort;

struct Plant {
    int x_;
    int y_;

    Plant() {}
    Plant(int x, int y) : x_(x), y_(y) {}
};

bool operator<(const Plant& lhs, const Plant& rhs) {
    if (lhs.x_ == rhs.x_) {
        return lhs.y_ < rhs.y_;
    }
    return lhs.x_ < rhs.x_;
}

int SearchPath(Plant start_plant, int dx, int dy, int row, int col,
        Plant plants[5000], int n) {
    Plant plant(start_plant.x_ + dx, start_plant.y_ + dy);
    int step = 2;
    while (plant.x_ <= row && plant.x_ >= 1 &&
            plant.y_ <= col && plant.y_ >= 1) {
        if (!binary_search(plants, plants + n, plant)) {
            step = 0;
            break;
        }
        plant.x_ += dx;
        plant.y_ += dy;
        step++;
    }
    return step;
}

int main() {
    int row, col, n;
    cin >> row >> col >> n;

    Plant plants[5000];
    for (int i = 0; i < n; i++) {
        cin >> plants[i].x_ >> plants[i].y_;
    }

    sort(plants, plants + n);

    int max_step = 2;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int dx = plants[j].x_ - plants[i].x_;
            int dy = plants[j].y_ - plants[i].y_;
            int px = plants[i].x_ - dx;
            int py = plants[i].y_ - dy;

            if (px >= 1 && px <= row && py >= 1 && py <= col) {
                continue;
            }

            if (plants[i].x_ + (max_step - 1) * dx > row) {
                break;
            }

            int final_py = plants[i].y_ + (max_step - 1) * dy;
            if (final_py > col || final_py < 1) {
                continue;
            }

            int curr_step = SearchPath(plants[j], dx, dy, row, col, plants, n);
            if (curr_step > max_step) {
                max_step = curr_step;
            }
        }
    }

    if (max_step == 2) {
        max_step = 0;
    }
    cout << max_step << endl;

    return 0;
}
