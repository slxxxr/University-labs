#include "treuh.h"



int main() {

	cout.setf(ios_base::fixed);

	Treugolnik t1(1, 1, 2, 2, 3, 3), t2;

	cout << "t1 " << endl << t1;
	cout << "t2: " << endl << t2;
	
	t2 = t1 + 2;

	cout << "t1 " << endl << t1;
	cout << "t2 " << endl << t2;

}
