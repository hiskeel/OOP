#include <iostream>
using namespace std;
#include "windows.h"
#include<ostream>

//void gotoxy(int x, int y)
//{
//	COORD coord;
//	coord.X = x;
//	coord.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
class Point {
	int x;
	int y;
public:
	Point(int x, int y) : x(x), y(y) {};
	ostream operator << (ostream out) {
		out << x << ":" << y << endl;
	}
	int GetX() {
		return x;
	}
	int GetY() {
		return y;
	}



};
ostream &operator << (ostream& out, Point p) {
	out << p.GetX() << ":" << p.GetY() << endl;
	return out;
}
template<typename T>
class List
{
	struct Node
	{
		T value;
		Node* next;
		Node(T value, Node* next) :value(value), next(next) {}
	};
private:
	Node* head;
public:
	List()
	{
		head = nullptr;
	}
	void AddToHead(T value)
	{
		Node* newNode = new Node(value, head);
		//newNode->value = value;
		//newNode->next = head;

		head = newNode;
	}
	void PrintList()
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->value;
			current = current->next;
		}
		cout << endl;
	}
	~List()
	{
		Node* current = nullptr;
		while (head != nullptr)
		{
			current = head;
			head = head->next;
			delete current;
		}
	}
	void AddToTail(T value)
	{
		Node* newNode = new Node(value, nullptr);

		if (head == nullptr)
			head = newNode;
		else
		{
			Node* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}
	T GetElementByPosition(int pos)
	{
		Node* current = head;
		int i = 1;
		while (current != nullptr)
		{
			if (pos == i) return current->value;
			current = current->next;
			i++;
		}
	}
	void DeleteFromHead() {
		if (head == nullptr)return;
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node* temp;
			Node* current = head;
			
			temp = current->next;
			
			delete head;
			head = temp;
		}
	}
	void DeleteFromTail()
	{
		if (head == nullptr)return;
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node* current = head;
			while (current->next->next != nullptr)
			{
				current = current->next;
			}
			delete current->next;
			current->next = nullptr;
		}
	}
};

class Vector
{
	int size;
	//Point * points = new Point[size];
	List<Point> points;
public:
	//Vector()
	//{
	//	size = 0;
	//	points = nullptr;
	//}
	//void AddPoint(Point p)
	//{
	//	size++;
	//	Point* temp = new Point[size];//1
	//	for (int i = 0; i < size; i++)
	//	{
	//		temp[i] = points[i];
	//	}
	//}
	void AddPointToHead(Point p)
	{
		points.AddToHead(p);
	}
	void Print() {
		points.PrintList();
	}
	void AddPointToTail(Point p) {
		points.AddToTail(p);
	}
	void DeletePointFromTail() {
		points.DeleteFromTail();
	}
	void DeletePointFromHead() {
		points.DeleteFromHead();
	}
};

int main()
{
	//gotoxy(10, 10);
	List<Point> list;

	Vector v;
	Point p(1, 2);
	v.AddPointToHead(p);
	v.AddPointToHead(Point(2, 3));
	v.AddPointToHead(Point(3, 4));
	v.AddPointToHead(Point(5, 6));
	v.AddPointToHead(Point(6, 7));
	v.Print();
	v.DeletePointFromTail();
	v.AddPointToTail(Point(0, 0));
	v.Print();
	v.DeletePointFromHead();
	v.Print();

	
	






}