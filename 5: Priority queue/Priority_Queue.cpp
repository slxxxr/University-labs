#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T> class priority_queue {
private:

	vector<T> heap = {};

	void up(int i) {
		while (i != 0 and this->heap[i] > this->heap[(i - 1) / 2]) {
			swap(this->heap[i], this->heap[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}

	void down(int i) {
		while (2 * i + 1 < (int)this->heap.size()) {
			int maxChild = 2 * i + 1;
			if (maxChild + 1 < (int)this->heap.size() and this->heap[maxChild] < this->heap[maxChild + 1]) {
				maxChild++;
			}

			if (this->heap[i] >= this->heap[maxChild]) {
				break;
			}
			swap(this->heap[i], this->heap[maxChild]);
			i = maxChild;
		}
	}

public:
	priority_queue() {
		this->heap = {};
	}

	void push(T value) {
		this->heap.push_back(value);
		up((int)this->heap.size() - 1);
	}

	T pop() {
		T value = this->heap[0];
		this->heap[0] = this->heap[(int)this->heap.size() - 1];
		this->heap.pop_back();
		down(0);
		return value;
	}

	int size() {
		return (int)this->heap.size();
	}

	bool empty() {
		return size() == 0;
	}

	T top() {
		return this->heap[0];
	}

	priority_queue& operator=(priority_queue& other) {
		this->heap = other.heap;

		return *this;
	}

};


int main() {

	priority_queue<int> que;

	que.push(131);
	que.push(123);
	que.push(213);

	cout << que.top() << endl;
	
	que.pop();
	cout << que.top() << endl;
	
	que.pop();
	cout << que.top() << endl;

	que.push(1212);
	cout << que.top() << endl;
	
}
