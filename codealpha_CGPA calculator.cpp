#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    float totalCredits = 0, totalGradePoints = 0;

    cout << "Enter number of courses: ";
    cin >> n;

    vector<float> grades(n), credits(n);

    for (int i = 0; i < n; i++) {
        cout << "\nCourse " << i + 1 << endl;
        cout << "Enter grade (on 10-point scale): ";
        cin >> grades[i];
        cout << "Enter credit hours: ";
        cin >> credits[i];

        totalCredits += credits[i];
        totalGradePoints += grades[i] * credits[i];
    }

    float GPA = totalGradePoints / totalCredits;
    float CGPA = GPA; 

    cout << "\n----- Course Details -----\n";
    cout << "Course\tGrade\tCredits\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << grades[i] << "\t" << credits[i] << endl;
    }

    cout << fixed << setprecision(2);
    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "GPA: " << GPA << endl;
    cout << "Final CGPA: " << CGPA << endl;

    return 0;
}
