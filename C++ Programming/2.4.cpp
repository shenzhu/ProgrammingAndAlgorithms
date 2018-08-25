/* Copyright Shen Zhu 2018 */

#include <iomanip>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setfill;
using std::setw;

class HeadQuarters {
 private:
  int red_or_blue_;
  int life_value_;
  int count_;
  int warrior_counts_[5];
  int warrior_values_[5];
  string warrior_names_[5];
  string headquarter_name_;
 public:
  HeadQuarters(int red_or_blue, int life_value, int warrior_values[],
    string warrior_names[], int order[], string headquarter_names[]);

  int GetLifeValue();

  int GetWarriorLifeValue(int position);

  void Produce(int time, int position);
};

inline
HeadQuarters::HeadQuarters(int red_or_blue, int life_value,
    int warrior_values[], string warrior_names[],
    int order[], string headquarter_names[]) : count_(0),
    life_value_(life_value), red_or_blue_(red_or_blue),
    headquarter_name_(headquarter_names[red_or_blue]) {
    for (int i = 0; i < 5; i++) {
        warrior_counts_[i] = 0;
        warrior_names_[i] = warrior_names[order[i]];
        warrior_values_[i] = warrior_values[order[i]];
    }
}

inline
int HeadQuarters::GetLifeValue() {
    return life_value_;
}

inline
int HeadQuarters::GetWarriorLifeValue(int position) {
    return warrior_values_[position];
}

inline
void HeadQuarters::Produce(int time, int position) {
    count_++;
    warrior_counts_[position]++;
    cout << setfill('0') << setw(3) << time << " " << headquarter_name_
         << " " << warrior_names_[position] << " " << count_
         << " born with strength " << warrior_values_[position] << ","
         << warrior_counts_[position] << " " << warrior_names_[position]
         << " in " << headquarter_name_ << " headquarter" << endl;
    life_value_ -= warrior_values_[position];
}

int main() {
    int red_order[5] = {2, 3, 4, 1, 0};
    int blue_order[5] = {3, 0, 1, 2, 4};
    string headquarter_names[2] = {"red", "blue"};
    string warrior_names[5] = {"dragon", "ninja",
        "iceman", "lion", "wolf"};

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int warrior_value_needed[5];
        int headquarter_value, min_value, red_position = 0, blue_position = 0;
        bool red_stop = false, blue_stop = false;
        cin >> headquarter_value;

        for (int j = 0; j < 5; j++) {
            cin >> warrior_value_needed[j];
        }
        cout << "Case:" << i + 1 << endl;

        min_value = warrior_value_needed[0];
        for (int j = 1; j < 5; j++) {
            if (warrior_value_needed[j] < min_value) {
                min_value = warrior_value_needed[j];
            }
        }

        HeadQuarters red_hq = HeadQuarters(0, headquarter_value,
            warrior_value_needed, warrior_names, red_order, headquarter_names);
        HeadQuarters blue_hq = HeadQuarters(1, headquarter_value,
            warrior_value_needed, warrior_names, blue_order, headquarter_names);

        for (int time = 0; ((!red_stop) || (!blue_stop)); time++) {
            if (!red_stop) {
                if (red_hq.GetLifeValue() < min_value) {
                    cout << setfill('0') << setw(3) << time
                         << " red headquarter stops making warriors" << endl;
                    red_stop = true;
                } else {
                    while (true) {
                        if (red_hq.GetLifeValue() >=
                            red_hq.GetWarriorLifeValue(red_position)) {
                            red_hq.Produce(time, red_position);
                            if (red_position == 4) {
                                red_position = 0;
                            } else {
                                red_position++;
                            }
                            break;
                        } else {
                            if (red_position == 4) {
                                red_position = 0;
                            } else {
                                red_position++;
                            }
                        }
                    }
                }
            }
            if (!blue_stop) {
                if (blue_hq.GetLifeValue() < min_value) {
                    cout << setfill('0') << setw(3) << time
                         << " blue headquarter stops making warriors" << endl;
                    blue_stop = true;
                } else {
                    while (true) {
                        if (blue_hq.GetLifeValue() >=
                            blue_hq.GetWarriorLifeValue(blue_position)) {
                            blue_hq.Produce(time, blue_position);
                            if (blue_position == 4) {
                                blue_position = 0;
                            } else {
                                blue_position++;
                            }
                            break;
                        } else {
                            if (blue_position == 4) {
                                blue_position = 0;
                            } else {
                                blue_position++;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
