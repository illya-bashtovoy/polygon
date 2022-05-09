/*
Створити абстрактний клас “Багатокутник”.
Клас повинен містити методи для обчислення периметра, знаходження площі і ін.
Побудувати похідний клас “Трикутник” і прямокутник,
що містить також методи для знаходження довжин медіан, висот трикутника, прямокутника
*/

#include <iostream>
#include <math.h>

using namespace std;

class  PLgon { 
protected:
	virtual double getArea() = 0; 
	virtual double getPerimetr() = 0;
};


class Trig : public PLgon {
protected:
	double ab, bc, ca;
	double Median;
	double Height; 
	double p;

public:
	Trig(int ab, int bc, int ca) {
		this -> ab = ab;
		this -> bc = bc;
		this -> ca = ca;
	}


	double Med() {
		Median = (sqrt(2 * pow(ab, 2) + 2 * pow(bc, 2) + 2 * pow(ca, 2))) / 2;
		return Median;
	}


	double Hg() {
		p = (ab + bc + ca) / 2;
		Height = 2 / ab * (sqrt(p * (p - ab) * (p - bc) * (p - ca)));
		return Height;
	}


	double getArea() override {
		return (Height * ab) / 2;
	}


	double getPerimetr() override {
		return p * 2;
	}


	~Trig() {};
};


class Rectangle : public PLgon {
protected:
	double ab, bc;
	double d;

public:
	Rectangle(int ab, int bc) {
		this->ab = ab;
		this->bc = bc;
	}


	double HgR() {
		return ab;
	}


	double Diagonal() {
		d = sqrt(pow(ab, 2) + pow(bc, 2));
		return d;
	}


	double getArea() override {
		return ab * bc;
	}


	double getPerimetr() override {
		return (ab + bc) * 2;
	}


	~Rectangle() {};
};


int main() {
	setlocale(0, "");

	Trig X(4, 5, 6);
	Rectangle N(6, 7);

	cout << "Медiана трикутника = " << X.Med() << endl;
	cout << "Висота трикутника = " << X.Hg() << endl;
	cout << "Периметр трикутника = " << X.getPerimetr() << endl;
	cout << "Площа трикутника = " << X.getArea() << endl;
	cout << "Дiагональ прямокутника = " << N.Diagonal() << endl;
	cout << "Висота прямокутника = " << N.HgR() << endl;
	cout << "Периметр прямокутника = " << N.getPerimetr() << endl;
	cout << "Площа прямокутника = " << N.getArea() << endl;
}