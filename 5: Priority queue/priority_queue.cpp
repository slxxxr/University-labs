#include "priority_queue.h"

template<typename T> void priority_queue<T>::up(int i) {
	while (i != 0 and this->heap[i] > this->heap[(i - 1) / 2]) {
		swap(this->heap[i], this->heap[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

template<typename T> void priority_queue<T>::down(int i) {
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


template<typename T> priority_queue<T>::priority_queue() {
	this->heap = {};
}

template<typename T> void priority_queue<T>::push(T value) {
	this->heap.push_back(value);
	up((int)this->heap.size() - 1);
}

template<typename T> T priority_queue<T>::pop() {
	T value = this->heap[0];
	this->heap[0] = this->heap[(int)this->heap.size() - 1];
	this->heap.pop_back();
	down(0);
	return value;
}

template<typename T> int priority_queue<T>::size() {
	return (int)this->heap.size();
}

template<typename T> bool priority_queue<T>::empty() {
	return size() == 0;
}

template<typename T> T priority_queue<T>::top() {
	return this->heap[0];
}

template<typename T> priority_queue<T>& priority_queue<T>::operator=(priority_queue& other) {
	this->heap = other.heap;

	return *this;
}


