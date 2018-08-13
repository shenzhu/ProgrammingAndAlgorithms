/* Copyright Shen Zhu 2018 */

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Student {

    private:
        int age_;
        int avg_grades_[4];
        int avg_grade_;
        string name_;
        string student_id_;

    public:
        void SetAge(int age) {
            age_ = age;
        }

        void SetAveGrades(int avg_grades[4]) {
            for (int i = 0; i < 4; i++) {
                avg_grades_[i] = avg_grades[i];
            }
        }

        void SetName(string name) {
            name_ = name;
        }

        void SetStudentId(string student_id) {
            student_id_ = student_id;
        }

        int GetAge() {
            return age_;
        }

        int CalculateAvgGrade() {
            int sum = 0;
            for (int i = 0; i < 4; i++) {
                sum += avg_grades_[i];
            }

            return sum / 4;
        }

        string GetName() {
            return name_;
        }

        string GetStudentId() {
            return student_id_;
        }
};

int main() {
    Student student;

    string line;
    getline(cin, line);

    // Split string by comma
    vector<string> elements;
    string delimiter = ",";
    size_t last_pos = 0, curr_pos;
    while ((curr_pos = line.find(delimiter, last_pos)) != string::npos) {
        string token = line.substr(last_pos, curr_pos - last_pos);
        elements.push_back(token);
        last_pos = curr_pos + delimiter.length();
    }
    elements.push_back(line.substr(last_pos, line.length()));
    
    
    student.SetName(elements[0]);
    student.SetAge(stoi(elements[1]));
    student.SetStudentId(elements[2]);

    int avg_grades[4] = {0};
    for (int i = 0; i < 4; i++) {
        avg_grades[i] = stoi(elements[3 + i]);
    }
    student.SetAveGrades(avg_grades);

    cout << student.GetName() << "," << student.GetAge() << ","
         << student.GetStudentId() << "," << student.CalculateAvgGrade() << endl;

    return 0;
}