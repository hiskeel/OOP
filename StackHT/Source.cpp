#include <iostream>

using namespace std;
template<class T_arr>
class Stack {
	enum { EMPTY = -1 };

	T_arr* arr;
	int size;
	int top;
public:
	Stack() {
		arr = nullptr;
		size = 0;
		top = EMPTY;
	}
	Stack(int size) :size(size)
	{
		arr = new T_arr[size];
		top = -1;
	}
	~Stack()
	{
		delete[]arr;
	}
	bool isFull() {
		return top == size - 1;
	}
	bool isEmpty() {
		return top == EMPTY;
	}
	void Push(T_arr value) {
		if (!isFull())arr[++top] = value;
	}
	T_arr Pop() {
		if (!isEmpty())return arr[top--];
		return 0;
	}
	int GetCount() {
		return top + 1;
	}
	int Peek() {
		return arr[top];
	}
	void Print()
	{
		for (int i = 0; i <= top; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}



};
bool IsValid(string code) {
	Stack<char> st(10);
	Stack<char> st1(10);
	Stack<char> st2(10);
	for (char symbol : code)
	{
		if (symbol == '{')
		{
			st.Push('{');

		}
		if (symbol == '}')
		{
			if (st.isEmpty())return false;
			st.Pop();
		}
		if (symbol == '(')
		{
			st1.Push('(');

		}
		if (symbol == ')')
		{
			if (st1.isEmpty())return false;
			st1.Pop();
		}
		if (symbol == '[')
		{
			st2.Push('[');

		}
		if (symbol == ']')
		{
			if (st2.isEmpty())return false;
			st2.Pop();
		}
	}
	return st.isEmpty() && st2.isEmpty() && st1.isEmpty();
}

void main() {
	Stack<int> st(20);
	st.Push(5);
	st.Push(7);
	st.Push(8);
	st.Push(4);
	st.Push(11);
	cout << "Count : " << st.GetCount() << endl;
	st.Print();
	cout << "Element  by Peek : " << st.Peek() << endl;
	while (!st.isEmpty())
	{
		cout << "Element  : " << st.Pop() << endl;
		st.Print();
	}
	cout << "Count : " << st.GetCount() << endl;

	string code = "class Stack{ void Print(){for(.....){if(.....){.....}}}};";
	if (IsValid(code))
		cout << "Valid code" << endl;
	else
		cout << "Invalid code" << endl;
}