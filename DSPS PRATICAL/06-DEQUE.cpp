#include <iostream>
using namespace std;

class Queue
{
public:
    int f, r;
    int ele, n;
    int Q[10]; 

    Queue(int size)
    {
        n = size;
        f = -1;
        r = -1;
    }

    void enQueue();
    void deQueue();
    void peek();
    bool isempty();
    bool isfull();
    void display();
};


bool Queue::isempty()
{
    return (f == -1);
}


bool Queue::isfull()
{
    return (r == n - 1);
}


void Queue::enQueue()
{
    if (isfull())
    {
        cout << "Queue is full!!!\nCan't insert element!" << endl;
    }
    else
    {
        if (isempty())
        {
            f = 0;
        }
        cout << "Enter the element to enqueue: ";
        cin >> ele;
        r++;
        Q[r] = ele;
    }
}


void Queue::deQueue()
{
    if (isempty())
    {
        cout << "Queue is empty!!!\n";
        return;
    }

    cout << "Dequeued element is: " << Q[f] << "\n";

    if (f == r)
    {
        f = r = -1; 
    }
    else
    {
        f++;
    }
}


void Queue::display()
{
    if (isempty())
    {
        cout << "Queue is empty!\n";
    }
    else
    {
        cout << "Queue Elements: ";
        for (int i = f; i <= r; i++)
        {
            cout << Q[i] << " ";
        }
        cout << "\n";
    }
}


void Queue::peek()
{
    if (isempty())
    {
        cout << "Queue is empty!!!\n";
    }
    else
    {
        cout << "The first element of the queue is: " << Q[f] << "\n";
    }
}

int main()
{
    int n;
    cout << "Enter the size of the queue: ";
    cin >> n;
    Queue q(n);
    int ch = 0;

    while (true)
    {
        cout << "\nQueue Operations: \n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            q.enQueue();
            break;
        case 2:
            q.deQueue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            q.peek();
            break;
        case 5:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice! Please select from the options.\n";
        }
    }

    return 0;
}
