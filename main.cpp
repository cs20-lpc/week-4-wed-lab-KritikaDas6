// #include "LinkedList.hpp"
// #include <string>

// int main() {
//     // call the constructor
//     LinkedList<string> myList;

//     // add elements to the list
//     myList.append("Heart");
//     myList.insert(0, "Your");
//     myList.insert(0, "May");

//     // try replacing as an invalid operation
//     try {
//         myList.replace(-3, "?");
//     }
//     catch (string& e) {
//         cerr << e << endl;
//     }

//     // add another element
//     myList.append("Citrus");

//     // try inserting as an invalid operation
//     try {
//         myList.insert(5, "kweh");
//     }
//     catch (string& e) {
//         cerr << e << endl;
//     }

//     // remove an element
//     myList.remove(3);

//     // display the state of the list
//     cout << myList;

//     // get the second element and display it
//     string word = myList.getElement(2);
//     cout << "Element 2: " << word << endl;

//     // create a second list using the copy constructor
//     cout<< "passes1"<<endl;
//     LinkedList<string> secondList = myList;


//     // modify the second list and display its state
   
//     secondList.append("Beat");
//     secondList.replace(2, "Drums");
//     cout << secondList;

//     // try removing an element as an invalid operation
//     try {
//         secondList.remove(4);
//     }
//     catch (string& e) {
//         cerr << e << endl;
//     }

//     // create a third list using the default constructor (max size of 100)
//     LinkedList<string> thirdList;

//     // display the state of the list, should be empty
//     cout << thirdList;

//     // copy the first list to the third list using assignment overload
//     thirdList = myList;

//     // display the length and max size, should match the first list
//     cout << "thirdList length: " << thirdList.getLength() << endl;

//     // add elements to the list
//     thirdList.append("Be A");
//     thirdList.append("Yellow");
//     thirdList.append("Banana");

//     // display the state of the list
//     cout << thirdList;

//     // try getting elements as an invalid operation
//     try {
//         cout << thirdList.getElement(-7) << endl;
//     }
//     catch (string& e) {
//         cerr << e << endl;
//     }
//     try {
//         cout << thirdList.getElement(7) << endl;
//     }
//     catch (string& e) {
//         cerr << e << endl;
//     }

//     // clear out the list and verify it is now empty
//     myList.clear();
//     if (myList.isEmpty()) {
//         cout << "myList is empty!\n";
//     }

//     // terminate
//     return 0;
// }

#include "LinkedList.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "LinkedList Driver Program\n\n";

    // test with integers
    LinkedList<int> numbers;

    cout << "Initial integer list:\n";
    cout << numbers;
    cout << "Length: " << numbers.getLength() << endl;
    cout << "Is empty: " << (numbers.isEmpty() ? "yes" : "no") << endl;

    // append and insert
    numbers.append(10);
    numbers.append(20);
    numbers.insert(0, 5); // insert at head
    numbers.insert(2, 15); // middle insert
    numbers.insert(numbers.getLength(), 25); // insert at end

    cout << "\nAfter appends and inserts:\n";
    cout << numbers;

    // bad inserts
    try {
        numbers.insert(-1, 100);
    } catch (string& e) {
        cout << "Error on insert(-1): " << e << endl;
    }

    try {
        numbers.insert(100, 100);
    } catch (string& e) {
        cout << "Error on insert(100): " << e << endl;
    }

    // get elements
    cout << "\nGetting elements:\n";
    try {
        cout << "Element at 0: " << numbers.getElement(0) << endl;
        cout << "Element at 3: " << numbers.getElement(3) << endl;
    } catch (string& e) {
        cout << "Error in getElement: " << e << endl;
    }

    // bad getElement
    try {
        numbers.getElement(-5);
    } catch (string& e) {
        cout << "Error in getElement(-5): " << e << endl;
    }

    // replace
    numbers.replace(1, 12);
    numbers.replace(4, 30);

    cout << "\nAfter replacements:\n";
    cout << numbers;

    // bad replace
    try {
        numbers.replace(10, 100);
    } catch (string& e) {
        cout << "Error in replace(10): " << e << endl;
    }

    // remove head, middle, tail
    numbers.remove(0);
    numbers.remove(2);
    numbers.remove(numbers.getLength() - 1);

    cout << "\nAfter removals:\n";
    cout << numbers;

    // bad remove
    try {
        numbers.remove(-1);
    } catch (string& e) {
        cout << "Error in remove(-1): " << e << endl;
    }

    try {
        numbers.remove(numbers.getLength());
    } catch (string& e) {
        cout << "Error in remove(length): " << e << endl;
    }

    // copy constructor test
    LinkedList<int> copyList(numbers);
    copyList.append(99);

    cout << "\nOriginal list:\n" << numbers;
    cout << "Copied list:\n" << copyList;

    // assignment test
    LinkedList<int> assignedList;
    assignedList = numbers;

    cout << "\nAssigned list:\n" << assignedList;

    // self-assignment
    assignedList = assignedList;
    cout << "After self-assignment:\n" << assignedList;

    // clear test
    numbers.clear();
    cout << "\nAfter clearing original list:\n";
    cout << numbers;
    cout << "Length: " << numbers.getLength() << endl;
    cout << "Is empty: " << (numbers.isEmpty() ? "yes" : "no") << endl;

    // insert into cleared list
    numbers.insert(0, 77);
    cout << "\nAfter inserting into cleared list:\n";
    cout << numbers;

    // try getElement on empty list
    numbers.clear();
    try {
        numbers.getElement(0);
    } catch (string& e) {
        cout << "Error in getElement after clear: " << e << endl;
    }

    // testing with strings
    LinkedList<string> names;
    names.append("asia");
    names.append("nav");
    names.insert(1, "kritika");
    names.replace(0, "das");
    names.remove(2);

    cout << "\nString list:\n";
    cout << names;

    LinkedList<string> copiedNames(names);
    copiedNames.append("Panigrahi");

    cout << "Copied string list:\n";
    cout << copiedNames;

    return 0;
}
