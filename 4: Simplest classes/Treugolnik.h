#pragma once
#include <iostream> 
#include <cmath>

using namespace std;
class Treugolnik {

private:
	double x1, y1, x2, y2, x3, y3;

public:

	Treugolnik();

	Treugolnik(double x1, double y1, double x2, double y2, double x3, double y3);

	Treugolnik(const Treugolnik& other);

	~Treugolnik();

	void move(double x, double y);

	double square();

	bool operator < (Treugolnik& other);

	bool operator > (Treugolnik& other);

	Treugolnik operator + (double n);

	Treugolnik operator = (Treugolnik other);

	Treugolnik operator *= (double n);

	friend ostream& operator << (ostream& out, Treugolnik& T);

	friend istream& operator >> (istream& in, Treugolnik& T);

};


