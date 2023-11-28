#include "treuh.h"


Treugolnik::Treugolnik() {
	x1 = 0;
	x2 = 0;
	x3 = 0;

	y1 = 0;
	y2 = 0;
	y3 = 0;
}

Treugolnik::Treugolnik(double x1, double y1, double x2, double y2, double x3, double y3) {
	this->x1 = x1;
	this->y1 = y1;

	this->x2 = x2;
	this->y2 = y2;

	this->x3 = x3;
	this->y3 = y3;

	//cout << "Create" << endl;
}

Treugolnik::Treugolnik(const Treugolnik& other) {
	this->x1 = other.x1;
	this->y1 = other.y1;

	this->x2 = other.x2;
	this->y2 = other.y2;

	this->x3 = other.x3;
	this->y3 = other.y3;

	//cout << "Copy" << endl;
}


void Treugolnik::move(double x, double y) {
	this->x1 += x;
	this->y1 += y;

	this->x2 += x;
	this->y2 += y;

	this->x3 += x;
	this->y3 += y;
}

double Treugolnik::square() {
	double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	double b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
	double c = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));

	double p = (a + b + c) / 2;

	double square = sqrt(p * (p - a) * (p - b) * (p - c));
	return square;
}

bool Treugolnik::operator < (Treugolnik& other) {
	return (this->square() < other.square());
}

bool Treugolnik::operator > (Treugolnik& other) {
	return (this->square() > other.square());
}

Treugolnik Treugolnik::operator = (Treugolnik other) {
	this->x1 = other.x1;
	this->y1 = other.y1;

	this->x2 = other.x2;
	this->y2 = other.y2;

	this->x3 = other.x3;
	this->y3 = other.y3;

	//cout << "Pris" << endl;

	return *this;
}

Treugolnik Treugolnik::operator *= (double n) {
	this->x1 *= n;
	this->y1 *= n;

	this->x2 *= n;
	this->y2 *= n;

	this->x3 *= n;
	this->y3 *= n;

	
	return *this;
}


Treugolnik Treugolnik::operator + (double n) {

	Treugolnik temp = *this;

	temp.x1 += n;
	temp.y1 += n;

	temp.x2 += n;
	temp.y2 += n;

	temp.x3 += n;
	temp.y3 += n;

	return temp;
}


ostream& operator << (ostream& out, Treugolnik& T) {
	out << "X1:= " << T.x1 << "	 Y1:= " << T.y1 << "\n";
	out << "X2:= " << T.x2 << "	 Y2:= " << T.y2 << "\n";
	out << "X3:= " << T.x3 << "	 Y3:= " << T.y3 << "\n";
	out << "---------------------" << "\n";

	return out;
}

istream& operator >> (istream& in, Treugolnik& T) {
	cout << "Input X1 and Y1: ";
	in >> T.x1 >> T.y1;

	cout << "Input X2 and Y2: ";
	in >> T.x2 >> T.y2;

	cout << "Input X3 and Y3: ";
	in >> T.x3 >> T.y3;

	return in;
}

