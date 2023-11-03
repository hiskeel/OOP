#include <iostream>

using namespace std;
class StaticStack {
	enum { EMPTY = -1, FULL = 9 };
	int arr[FULL + 1];
	int topIndex;
public:
	StaticStack()
	{
		topIndex = EMPTY;
	}

	~StaticStack() = default;
	
	explicit StaticStack(const StaticStack& other) = delete;

	bool IsFull()const
	{
		return topIndex == FULL;
	}
	bool Push(int elem)
	{
		if (!IsFull())
		{
			arr[++topIndex] = elem;
			return true;
		}
		return false;
	}
	bool IsEmpty()const
	{
		return topIndex == EMPTY;
	}
	int Pop()
	{
		if (!IsEmpty())
			return arr[topIndex--];
		return 0;
	}
	int GetCount()const
	{
		return topIndex + 1;
	}
	void Clear()
	{
		topIndex = EMPTY;
	}
	char Peek()
	{
		if (!IsEmpty())
			return arr[topIndex];
		return 0;
	}
	void Print()
	{
		for (int i = 0; i <= topIndex; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

class Stack {
	enum { EMPTY = -1 };

	char* arr;
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
		arr = new char[size];
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
	void Push(char value) {
		if (isFull()) {
			char* temp = new char[size * 2];
			for (int i = 0; i < size;i++) {
				temp[i] = arr[i];
			}
			temp[++top] = value;
			delete[]arr;
			size *= 2;
			arr = temp;
			
		}
		else { arr[++top] = value; }
	}
	
	
	char Pop() {
		if (!isEmpty())return arr[top--];
		return '0';
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


void main() {
	Stack st(3);
	st.Push('5');
	st.Push('7');
	st.Push('8');
	st.Push('4');
	st.Push('11');
	char peek = st.Peek();
	cout << "Count : " << st.GetCount() << endl;
	st.Print();
	cout << "Element  by Peek : " << peek << endl;
	while (!st.isEmpty())
	{
		cout << "Element  : " << st.Pop() << endl;
		st.Print();
	}
	cout << "Count : " << st.GetCount() << endl;
}
	