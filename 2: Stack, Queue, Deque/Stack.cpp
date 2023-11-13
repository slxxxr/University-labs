#include <iostream>
#include <fstream>

using namespace std;

struct Node {
	int data;
	Node* prev;
	Node* next;

	Node(int data) :
		data(data),
		prev(nullptr),
		next(nullptr)
	{}
};

struct stack_spisok {
	int size;
	Node* first;
	Node* last;

	stack_spisok() :
		size(0),
		first(nullptr),
		last(nullptr)
	{}

	bool empty() {
		return (first ? false : true);
	}

	void push(Node* node) {
		if (empty()) {
			first = node;
			last = node;
			return;
		}

		last->next = node;
		node->prev = last;
		last = node;
		size++;
	}

	void remove_all() {
		first = nullptr;
		last = nullptr;
		size = 0;
	}

	void pop() {
		if (empty()) return;
		if (first == last) {
			remove_all();
			return;
		}

		Node* prev_node = last->prev;
		prev_node->next = nullptr;
		last = prev_node;
		size--;
	}

	void print() {
		Node* tmp = first;
		while (tmp != nullptr) {
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}

};

const int N = 100;

struct stack_mas {
	int data[N];
	int size;

	stack_mas() :
		size(0)
	{}

	void push(int x) {
		if (size == N) {
			cout << "Overflow" << endl;
			return;
		}
		data[size] = x;
		size++;
	}

	int pop() {
		if (size == 0) {
			cout << "Empty" << endl;
			return -1;
		}
		size--;
		return data[size];
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}

};


int main() {

	stack_mas st;
	int n = 100;
	while (n--) {
		string typ;
		cin >> typ;
		if (typ == "push") {
			int x;
			cin >> x;
			st.push(x);
		}
		if (typ == "pop") {
			cout << st.pop() << endl;
		}

		st.print();
	}

}

