#include<iostream>

using namespace std;

#include <stdio.h>
#include <windows.h>


class Point {
	int x;
	int y;
public:
	Point() :x(0), y(0){}
	Point(int x, int y) :x(x), y(y) {}
	int GetX() {
		return x;
	}
	int GetY() {
		return y;
	}
	void Print() {
		cout << "X: " << x << "\nY: " << y << endl;
	}
	void operator ++() {
		x++;
		y++;
	}
	void operator --() {
		x--;
		y--;
	}
	void operator !() {
		x *= -1;
		y *= -1;
	}
	bool operator <(Point& a) {
		return x < a.x&& y < a.y;
	}
	bool operator >(Point& a) {
		return x > a.x&& y > a.y;
	}
	
};
void gotoxy(Point p) {
	COORD coord;
	coord.X = p.GetX();
	coord.Y = p.GetY();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
class Vector {
	Point* points;
	int pointCount;
public:
	Vector() {
		points = nullptr;
		pointCount = 0;
	}
	Vector(Point point) {
		points = new Point[pointCount + 1];
		points[pointCount] = point;
		pointCount++;
	}
	Vector(const Vector& other) {
		this->pointCount = other.pointCount;
		this->points = new Point[pointCount];
		for (int i = 0; i < pointCount;i++) {
			this->points[i] = other.points[i];
		}
	}
	~Vector() {
		delete[] points;
	}
	void AddPoint(Point a) {
		Point* temp = new Point[pointCount + 1];
		for (int i = 0; i < pointCount; i++) {
			temp[i] = points[i];
		}
		temp[pointCount] = a;
		pointCount++;
		
	
		delete[] points;
		points = temp;
	}
	void Print() {
		for (int i = 0; i < pointCount; i++) {
			cout << "X: " << points[i].GetX() << "\nY: " << points[i].GetY() << "\n-----" << endl;
		}
	}
	void operator =(Vector& other) {
		pointCount = other.pointCount;
		points = new Point[pointCount];
		for (int i = 0; i < pointCount;i++) {
			points[i] = other.points[i];
		}
	}
};


void main() {
	Point A(15, 30);
	Point B(2, 3);


	gotoxy(A);
	printf(".");


	A.Print();
	++A;
	A.Print();
	--A;
	A.Print();
	!A;
	A.Print();
	if (A < B) {
		cout << "A < B" << endl;
	}
	Vector points(A);
	points.AddPoint(B);
	points.Print();
	Vector P2(points);
	P2.Print();
	Vector v(Point(5,10));
	v.Print();
	P2 = v;
	P2.Print();
	cout << "\n\n\n\n";

	
}