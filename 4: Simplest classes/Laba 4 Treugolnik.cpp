#include "Treugolnik.h"



int main() {

	Treugolnik one(-1, -2, 5, 1, 1, 4);
	
	cout << one;

	cin >> one;

	cout << one;

	cout << "Square: " << one.square() << "\n";

	one *= 2;

	cout << one << "\n";

	cout << "Square: " << one.square() << "\n";
	
}