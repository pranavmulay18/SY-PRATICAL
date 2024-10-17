#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    float feedback;

public:
    // Default constructor
    Student() {
        name = "No Record";
        rollNumber = 0;
        studentClass = "No Class Allotted";
        feedback = 0.0;
    }

    float getFeedback() {
        int feedbackResponses[5];
        cout << "    1. Did You understand the Purpose of the Training Program at the start of the event?\n  \t• ( Press 1 [ YES ]  Press  0 [NO] ) : ";
        cin >> feedbackResponses[0];
        cout << "    2. Did the Training Meet your Expectations?\n  \t• ( Press 1 [ For 8/10 or more ]  Press  0 [ 7/10 or less] ) :  ";
        cin >> feedbackResponses[1];
        cout << "    3. Overall, how would you rate the training instructor?\n  \t• ( Press 1 [ YES ]  Press  0 [NO] ) :   ";
        cin >> feedbackResponses[2];
        cout << "    4. Was the Training program well-organized and easy to follow?\n  \t• ( Press 1 [ YES ]  Press  0 [NO] ) :  ";
        cin >> feedbackResponses[3];
        cout << "    5. Do you feel you were given enough time and resources to complete the training?\n  \t• ( Press 1 [ YES ]  Press  0 [NO] ) :  ";
        cin >> feedbackResponses[4];

        int positiveResponses = 0;
        for (int i = 0; i < 5; i++) {
            if (feedbackResponses[i] == 1) {
                positiveResponses++;
            }
        }

        return (positiveResponses / 5.0) * 100;
    }

    // Parameterized constructor
    Student(string n, int roll, string cls) {
        name = n;
        rollNumber = roll;
        studentClass = cls;
        feedback = getFeedback();
    }

    static void printRowHeader() {
        cout << "| " << setw(4) << "No."
             << " | " << setw(10) << "Name"
             << " | " << setw(10) << "Roll No."
             << " | " << setw(15) << "Class"
             << " | " << setw(7) << "Rating"
             << " | " << setw(7) << "Status"
             << " |\n";
    }

    static void printRow(int index, const string &n, int roll, const string &cls, float rate, const string &status) {
        cout << "| " << setw(4) << index + 1
             << " | " << setw(10) << n
             << " | " << setw(10) << roll
             << " | " << setw(15) << cls
             << " | " << setw(7) << fixed << setprecision(2) << rate
             << " | " << setw(7) << status
             << " |\n";
    }

    static void printBorder() {
        cout << "+------+------------+------------+---------------+---------+-----------+\n";
    }

    static void printStudents(Student students[], int count) {
        printBorder();
        printRowHeader();
        printBorder();

        for (int i = 0; i < count; i++) {
            string status = students[i].feedback > 60 ? "+ve" : "-ve";
            printRow(i, students[i].name, students[i].rollNumber, students[i].studentClass, students[i].feedback, status);
        }

        printBorder();
    }

    static bool isSorted(Student students[], int count) {
        for (int i = 0; i < count - 1; i++) {
            if (!(students[i].rollNumber < students[i + 1].rollNumber)) {
                return false;
            }
        }
        return true;
    }

    static void sortStudents(Student students[], int count) {
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (students[i].rollNumber > students[j].rollNumber) {
                    Student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
    }

    static float getAverageFeedback(Student students[], int count) {
        float total = 0;
        for (int i = 0; i < count; i++) {
            total += students[i].feedback;
        }
        return total / count;
    }

    static int linearSearch(Student students[], int count, int roll, string cls) {
        for (int i = 0; i < count; i++) {
            if (students[i].rollNumber == roll && students[i].studentClass == cls) {
                return i;
            }
        }
        return -1;
    }

    static int binarySearch(Student students[], int count) {
        if (!isSorted(students, count)) {
            cout << "The list is unsorted. Sorting the list...\n";
            sortStudents(students, count);
        }

        int roll;
        cout << "Enter Roll Number of Student: ";
        cin >> roll;

        int low = 0, high = count - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (students[mid].rollNumber == roll) {
                return mid;
            } else if (students[mid].rollNumber < roll) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    void displayStudent(int index) {
        printBorder();
        printRowHeader();
        printBorder();
        string status = feedback > 60 ? "+ve" : "-ve";
        printRow(index, name, rollNumber, studentClass, feedback, status);
        printBorder();
    }
};

int main() {
    Student students[10];
    int count, choice;

    cout << "Enter Number of Students Attended the Program: ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        string name, cls;
        int rollNumber;

        cout << "Enter Details of Student - " << i + 1 << " : " << endl;
        cout << "  • Enter Roll Number: ";
        cin >> rollNumber;
        cout << "  • Enter Name: ";
        cin >> name;
        cout << "  • Enter Class: ";
        cin >> cls;

        students[i] = Student(name, rollNumber, cls);
    }

    do {
        cout << "\nOperation Menu:" << endl;
        cout << "1. Sort by Roll Number" << endl;
        cout << "2. Display All Students FEEDBACK" << endl;
        cout << "3. Check Student Presence (Optimized)" << endl;
        cout << "4. Check Student Presence (Unoptimized)" << endl;
        cout << "5. Get FEEDBACK Summary" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Student::sortStudents(students, count);
                break;
            case 2:
                Student::printStudents(students, count);
                break;
            case 3: {
                int index = Student::binarySearch(students, count);
                if (index != -1) {
                    cout << "Student was Present for the Training Program\nStudent Details:\n\n";
                    students[index].displayStudent(index);
                } else {
                    cout << "Student was NOT Present for the Training Program" << endl;
                }
                break;
            }
            case 4: {
                int roll;
                string cls;
                cout << "Enter Roll Number of Student: ";
                cin >> roll;
                cout << "Enter Class of Student: ";
                cin >> cls;

                int index = Student::linearSearch(students, count, roll, cls);

                cout << "Searching using Linear Search..." << endl;

                if (index != -1) {
                    cout << "Student was Present for the Training Program\nStudent Details:\n";
                    students[index].displayStudent(index);
                } else {
                    cout << "Student was NOT Present for the Training Program" << endl;
                }
                break;
            }
            case 5: {
                Student::printStudents(students, count);
                cout << "\n\n";
                float averageFeedback = Student::getAverageFeedback(students, count);
                if (averageFeedback > 60) {
                    cout << "\t\t [ RESPONSE IS SATISFACTORY !!!! ]\n";
                    cout << "\t\tOverall RATING:  [ " << fixed << setprecision(2) << averageFeedback <<"  ]"<< endl;
                } else {
                    cout << "\t\t[ RESPONSE IS NOT SATISFACTORY !!!! ]\n";
                    cout << "\t\tOverall RATING: [  " << fixed << setprecision(2) << averageFeedback<<" ]" << endl;
                }
                break;
            }
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
