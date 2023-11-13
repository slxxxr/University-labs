#include <iostream>

using namespace std;

struct Node {
	string data;
	Node* next;

	Node(string data) :
		data(data),
		next(nullptr)
	{}
};

struct list {
	Node* first;
	Node* last;

	list():
		first(nullptr),
		last(nullptr)
	{}

	bool empty() {
		return (first? false : true);
	}

	Node* find(string data) {
		Node* res = first;
		while (res and res->data != data) {
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
		last = node;
	}

	void push_front(Node* node) {
		if (empty()) {
			first = node;
			last = node;
			return;
		}

		node->next = first;
		first = node;
	}

	void insert_after(string data, Node* new_node) {
		Node* node = find(data);
		if (empty() or node == last) {
			push_back(new_node);
			return;
		}
		new_node->next = node->next;
		node->next = new_node;
	}

	void remove_all() {
		first = nullptr;
		last = nullptr;
	}

	void remove_back() {
		if (empty()) return;
		if (first == last) {
			first = nullptr;
			last = nullptr;
			return;
		}

		Node* tmp = first;
		while (tmp and tmp->next != last) {
			tmp = tmp->next;
		}
		tmp->next = nullptr;
		last = tmp;
	}

	void remove_front() {
		if (empty()) { 
			return; 
		}
		if (first == last) {
			remove_all();
		}

		first = first->next;
	}

	void remove(string data) {
		Node* node = find(data);
		if (node == first) {
			remove_front();
			return;
		}
		if (node == last) {
			remove_back();
			return;
		}

		Node* tmp = first;
		while (tmp and tmp->next != node) {
			tmp = tmp->next;
		}
		tmp->next = node->next;
	}

	void print_all() {
		Node* tmp = first;
		while (tmp != nullptr) {
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}

};


int main() {

	list arr;
	int n; cin >> n;
	while (n--) {
		string typ;
		cin >> typ;
		if (typ == "push_front" or typ == "push_back") {
			string data;
			cin >> data;
			Node* node = new Node(data);
			(typ == "push_front" ? arr.push_front(node) : arr.push_back(node));
		}
		if (typ == "remove_back") {
			arr.remove_back();
		}
		if (typ == "remove_front") {
			arr.remove_front();
		}
		if (typ == "remove_all") {
			arr.remove_all();
		}
		if (typ == "insert_after") {
			string data, new_data;
			cin >> data >> new_data;
			Node* new_node = new Node(new_data);
			arr.insert_after(data, new_node);
		}
		if (typ == "remove") {
			string data; 
			cin >> data;
			arr.remove(data);
		}

		arr.print_all();
	}

	cout << "END";
}

