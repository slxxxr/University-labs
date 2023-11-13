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

struct list {
	Node* first;
	Node* last;

	list() :
		first(nullptr),
		last(nullptr)
	{}

	bool empty() {
		return (first ? false : true);
	}

	void push_back(int x) {
		Node* node = new Node(x);
		if (empty()) {
			first = node;
			last = node;
			return;
		}

		last->next = node;
		node->prev = last;
		last = node;
	}

	void push_front(int x) {
		Node* node = new Node(x);
		if (empty()) {
			first = node;
			last = node;
			return;
		}

		first->prev = node;
		node->next = first;
		first = node;
	}

	void remove_all() {
		first = nullptr;
		last = nullptr;
	}

	void pop_back() {
		if (empty()) return;
		if (first == last) {
			remove_all();
			return;
		}

		Node* prev_node = last->prev;
		prev_node->next = nullptr;
		last = prev_node;
	}

	void pop_front() {
		if (empty() or first == last) {
			remove_all();
			return;
		}
		first->next->prev = nullptr;
		first = first->next;
	}

	
	void print() {
		if (empty()) return;
		Node* tmp = first;
		while (tmp != nullptr) {
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
};

const int N = 5;

struct deque_mas {
	int data[N];
	int first, last, size;

	deque_mas() :
		data(),
		first(-1),
		last(0),
		size(0)
	{}

	bool full() {
		return((first == 0 and last == N - 1) or first == last + 1);
	}

	bool empty() {
		return (first == -1);
	}

	void push_front(int x) {
		if (full()) {
			cout << "Overflow" << endl;
			return;
		}

		if (first == -1) {
			first++;
			last = 0;
		}
		else if (first == 0) {
			first = N - 1;
		}
		else {
			first--;
		}

		data[first] = x;
		size++;
	}

	void push_back(int x) {
		if (full()) {
			cout << "Overflow" << endl;
			return;
		}

		if (first == -1) {
			first++;
			last = 0;
		}
		else if (last == N - 1) {
			last = 0;
		}
		else {
			last++;
		}

		data[last] = x;
		size++;
	}

	void pop_front() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}

		if (first == last) {
			first = -1;
			last = -1;
		}
		else if (first == N - 1) {
			first = 0;
		}
		else {
			first++;
		}

		size--;
	}

	void pop_back() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}

		if (first == last) {
			first = -1;
			last = -1;
		}
		else if (last == 0) {
			last = N - 1;
		}
		else {
			last--;
		}

		size--;
	}

	void print() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}

		if (last < first) {
			for (int i = first; i < N; i++) {
				cout << data[i] << " ";
			}
			for (int i = 0; i <= last; i++) {
				cout << data[i] << " ";
			}
		}
		else {
			for (int i = first; i <= last; i++) {
				cout << data[i] << " ";
			}
		}

		cout << endl;
	}

};



int main() {

	int n = 100;
	deque_mas q;

	while (n--) {
		string typ;
		cin >> typ;

		if (typ == "push_back") {
			int x;
			cin >> x;
			q.push_back(x);
		}
		else if (typ == "push_front") {
			int x;
			cin >> x;
			q.push_front(x);
		}
		else if (typ == "pop_back") {
			q.pop_back();
		}

		else if (typ == "pop_front") {
			q.pop_front();
		}
		
		q.print();

	}

	cout << "END";
}

