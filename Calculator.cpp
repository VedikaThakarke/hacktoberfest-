#include <iostream>
#include <vector>

using namespace std;

// Convert marks out of 100 to grade points
double marksToGradePoint(double marks) {
    if (marks >= 90) return 10;
    else if (marks >= 80) return 9;
    else if (marks >= 70) return 8;
    else if (marks >= 60) return 7;
    else if (marks >= 50) return 6;
    else if (marks >= 40) return 5;
    else return 0;  // Fail
}

// Calculate GPA for a semester
double calculateGPA(vector<double> grades, vector<int> credits) {
    double totalPoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < grades.size(); ++i) {
        totalPoints += grades[i] * credits[i];  // Grade * credit for each subject
        totalCredits += credits[i];  // Sum credits
    }

    if (totalCredits == 0) return 0;  // Avoid division by zero
    return totalPoints / totalCredits;  // GPA = total points / total credits
}

// Calculate CGPA based on GPA of each semester
double calculateCGPA(vector<double> gpas, vector<int> semesterCredits) {
    double totalGPA = 0;
    int totalSemCredits = 0;

    for (int i = 0; i < gpas.size(); ++i) {
        totalGPA += gpas[i] * semesterCredits[i];  // GPA * semester credits
        totalSemCredits += semesterCredits[i];  // Sum semester credits
    }

    if (totalSemCredits == 0) return 0;
    return totalGPA / totalSemCredits;  // CGPA = total GPA points / total credits
}

int main() {
    int numSubjects, numSemesters;

    // Input for current semester
    cout << "Enter the number of subjects in the current semester: ";
    cin >> numSubjects;

    vector<double> marks(numSubjects);
    vector<int> credits(numSubjects);
    vector<double> grades(numSubjects);

    // Input marks and credits for each subject
    for (int i = 0; i < numSubjects; ++i) {
        cout << "Subject " << (i + 1) << " marks: ";
        cin >> marks[i];
        cout << "Subject " << (i + 1) << " credits: ";
        cin >> credits[i];
        grades[i] = marksToGradePoint(marks[i]);  // Convert marks to grade points
    }

    // Calculate GPA for the current semester
    double currentGPA = calculateGPA(grades, credits);
    cout << "\nYour GPA for the current semester is: " << currentGPA << endl;

    // Input previous semester GPAs for CGPA calculation
    cout << "\nEnter the number of semesters completed (including the current semester): ";
    cin >> numSemesters;

    vector<double> gpas(numSemesters);
    vector<int> semesterCredits(numSemesters);

    // Input GPA and credits for all semesters
    for (int i = 0; i < numSemesters; ++i) {
        cout << "Semester " << (i + 1) << " GPA: ";
        cin >> gpas[i];
        cout << "Semester " << (i + 1) << " total credits: ";
        cin >> semesterCredits[i];
    }

    // Calculate CGPA
    double cgpa = calculateCGPA(gpas, semesterCredits);
    cout << "\nYour CGPA is: " << cgpa << endl;

    return 0;
}
