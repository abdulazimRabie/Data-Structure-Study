#pragma once
#include <iostream>
using namespace std;

class Array {
private:
	int size;
	int length;
	int* items;
public:
	Array(int size) {
		this->size = size;
		length = 0;
		items = new int[size];
	}

	void fill() {
		int itemsTobBeFilled;
		cout << "#items to be filled" << endl;
		cin >> itemsTobBeFilled;

		if (itemsTobBeFilled > size) {
			cout << "items are larger than array size .. sorry!" << endl;
			return;
		}

		length = itemsTobBeFilled;

		for (int i = 0; i < itemsTobBeFilled; i++) {
			cout << "item #" << i << " : ";
			cin >> items[i];
		}
	}

	void display() {
		cout << "Diplaying inserted items" << endl;
		for (int i = 0; i < length; i++) {
			cout << items[i] << "\t";
		}
		cout << '\n';
	}

	int getSize() {
		return size;
	}

	int getLength() {
		return length;
	}

	int search(int value) {
		for (int i = 0; i < length; i++) {
			if (items[i] == value) return i;
		}
		return -1;
	}

	void append(int value) {
		if (length < size) {
			items[length] = value;
			length++;
		}
		else
			cout << "array is full \n";
	}

	void insert(int index, int value) {
		if (index >= size) {
			cout << "out of bounds \n";
			return;
		}

		if (length == size) {
			cout << "array is full" << endl;
			return;
		}

		for (int i = length; i > index; i--) {
			items[i] = items[i - 1];
		}

		items[index] = value;
		length++;
	}

	void remove(int index) {
		if (index < 0 || index >= size) {
			cout << "index isn't valied \n";
			return;
		}

		for (int i = index; i < length - 1; i++) {
			items[i] = items[i + 1];
		}

		items[length - 1] = NULL;
		length--;
	}


	void enlarge(int size) {
		if (size <= this->size) {
			cout << "must be larger than old one ! stupid." << endl;
			return;
		}

		int* oldItems = items;
		this->size = size;
		items = new int[size];

		for (int i = 0; i < this->size; i++) {
			items[i] = oldItems[i];
		}

		delete oldItems;
	}

};

int main() {

	Array array(5);
	array.fill();
	array.remove(2);
	array.display();
	cout << "Length : " << array.getLength() << endl;
	array.enlarge(10);
	array.append(100); // 1
	array.append(200); // 2
	array.append(400); // 3
	array.append(500); // 4
	array.append(600); // 5
	cout << "Size : " << array.getSize() << endl;
	array.display();
	return 0;
}