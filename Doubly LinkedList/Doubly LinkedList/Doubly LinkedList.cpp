#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DblLinkedList {
    Node* head = NULL;
    Node* tail = NULL;
    int length = 0;
    bool reversed = false;
public:
    // inset First
    void insertFirst(int item) {
        Node* node = new Node();
        node->data = item;
        if (isEmpty()) {
            node->prev = node->next = NULL;
            head = node;
            length++;
            return;
        }
        head->prev = node;
        node->next = head;
        node->prev = NULL;
        head = node;
        length++;
    }

    // insert Last
    void insertLast(int item) {
        if (isEmpty()) {
            insertFirst(item);
            return;
        }
        Node* node = new Node();
        node->data = item;
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        node->prev = temp;
        node->next = NULL;
        temp->next = node;

        length++;
    }

    // insert at position
    void insertAtPosition(int position, int item) {
        if (position < 0 || position >= length) return;
        if (position == 0) {
            insertFirst(item);
            return;
        }
        if (position == length - 1) {
            insertLast(item);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position; i++) temp = temp->next;
        Node* node = new Node();
        node->data = item;
        // modifying "next"s & "prev"s
        temp->prev->next = node;
        node->prev = temp->prev;

        node->next = temp;
        temp->prev = node;

        length++;
    }

    // REMOVING
    // remove first
    void removeFirst() {
        if (isEmpty()) return;
        Node* deleted = head;
        head = head->next;
        delete deleted;
        length--;
    }
    // remove last
    void removeLast() {
        if (isEmpty()) return;
        if (length == 1) {
            removeFirst();
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->prev->next = temp->next; // next = NULL
        delete temp;
        length--;
    }

    // remove at position
    void removeAtPosition(int position) {
        if (isEmpty() || position < 0 || position >= length) return;
        if (position == 0) {
            removeFirst();
            return;
        }
        if (position == length - 1) {
            removeLast();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position; i++) temp = temp->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        length--;
    }

    void reverse() {
        if (isEmpty() || length == 1)
            return;
        if (reversed) {
            Node* temp = head;
            head = tail;
            tail = head;
            reversed = false;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        tail = head;
        head = temp;
        reversed = true;
    }

    bool contains(int item) {
        if (isEmpty()) return 0;
        if (length == 1) return head->data == item;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == item) return 1;
            temp = temp->next;
        }
        return 0;
    }

    bool isEmpty() { return head == NULL; }

    void display() {
        if (isEmpty())
            return;
        Node* temp = head;
        if (temp->next == NULL && length > 1) {
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->prev;
            }
            cout << endl;
            return;
        }
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DblLinkedList linked;
    linked.insertFirst(1);
    linked.insertFirst(2);
    linked.insertFirst(3);

    linked.insertLast(4);

    linked.insertAtPosition(1, 111);
    linked.insertAtPosition(4, 444);
    linked.insertAtPosition(0, 444);
    linked.display();
    cout << endl;
    linked.removeAtPosition(2);
    linked.removeAtPosition(2);
    linked.removeAtPosition(-1);

    linked.removeAtPosition(5);

    linked.display();

    linked.reverse();
    linked.reverse();
    linked.reverse();
    linked.reverse();

    linked.display();
}