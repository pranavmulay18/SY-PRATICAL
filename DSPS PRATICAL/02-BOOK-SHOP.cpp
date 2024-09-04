#include <iostream>
#include <string>
using namespace std;

class Library {
public:
    string title;
    float cost;

    void addBook() {
        cout << "  • Book Title: ";
        cin >> title;
        cout << "  • Book Price: ";
        cin >> cost;
    }
    
    static void displayShelf(Library books[], int count) {
        cout << "----------------------------------------------------------" << endl;
        cout << "|        Book Title        |       Price        |" << endl;
        cout << "----------------------------------------------------------" << endl;
        for (int i = 0; i < count; i++) {
            cout << "| " << setw(20) << left << books[i].title << " | " 
                 << setw(15) << right << books[i].cost << " |" << endl;
        }
        cout << "----------------------------------------------------------" << endl;
    }

    static void removeDuplicates(Library books[], int &count) {
        cout << "\nRemoving Duplicates......." << endl;
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (books[i].title == books[j].title) {
                    for (int k = j; k < count - 1; k++) {
                        books[k] = books[k + 1];
                    }
                    count--; 
                    j--; 
                }
            }
        }
    }

    static void removeDuplicatesUnoptimized(Library books[], int count) {
        bool flags[count];
        Library filteredBooks[count];
        cout << "\nRemoving Duplicates......." << endl;
        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                if (books[i].title == books[j].title) {
                    flags[j] = true;
                }
            }
        }

        int i = 0, j = 0;
        while (i < count) {
            if (!flags[i]) {
                filteredBooks[j] = books[i];
                j++;
            }
            i++;
        }
        for (int k = j; k < count; k++) {
            filteredBooks[k].title = "No Title";
            filteredBooks[k].cost = 0.0;
        }

        displayShelf(filteredBooks, count);
    }

    static void sortBooks(Library books[], int count) {
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (books[i].cost < books[j].cost) {
                    Library temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
    }

    static void filterByPrice(Library books[], int price, int count) {
        int belowCount = 0;
        
        cout << "Books Below Provided Price:" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "|        Book Title        |       Price        |" << endl;
        cout << "----------------------------------------------------------" << endl;
        for (int i = 0; i < count; i++) {
            if (books[i].cost < price) {
                cout << "| " << setw(20) << left << books[i].title << " | " 
                     << setw(15) << right << books[i].cost << " |" << endl;
                belowCount++;
            }
        }
        cout << "----------------------------------------------------------" << endl;
        cout << "\n\nNumber of Books Below Given Price: [ " << belowCount << " ]" << endl;

        int aboveCount = 0;

        cout << "Books Above Provided Price:" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "|        Book Title        |       Price        |" << endl;
        cout << "----------------------------------------------------------" << endl;
        for (int i = 0; i < count; i++) {
            if (books[i].cost >= price) {
                cout << "| " << setw(20) << left << books[i].title << " | " 
                     << setw(15) << right << books[i].cost << " |" << endl;
                aboveCount++;
            }
        }
        cout << "----------------------------------------------------------" << endl;
        cout << "\n\nNumber of Books Above Given Price: [ " << aboveCount << " ]" << endl;
    }
};

int main() {
    Library shelf[10];
    int count, choice;

    cout << "Enter Number of Books: ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        cout << "Enter Details of Book - " << i + 1 << " : " << endl;
        shelf[i].addBook();
    }

    do {
        cout << "\nOperation Menu:" << endl;
        cout << "1. Filter Books by Price" << endl;
        cout << "2. Remove Duplicates (Optimized)" << endl;
        cout << "3. Display Shelf" << endl;
        cout << "4. Sort Books by Price (Descending)" << endl;
        cout << "5. Remove Duplicates (Unoptimized)" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int price;
                cout << "Enter Price to Filter By: ";
                cin >> price;
                Library::filterByPrice(shelf, price, count);
                break;
            }
            case 2: {
                Library::removeDuplicates(shelf, count);
                break;
            }
            case 3: {
                Library::displayShelf(shelf, count);
                break;
            }
            case 4: {
                Library::sortBooks(shelf, count);
                cout << "Books sorted by price." << endl;
                break;
            }
            case 5: {
                Library::removeDuplicatesUnoptimized(shelf, count);
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
