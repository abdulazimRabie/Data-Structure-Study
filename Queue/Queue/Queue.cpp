#include <iostream>
#include <cassert>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node() {
		data = 0;
		next = NULL;
	}
};

class Queue {
public:
	Node* front;
	Node* rear;

	Queue() {
		front = rear = NULL;
	}

	void enQueue(int item) {
		Node* node = new Node();
		node->data = item;
		// next is NULL by default

		if (isEmpty()) {
			front = rear = node;
		}
		else {
			rear->next = node;
			rear = node;
		}

	}

	int dequeue() {
		if (isEmpty()) return NULL;

		Node* deletedItem;
		deletedItem = front;
		int item = front->data;

		if (front == rear) {
			front = rear = NULL;
			delete deletedItem;
		}
		else {
			front = front->next;
			delete deletedItem;
		}

		return item;

	}

	int peek() {
		return front->data;
	}

	int count() {
		int counter = 0;
		Node* temp = front;
		while (temp != NULL) {
			counter++;
			temp = temp->next;
		}
		return counter;
	}

	bool search(int item) {
		Node* temp = front;

		while (temp != NULL) {
			if (temp->data == item) 
				return true;
			temp = temp->next;
		}

		return false;
	}

	void clear() {
		while (!isEmpty()) dequeue();
	}

	void display() {
		Node* temp = front;
		while (temp != NULL) {
			cout << temp->data << " <- ";
			temp = temp->next;
		}
		cout << endl;
	}


	bool isEmpty() {
		return (front == NULL);
	}
};

/*==========================================*/
//const int maxSize = 100;

class arrayQueue {
	int front;
	int rear;
	int length;
	int *arr;
	int maxSize;
public:
	arrayQueue(int size) {
		front = 0;
		rear = size - 1;
		length = 0;
		arr = new int[size];
		maxSize = size; 
	}

	void enqueue(int item) {
		if (isFull()) {
			cout << "queue is full !" << endl;
			return;
		}
		rear = (rear + 1) % maxSize;
		arr[rear] = item;
		length++;
	}

	void dequeue() {
		if (isEmpty()) cout << "quueu is empty !" << endl;
		front = (front + 1) % maxSize;	
		length--;
	}

	int peek() {
		if (isEmpty()) {
			cout << "cann't peek ... queue is empty !" << endl;
			return;
		}
		return arr[front];
	}

	void peek(int & peekElement) {
		if (isEmpty()) {
			cout << "cann't peek ... queue is empty !" << endl;
			return;
		}
		peekElement = arr[front];
	}

	int search(int item) {
		if (isEmpty()) return -1;

		for (int i = front; i != rear; i = (i + 1) % maxSize) {
			if (arr[i] == item) return i;
		}
		if (arr[rear] == item) return rear;

		return -1;
	}

	void display() {
		assert(!isEmpty());
		return;

		for (int i = front; i != rear; i = (i + 1) % maxSize) {
			cout << arr[i] << " <- ";
		}
		cout << arr[rear] << endl;
	}

	bool isEmpty() {
		return length == 0;
	}

	bool isFull() {
		return length == maxSize;
	}
};

int main()
{
	/*
		Queue queue;
		queue.enQueue(1);
		queue.enQueue(2);
		queue.enQueue(3);

		cout << "peek : " << queue.peek() << endl;
		cout << "counter: " << queue.count() << endl;
		cout << "search for '3' : " << queue.search(3) << endl;

		queue.display();
		queue.clear();

		queue.display();

		cout << queue.isEmpty() << endl;
	*/

	arrayQueue q(5);
	/*q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);*/

	/*int topEle = 0;
	q.peek(topEle);

	cout << "top ele : " << topEle << endl;

	cout << "serach for 3 : " << q.search(3) << endl;

	q.display();*/

	cout << "pdlas" << endl;
	
}