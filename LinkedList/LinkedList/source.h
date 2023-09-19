#include <iostream>
using namespace std;

class Node {

public:
	int data;
	Node* next;
	Node() {};
	Node(int data, Node* next) {
		this->data = data;
		this->next = next;
	}

};

class LinkedList {

public:
	Node* head;
	int length = 0;

	LinkedList() {
		head = NULL;
	}

	bool isEmpty() {
		return (head == NULL);
	}

	bool isFound(int item) {
		Node* temp = head;
		while (temp != NULL) {
			if (temp->data == item) return true;
			temp = temp->next;
		}
		return false;
	}

	int getLength() {
		return length;
	}

	void insertFirst(int dataValue) {
		if (isEmpty()) {
			insertEmpty(dataValue);
		}
		else {
			Node* node = new Node();
			node->data = dataValue;
			node->next = head;
			head = node;
			length++;
		}
	}


	void append(int dataValue) {
		if (isEmpty()) {
			insertEmpty(dataValue);
		}
		else {
			Node* node = new Node();
			node->data = dataValue;
			Node* temp = head;
			while (true) {
				if (temp->next == NULL) {
					temp->next = node;
					node->next = NULL;
					break;
				}
				temp = temp->next;
			}
			length++;
		}
	}

	void insertBefore(int item, int dataValue) {
		if (isEmpty()) {
			insertEmpty(dataValue);
		}
		else {
			if (isFound(item)) {
				Node* node = new Node();
				node->data = dataValue;
				length++;


				Node* points = head;

				if (points->data == item) {
					insertFirst(item);
					return;
				}

				while (points != NULL) {
					/*if (points == head) {
						if (points->data == item) {
							insertFirst(dataValue);
							break;
						}
					}*/
					if (points->next->data == item) {
						node->next = points->next;
						points->next = node;
						break;
					}
					points = points->next;
				}
			}
		}
	}

	void remove(int item) {
		if (isEmpty()) return;
		Node* deleptr = head;
		if (head->data == item) {
			head = head->next;
			delete deleptr;
			length--;
			return;
		}
		
		while (true) {
			if (deleptr->next->data == item) {
				Node* temp;
				temp = deleptr->next;
				deleptr->next = deleptr->next->next;
				delete temp;
				length--;
				return;
			}
			deleptr = deleptr->next;
		}
		
		//last
	}

	void display() {
		Node* temp = head;
		cout << "| ";
		while (temp != NULL) {
			cout << temp->data << " | ";
			temp = temp->next;
		}
		cout << endl;
	}

private:
	void insertEmpty(int dataValue) {
		Node* node = new Node();
		node->data = dataValue;
		node->next = NULL;
		head = node;
		length++;
	}
};

int main()
{
	LinkedList linked;
	/*linked.insertFirst(10);
	linked.insertFirst(20);
	linked.insertFirst(30);
	linked.insertFirst(40);*/

	linked.append(10);
	linked.append(20);
	linked.append(30);
	linked.append(40);

	linked.insertBefore(40, 0);

	linked.remove(20);
	linked.remove(0);
	linked.remove(40);

	linked.display();
	cout << "Linked List length : " << linked.getLength();

	return 0;

}
