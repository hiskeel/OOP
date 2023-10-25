#include <iostream>

using namespace std;
class Book {
private:
	string title;
	string genre;
	string author;
	string vudavnyctvo;
public:
	Book() {
		title = "no title";
		genre = "no Genre";
		author = "no Author";
		vudavnyctvo = "no Vydavnuctvo";
	}

	void ShowBook() {
		cout << "Title: " << title << endl;
		cout << "Genre: " << genre << endl;
		cout << "Author: " << author << endl;
		cout << "Vudavnyctvo: " << vudavnyctvo << endl;
		cout << "________________________________" << endl;
	}
	void ChangeData() {
		cout << "Enter new title: "; cin >> title;
		cout << "Enter new genre: "; cin >> genre;
		cout << "Enter new author: "; cin >> author;
		cout << "Enter new vudavnyctvo: "; cin >> vudavnyctvo;
	}
	void FillInfo(string title, string genre, string author, string vudavn) {
		this->title = title;
		this->genre = genre;
		this->author = author;
		this->vudavnyctvo = vudavn;

	}
};
class Library {
	int size = 10;
	Book* arr;
public:
	void CreateList() {
		arr = new Book[size];
	}
	void FillList() {
		/*string title;
		string genre;
		string author;
		string vudavnyctvo;
		for (int i = 0; i < size; i++) {
			cout << "Enter new title: "; cin >> title;
			cout << "Enter new genre: "; cin >> genre;
			cout << "Enter new author: "; cin >> author;
			cout << "Enter new vudavnyctvo: "; cin >> vudavnyctvo;

			arr[i].FillInfo(title, genre, author, vudavnyctvo);
		}*/
	}
	void Show() {
		for (int i = 0; i < size; i++) {
			arr[i].ShowBook();
		}

	}
	void ChangeData(int index) {
		arr[index].ChangeData();
	}
	void FillBookInfo(int index) {
		string title;
		string genre;
		string author;
		string vudavnyctvo;
		cout << "Enter new title: "; cin >> title;
		cout << "Enter new genre: "; cin >> genre;
		cout << "Enter new author: "; cin >> author;
		cout << "Enter new vudavnyctvo: "; cin >> vudavnyctvo;
		arr[index].FillInfo(title, genre, author, vudavnyctvo);
	}
};
void main() {
	Library start;
	start.CreateList();
	/*start.FillList();*/
	start.Show();
	start.FillBookInfo(1);
	start.Show();
}