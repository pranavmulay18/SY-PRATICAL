#include<iostream>
using namespace std;

class Book {
    public:
        int cost;
        string name;

        void accept() {
            cout << "Enter the book title: ";
             cin >> name;
            cout << "Enter the book cost: ";
            cin >> cost;
        }

        void display()  {
            cout << name << "\t\t" << cost << endl;
        }
};

int main() {
    Book b[10];
    int i,ch,n,j,count=0;
    cout << "How many books are you? ";
    cin >> n;
    

    do {
        cout << "Menu\n1) Accept\n2) Display\n3) Sort\n4) Remove duplicate\n5) Count\n6) book which greater than 500:-\n7) EXIT \n Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                for (i = 0; i < n; i++) {
                    b[i].accept();
                }
                break;
            case 2:
                cout << "Book Title\tCost" << endl;
                for (i = 0; i < n; i++) {
                    b[i].display();
                }
                break;
            case 3:
                
            for (i = 0; i < n - 1; i++)
            {
                for (j = 0; j < n - i - 1; j++)
                {
                    if (b[j + 1].cost > b[j].cost)
                    {
                        Book temp;
                        temp = b[j + 1];
                        b[j + 1] = b[j];
                        b[j] = temp;
                    }
                }
            }
            cout << "\n";
            for (i = 0; i < n; i++)
                b[i].display();
            break;
            case 4:
            i = 0;
            for (j = 0; j < n; j++)
            {
                if (b[j].cost != b[i].cost)
                {
                    b[i + 1] = b[j];
                    i++;
                }
            }
            for (int k = 0; k <= i; k++)
                b[k].display();
            break;
            case 5:
            cout << "BOOK TITLE\tCOST\n";
            for (i = 0; i < n; i++)
            {
                if (b[i].cost <= 500)
                {
                    cout << b[i].name << " \t\t" << b[i].cost << "\n";
                }
                else
                {
                    count++;
                }
            }
            cout << "\nThe number of book which greater 500: " << count;
        

    
            break;
            case 6:
    
    cout<<"book which cost is greater then 500:-"<<count;
    break;
            
    }
}
    while (ch != 7);

    return 0;
}

