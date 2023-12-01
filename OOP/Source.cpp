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
class Circle : public Shape {
	int radius;
public:
	Circle() :Shape(), radius(0) {}
	Circle(string n, string t, double a, int l) :radius(l), Shape(n, t, a) {}
	void Show() {
		Shape::Show();
		cout << "radius: " << radius << "cm" << endl;
	}
};
class Triangle : public Shape {
	int line;
public:
	Triangle() :Shape(), line(0) {}
	Triangle(string n, string t, double a, int l) :line(l), Shape(n, t, a) {}
	void Show() {
		Shape::Show();
		cout << "Line of triangle: " << line << "cm" << endl;
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
	Triangle b;
	Circle c;
	TestShape(a);
	cout << endl;
	TestShape(b);
	cout << endl;
	TestShape(c);
	cout << endl;
}