// practical Exam.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <io.h>
#include <string>
using namespace std;

struct Node {
    string name;
    string phoneNumber;
    Node* next;

};

class phoneBook {
    Node* head = NULL;
    Node* tail = NULL;
public:
    void add(string name, string phoneNumber) {
        Node* node = new Node();
        node->name = name;
        node->phoneNumber = phoneNumber;

        if (isEmpty()) {
            head = node;
            tail = node;
            node->next = NULL;
            return;
        }


        tail->next = node;
        tail = node;
        node->next = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void display() {
        if (isEmpty()) return;
        Node* temp = head;
        cout << endl << "=========\n";
        while (temp != NULL) {
            cout << "[+]" << temp->name << "\t" << temp->phoneNumber << endl;
            temp = temp->next;
        }
        cout << "=========";
    }
};


void startMenue() {
    cout << "\n=====Phonebook Managment System=====" << endl;
    cout << "[1] Add Contact" << endl;
    cout << "[2] Display Contacts" << endl;
    cout << "[3] Exit" << endl;
    cout << "Enter Your Choice :";
}

int main()
{
    phoneBook phonebook;
    for (;;) {
        startMenue();
        int choice;
        cin >> choice;

        if (choice == 3) break;
        
        switch (choice) {
        case 1: {
            string name, phoneNumber;
            cout << "Enter The Name : ";
            cin >> name;
            cout << "Enter The PhoneNumber : ";
            cin >> phoneNumber;
            phonebook.add(name, phoneNumber);
            break;

        }
        case 2: {
            phonebook.display();
            break;
        }

        default:
            break;
        }



    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
