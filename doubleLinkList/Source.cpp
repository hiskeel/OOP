#include <iostream>
#include<string>

using namespace std;
struct Vagon
{
	int wag_number;
	int seats_number;
	int passengers;
	Vagon()
	{
		wag_number = 0;
		seats_number = 0;
		passengers = 0;
	}
	Vagon(int wag_number, int seats_number, int passengers)
	{
		this->wag_number = wag_number;
		this->seats_number = seats_number;
		this->passengers = passengers;
	}
	void Show()
	{
		cout << "Wagon number: " << wag_number << endl;
		cout << "Amount of places: " << seats_number << endl;
		cout << "Amount of passengers: " << passengers << endl << endl;

	}

};
ostream& operator << (ostream& out, Vagon vag) {
	out << "N:" << vag.wag_number << "-> Seats: " << vag.seats_number << " : Passengers: " << vag.passengers << endl;
	return out;
}


class Train
{
	
	
	struct Node
	{
		Node* prev;
		Vagon vag;
		Node* next;
		Node(Node* prev, Vagon value, Node* next) :prev(prev), vag(value), next(next) {}
	};
private:
	Node* head;
	Node* tail;
	int size;
public:
	
	Train()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	bool IsEmpty()
	{
		return head == nullptr;
	}
	void AddToHead(Vagon value)
	{
		Node* newNode = new Node(nullptr, value, head);

		if (IsEmpty())
		{
			head = tail = newNode;
		}
		else
		{
			head->prev = newNode;
			head = newNode;
		}
		size++;
	}
	void PrintList()
	{
		//Node* current = head;//int i = 0;
		//while (current != nullptr)//i < 10
		//{
		//	cout << current->value << " ";
		//	current = current->next;//i++;
		//}
		for (Node* i = head; i != nullptr; i = i->next)
		{
			cout << i->vag;
		}
		cout << endl;
	}
	~Train()
	{
		Node* current = nullptr;
		while (head != nullptr)
		{
			current = head;
			head = head->next;
			delete current;
		}
	}
	void AddToTail(Vagon value)
	{
		Node* newNode = new Node(tail, value, nullptr);

		if (IsEmpty())
			head = tail = newNode;
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}
	Vagon GetElementByPosition(int pos)
	{
		Node* current = head;
		int i = 1;
		while (current != nullptr)
		{
			if (pos == i) return current->vag;
			current = current->next;
			i++;
		}
	}
	Vagon operator[](int pos)
	{
		Node* current = head;
		int i = 1;
		while (current != nullptr)
		{
			if (pos == i) return current->vag;
			current = current->next;
			i++;
		}
	}
	void DeleteFromTail()
	{
		if (IsEmpty())return;
		if (head->next == nullptr)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
		size--;
	}
	void DeleteFromHead() {
		if (IsEmpty())return;
		if (head->next == nullptr)
		{
			delete tail;
			tail = head = nullptr;
		}
		else
		{
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
		}
		size--;
	}
	int GetSize()
	{
		return size;
	}
	void DeleteByPosition(int pos)//4
	{
		if (pos < 1 || pos > size)return;
		else if (pos == 1)
		{
			DeleteFromHead(); 
		}
		else if (pos == size)
		{
			DeleteFromTail();
		}
		else
		{
			Node* current;
			if (pos <= size / 2)
			{
				current = head;
				for (int i = 1; i < pos; i++)
				{
					current = current->next;
				}
			}
			else
			{
				current = tail;
				for (int i = size; i > pos; i--)
				{
					current = current->prev;
				}
			}

			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete current;
			size--;
		}

	}
	void AddByPos(int pos, Vagon vag) {
		if (pos < 1 || pos > size)return;
		else if (pos == 1)
		{
			AddToHead(vag);
		}
		else if (pos == size)
		{
			AddToTail(vag);
		}
		else
		{
			Node* current;
			Node* newNode = new Node(nullptr, vag, nullptr);
			if (pos <= size / 2)
			{
				current = head;
				for (int i = 1; i <= pos; i++)
				{
					current = current->next;
				}
			}
			else
			{
				current = tail;
				for (int i = size; i >= pos; i--)
				{
					current = current->prev;
				}
			}
			newNode->next = current->next;
			newNode->prev = current->prev->next;
			current->next = newNode;
			newNode->next->prev = newNode;
			
			size++;
		}
	}
};


void main() {
	
	Train list;
	list.AddToHead(Vagon(1, 30, 29));
	list.AddToHead(Vagon(2, 30, 4));
	list.AddToHead(Vagon(5, 30, 6));
	list.AddToHead(Vagon(6, 30, 6));
	list.AddToHead(Vagon(7, 30, 6));
	list.PrintList();
	list.DeleteFromHead();
	list.PrintList();
	list.AddByPos(2, Vagon(4, 31, 7));
	list.PrintList();
}
