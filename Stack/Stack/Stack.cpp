#include <iostream>
using namespace std;

// to use this static value while implementing stack array-based
const int MAX_SIZE = 100;

class Node {
public:
    int data;
    Node* next;
};

class Stack {

public:
    Node* top = NULL;

    void push(int value) {
        Node *node= new Node();
        node->data = value;
        if (isEmpty()) {
            node->next = NULL;
            top = node;
        }
        else {
            node->next = top;
            top = node;
        }
    }

    int peek() {
        return top->data;
    }

    int pop() {
        int popedItem = top->data;
        Node* removedNode = top;
        top = top->next;
        delete[] removedNode;
        return popedItem;
    }

    void display() {
        Node* counter = top;
        while (counter != NULL) {
            cout << counter->data << " | ";
            counter = counter->next;
        }
    }

    int count() {
        if (isEmpty()) return 0;

        Node* counterPtr = top;
        int counterItems = 0;
        while (counterPtr != NULL) {
            counterItems++;
            counterPtr = counterPtr->next;
        }
        return counterItems;
    }

    bool isEmpty() {
        return (top == NULL);
    }

    bool isFound(int item) {
        Node* counterPtr = top;
        while (counterPtr != NULL) {
            if (counterPtr->data == item) return true;
            counterPtr = counterPtr->next;
        }
        return false;
    }
};

/*=============================================*/

template <class t>
class StackArrayBased {

private:
    int top = -1;
    t items[MAX_SIZE];

public:
    void push(t item) {
        if (isFull()) return;
        top++;
        items[top] = item;
    }

    t pop() {
        if (isEmpty())
            cout << "an empty stack";
        t removedItem = items[top];
        top--;
        return removedItem;
    }

    t peek() {
        if (isEmpty())
            cout << "an empty stack";
        else
            return items[top];
    }

    void display() {
        cout << "[ ";
        for (int i = top; i > -1; i--) {
            cout << items[i] << " ";
        }
        cout << "]";
    }
    
    bool isFull() {
        return (top >= MAX_SIZE - 1);
    }

    bool isEmpty() {
        return (top < 0);
    }
};

int main()
{

    /*
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.pop();
    cout << stack.peek() << endl;
    cout << "# items => " << stack.count() << endl;
    cout << "is there \"3\" in the stack => " << stack.isFound(2);
    */

    StackArrayBased<string> stack;
    stack.push("osama");
    stack.push("karim");
    stack.push("abdulazim");
    stack.push("yahia");

    stack.pop();
    stack.pop();


    stack.display();
    cout << "\nstack based array is full : " << stack.isFull() << endl;
    cout << "\nstack based array is empty  : " << stack.isEmpty() << endl;

}
