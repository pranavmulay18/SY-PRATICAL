#include <iostream>
#include <string>

using namespace std;

class BookStore {
public:
    string name;
    string author;
    string publisher;
    int price;
    int copies;

    BookStore() {
        // Default constructor   
    }

    void addBook() {
        cout << "\t● Enter Book Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "\t● Enter Book Author: ";
        getline(cin, author);
        cout << "\t● Enter Book Publisher: ";
        getline(cin, publisher);
        cout << "\t● Enter Book Price: ";
        cin >> price;
        cout << "\t● Enter Book Copies: ";
        cin >> copies;
    }

    void displayBook(int index) {
        cout << "Book " << index << ":" << endl;
        cout << "Name: " << name << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: " << price << endl;
        cout << "Copies: " << copies << endl;
        cout << endl;
    }

    bool checkAvailability(int requiredCopies) {
        return requiredCopies <= copies;
    }

    static int searchBook(BookStore lot[], string bookTitle, string authorName, int lotSize) {
        for (int i = 0; i < lotSize; i++) {
            if (lot[i].author == authorName && lot[i].name == bookTitle) {
                return i;
            }
        }
        return -1;
    }

    static void orderBook(BookStore lot[], int lotSize) {
        string bookTitle, authorName;
        int requiredCopies;

        cout << "Enter Book Name: ";
        cin.ignore();
        getline(cin, bookTitle);
        cout << "Enter Book Author: ";
        getline(cin, authorName);

        int index = searchBook(lot, bookTitle, authorName, lotSize);

        if (index != -1) {
            cout << "Enter Book Copies Required: ";
            cin >> requiredCopies;

            if (lot[index].checkAvailability(requiredCopies)) {
                cout << "Order Successfully Placed!" << endl;
                lot[index].copies -= requiredCopies;

                cout << "Order Details:" << endl;
                lot[index].displayBook(index + 1);
            }
            else {
                cout << "OUT OF STOCK!" << endl;
            }
        }
        else {
            cout << "BOOK UNAVAILABLE IN SHOP!" << endl;
        }
    }
};

int main() {
    BookStore lot[5];
    int lotSize = 0, choice;

    do {
        cout << "\nOperation Menu:" << endl;
        cout << "1. ADD Books" << endl;
        cout << "2. Order Book" << endl;
        cout << "3. Display Books" << endl;
        cout << "4. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter Number of BOOKS (Max 5): ";
            cin >> lotSize;

            if (lotSize > 5) {
                cout << "You can only add up to 5 books." << endl;
                lotSize = 5;
            }

            for (int i = 0; i < lotSize; i++) {
                cout << "\nEnter Details of Book - " << i + 1 << " :" << endl;
                lot[i].addBook();
                cout << endl;
            }
            break;
        }
        case 2: {
            if (lotSize == 0) {
                cout << "No books available. Please add books first." << endl;
            }
            else {
                BookStore::orderBook(lot, lotSize);
            }
            break;
        }
        case 3: {
            if (lotSize == 0) {
                cout << "No books available." << endl;
            }
            else {
                for (int i = 0; i < lotSize; i++) {
                    lot[i].displayBook(i + 1);
                }
            }
            break;
        }
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
