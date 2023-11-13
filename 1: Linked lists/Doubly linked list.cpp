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

	Node* find(int num) {
		Node* res = first;
		while (res and res->num != num) {
			res = res->next;
		}
		return res;
	}

	void push_back(Node* node) {
		if (empty()) {
			first = node;
			last = node;
			return;
		}

		last->next = node;
		node->prev = last;
		last = node;
	}

	void push_front(Node* node) {
		if (empty()) {
			first = node;
			last = node;
			return;
		}

		first->prev = node;
		node->next = first;
		first = node;
	}

	void insert_after(int num, Node* new_node) {
		Node* node = find(num);
		if (empty() or node == last) {
			push_back(new_node);
			return;
		}
		
		new_node->next = node->next;
		node->next->prev = new_node;
		node->next = new_node;
		new_node->prev = node;
	}

	void remove_all() {
		first = nullptr;
		last = nullptr;
	}

	void remove_back() {
		if (empty()) return;
		if (first == last) {
			remove_all();
			return;
		}
		
		Node* prev_node = last->prev;
		prev_node->next = nullptr;
		last = prev_node;
	}

	void remove_front() {
		if (empty() or first == last) {
			remove_all();
			return;
		}
		first->next->prev = nullptr;
		first = first->next;
	}

	void remove(int num) {
		Node* node = find(num);
		if (node == first) {
			remove_front();
			return;
		}
		if (node == last) {
			remove_back();
			return;
		}
		
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	void print_all() {
		Node* tmp = first;
		while (tmp != nullptr) {
			cout << tmp->fio << " ";
			cout << tmp->num << " ";
			cout << tmp->avto << " ";
			cout << tmp->hours << " ";
			cout << endl;
			tmp = tmp->next;
		}
		cout << endl;
	}

	void print_info(string avto) {
		Node* tmp = first;
		while (tmp != nullptr) {
			if (tmp->avto == avto) {
				cout << tmp->fio << " ";
				cout << tmp->num << " ";
				cout << tmp->hours << " ";
				cout << endl;
			}
			tmp = tmp->next;
		}
	}

};


int main() {

	list arr;
	ifstream in("input.txt");

	string avto, fam, inc, fio;
	int num, hours;
	while (in >> num >> avto >> fam >> inc >> hours) {
		fio = fam + " " + inc;
		Node* node = new Node(num, avto, fio, hours);
		arr.push_back(node);
	}
	in.close();
	
	int n;
	cin >> n;
	while (n--) {
		string typ;
		cin >> typ;

		if (typ == "print_all") {
			arr.print_all();
		}

		if (typ == "push_back") {
			cin >> num >> avto >> fam >> inc >> hours;
			fio = fam + " " + inc;
			Node* node = new Node(num, avto, fio, hours);
			arr.push_back(node);
		}

		if (typ == "insert_after") {
			int prev_num;
			cin >> prev_num;
			cin >> num >> avto >> fam >> inc >> hours;
			fio = fam + " " + inc;
			Node* node = new Node(num, avto, fio, hours);
			arr.insert_after(prev_num, node);
		}

		if (typ == "remove_front") {
			arr.remove_front();
		}

		if (typ == "remove_back") {
			arr.remove_back();
		}
		
		if (typ == "remove") {
			cin >> num;
			arr.remove(num);
		}

		if (typ == "print_info") {
			cin >> avto;
			arr.print_info(avto);
		}

		if (typ != "print_all" and typ != "print_info")arr.print_all();
		cout << "_____________________________" << endl;
	}

	cout << "END";
}

