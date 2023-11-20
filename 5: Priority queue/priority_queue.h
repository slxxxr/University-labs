#pragma once
#include <vector>

using namespace std;

template<typename T> class priority_queue{
private:
	
	vector<T> heap;

	void up(int i);

	void down(int i);

public:
	priority_queue();

	void push(T value);

	T pop();

	int size();

	bool empty();

	T top();

	priority_queue& operator=(priority_queue& other);

};

