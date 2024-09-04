#include <iostream>
using namespace std;

int main() {
    int size, targetElement;
    cout << "Enter the Number of Elements: ";
    cin >> size;

    int elements[size];
    cout << "Enter the elements:\n";
    for (int i = 0; i < size; ++i) {
        cout <<"Enter element At ["<<i<<"] :";
        cin >> elements[i];
    }

    cout<<"Given Array : [ ";
    for (int i = 0; i < size; ++i) {
       cout <<elements[i]<<" ,";
    }
    cout<<"]\n";
    cout<<"Array Index : [ ";
         for (int i = 0; i < size; ++i) {
             cout <<i<<" ,";
     }
    cout<<"]\n";
    cout << "Enter the target element to search for: ";
    cin >> targetElement;
    int frequency = 0;
	for (int i = 0; i < size; ++i) {
            if(elements[i]==targetElement){
            	frequency++;
            }
    }
    int targetIndices[frequency];
    int currentIndex = 0;
    for (int i = 0; i < size; ++i) {
        if (elements[i] == targetElement) {
            targetIndices[currentIndex]=i;
            currentIndex++; 
        }
    } 

    if (frequency > 0) {
    	 cout << "Number of Occurrences : ["<<frequency << "]\n";
         cout << "Element First Occurrence [" << targetIndices[0] << "].\n";
         int lastIndex = sizeof(targetIndices)/sizeof(int);
         cout << "Element Last Occurrence [" << targetIndices[lastIndex-1] << "].\n";
         cout<<"All Indices of Occurrence : [ ";
         for (int i = 0; i < frequency; ++i) {
             cout <<targetIndices[i]<<" ,";
         }
         cout<<"]\n";
    } else {
        cout << "Element not found.\n";
    }

    return 0;
}

