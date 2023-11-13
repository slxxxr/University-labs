#include <iostream>
#include <fstream>

using namespace std;

struct Node {
	string avto, fio;
	int num, hours;
	Node* prev;
	Node* next;

	Node(int num, string avto, string fio, int hours) :
		num(num),
		avto(avto),
		fio(fio),
		hours(hours),
		prev(nullptr),
		next(nullptr)
	{}
};

struct queue_spisok {
	int size;
	Node* first;
	Node* last;

	queue_spisok() :
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
		if (empty() or first == last) {
			remove_all();
			return;
		}
		first->next->prev = nullptr;
		first = first->next;
	}

	void print_node(Node* node) {
		cout << node->avto << " ";
		cout << node->num << " ";
		cout << node->fio << " ";
		cout << node->hours << " ";
		cout << endl;
	}

	void print() {
		if (empty()) return;
		Node* tmp = first;
		cout << "________________________" << endl;
		while (tmp != nullptr) {
			print_node(tmp);
			tmp = tmp->next;
		}
		cout << "________________________" << endl;
	}



};

const int N = 5;

struct queue_mas {
	Node* data[N];
	int first, last;
	int size;

	queue_mas() :
		data(),
		first(0),
		last(0),
		size(0)
	{}

	void push(Node* node) {
		if (size == N) {
			cout << "Overflow" << endl;
			return;
		}
		if (last >= N) {
			last = 0;
		}
		data[last] = node;
		last++;
		size++;
	}

	void pop() {
		if (size == 0) {
			cout << "Empty" << endl;
			return;
		}

		first++;
		if (first >= N) {
			first = 0;
		}
		size--;
	}

	void print_node(Node* node) {
		cout << node->avto << " ";
		cout << node->num << " ";
		cout << node->fio << " ";
		cout << node->hours << " ";
		cout << endl;
	}

	void print() {
		if (size == 0) {
			return;
		}
		cout << "________________________" << endl;
		if (last <= first) {

			for (int i = first; i < N; i++) {
				print_node(data[i]);
			}

			for (int i = 0; i < last; i++) {
				print_node(data[i]);
			}
			
		}
		else {
			for (int i = first; i < last; i++) {
				print_node(data[i]);
			}
		}
		cout << "________________________" << endl;
	}

};


int main() {

	queue_mas q;
	int n = 100;
	while (n--) {
		string typ;
		cin >> typ;
		if (typ == "push") {
			string avto, fam, inc, fio;
			int num, hours;
			cin >> num >> avto >> fam >> inc >> hours;
			fio = fam + " " + inc;
			Node* node = new Node(num, avto, fio, hours);
			q.push(node);
			q.print();
		}
		else if (typ == "pop") {
			q.pop();
			q.print();
		}
		else if (typ == "size") {
			cout << q.size << endl;
		}
		else if (typ == "print_front") {
			q.print_node(q.data[q.first]);
		}
		else if (typ == "print_back") {
			q.print_node(q.data[q.last-1]);
		}
	
		

	}

}

