#include <iostream>

using namespace std;

class Shape {
protected:
	string name;
	string type;
	double area;
public:
	Shape() :name("noName"), type("noType"), area(0) {}
	Shape(string n, string t, double a) :name(n), type(t), area(a) {}

	virtual void Show() {
		cout << "Name: " << name << "\nType: " << type << "\nArea: " << area << "cm^2" << endl;
	}
	double GetArea() {
		return area;
	}

};
 void TestShape(Shape& shape) {
	shape.Show();
}
class Square : public Shape {
	int line;
public:
	Square() :Shape(), line(0) {}
	Square(string n, string t, double a, int l) :line(l), Shape(n, t, a) {}
	void Show() {
		Shape::Show();
		cout << "Line: " << line << "cm" << endl;
	}
};
class Square : public Shape {
	int line;
public:
	Square() :Shape(), line(0) {}
	Square(string n, string t, double a, int l) :line(l), Shape(n, t, a) {}
	void Show() {
		Shape::Show();
		cout << "Line: " << line << "cm" << endl;
	}
};
class Square : public Shape {
	int line;
public:
	Square() :Shape(), line(0) {}
	Square(string n, string t, double a, int l) :line(l), Shape(n, t, a) {}
	void Show() {
		Shape::Show();
		cout << "Line: " << line << "cm" << endl;
	}
};


void main() {
	Square a;
	TestShape(a);
}