#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;
struct Point {
	int x;
	int y;
	public:
		Point(int x, int y): x(x),y(y){}
		Point():x(1),y(1) {}
};
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
class Shape {
protected:
	
	string type;

public:
	Shape() : type("noType")  {}
	Shape(string t ) :type(t){}

	virtual void Print() {}
};

class Line : public Shape {
	Point start;
	Point end;
	COORD position;
public:
	Line(int x1, int y1,int x2,int y2) : start(x1,y1), end(x2,y2), position({ 0,0 }), Shape("Line"){}
	
	void SetPositionStart()
	{
		position.X = start.x >= 0 ? start.x : 0;
		position.Y = start.y >= 0 ? start.y : 0;
	}
	void SetPositionEnd() {
		position.X = end.x >= 0 ? end.x : 0;
		position.Y = end.y >= 0 ? end.y : 0;
	}
	void Print() override {
		SetPositionStart();
		
		gotoxy(position.X, position.Y);
		cout << ".";
		SetPositionEnd();
		gotoxy(position.X, position.Y);
		cout << ".";
	}
};
class Rectanglee : public Shape {
	Point start;
	int wight;
	int height;
	COORD position;
public:
	Rectanglee(int x, int y, int x2, int y2) : start(x, y),wight(x2),height(y2), position({0,0}), Shape("Rectangle") {}

	void SetPositionStart()
	{
		position.X = start.x >= 0 ? start.x : 0;
		position.Y = start.y >= 0 ? start.y : 0;
	}
	
	void Print()override {
		SetPositionStart();
		/*gotoxy(position.X, position.Y++);
		cout << ".";*/
		for (int i = 0; i <= height;i++) {
			gotoxy(position.X, position.Y+i);
			cout << "|";
			
			gotoxy(position.X + wight-1, position.Y +i);
			cout << "|";
		}
		for(int i = 0; i < wight;i++)
		{
			gotoxy(position.X + i, position.Y);
			cout << "-";
			gotoxy(position.X + i, position.Y + height);
			cout << "-";
		}
		
		
	}
};
class Polylines : public Shape {
	Point* points;
	int size ;
	COORD position;
public:
	Polylines():size(0), points(nullptr), position({ 0,0 }) {}
	Polylines(int size): position({ 0,0 }) {
		points = new Point[size];
		for (int i = 0; i < size; i++) {
			points[i].x = rand()%10;
			points[i].y = rand() % 10;
		}
		this->size = size;
		
	}
	~Polylines() {
		delete[] points;
	}
	
	void Print() override {
		for (int i = 0; i < size;i++) {
			position.X = points[i].x >= 0 ? points[i].x : 0;
			position.Y = points[i].y >= 0 ? points[i].y : 0;
			gotoxy(position.X, position.Y);
			cout << ".";
		}
	}


};





void main() {
	Line line(4, 5,6,8);
	Rectanglee rec(1, 1,3,3);
	line.Print();
	rec.Print();
	
	Polylines pl(5);
	pl.Print();
	
}