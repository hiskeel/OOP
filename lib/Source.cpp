#include <iostream>
#include<fstream>
#include<conio.h>
#include <string>

using namespace std;
class Book {
private:
	string title;
	string genre;
	string author;
	string vudavnyctvo;
public:
	string Gettitle() {
		return this->title;
	}
	string Getgenre() {
		return this->genre;
	}
	string Getauthor() {
		return this->author;
	}
	string Getvudavnyctvo() {
		return this->vudavnyctvo;
	}
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
	void AddBook() {
		Book* temp = new Book[size + 1];
		for (int i = 0; i < size;i++) {
			temp[i] = arr[i];
		}
		string title;
		string genre;
		string author;
		string vudavnyctvo;
		cout << "Enter new title: "; cin >> title;
		cout << "Enter new genre: "; cin >> genre;
		cout << "Enter new author: "; cin >> author;
		cout << "Enter new vudavnyctvo: "; cin >> vudavnyctvo;
		temp[size].FillInfo(title, genre, author, vudavnyctvo);
		delete [] arr;
		arr = temp;
		size++;
		
	}
	void searchByTitle(string request) {
		int prooveOW = 0;
		for (int i = 0; i < size; i++) {
			if (arr[i].Gettitle() == request) {
				arr[i].ShowBook();
				cout << "Book Index: " << i << endl;
			}
		}
		if (prooveOW == 0) {
			cout << "No such book with title: " << request << "!" << endl;
		}
	}
	void searchByGenre(string request) {
		int prooveOW = 0;
		for (int i = 0; i < size; i++) {
			if (arr[i].Getgenre() == request) {
				arr[i].ShowBook();
				cout << "Book Index: " << i << endl;
				prooveOW++;
			}
		}
		if (prooveOW == 0) {
			cout << "No such book with genre: " << request << "!" << endl;
		}
	}
	void searchByVudav(string request) {
		int prooveOW = 0;
		for (int i = 0; i < size; i++) {
			if (arr[i].Getvudavnyctvo() == request) {
				arr[i].ShowBook();
				cout << "Book Index: " << i << endl;
			}
		}
		if (prooveOW == 0) {
			cout << "No such book with vudavnyctvo: " << request << "!" << endl;
		}
	}
	void searchByAuthor(string request) {
		int prooveOW = 0;
		for (int i = 0; i < size; i++) {
			if (arr[i].Getauthor() == request) {
				arr[i].ShowBook();
				cout << "Book with Index: " << i << endl;
			}
		}
		if (prooveOW == 0) {
			cout << "No such book with author: " << request << "!" << endl;
		}
	}
	void SaveDataToFile(string path) {
		ofstream file(path);
		if (file.is_open()) {
			for (int i = 0; i < size; i++) {
				file << arr[i].Gettitle() << "\n";
				file << arr[i].Getgenre() << "\n";
				file << arr[i].Getauthor() << "\n";
				file << arr[i].Getvudavnyctvo() << "\n";
			}
			file.close();
			cout << "Data saved to " << path << endl;
		}
		else {
			cout << "Unable to open file for writing." << endl;
		}
	}

	// Load data from a file
	void LoadDataFromFile(string path) {
		ifstream file(path);
		if (file.is_open()) {
			int i = 0;
			while (!file.eof()) {
				string title, genre, author, vudavnyctvo;
				getline(file, title);
				getline(file, genre);
				getline(file, author);
				getline(file, vudavnyctvo);
				if (i < size) {
					arr[i].FillInfo(title, genre, author, vudavnyctvo);
					i++;
				}
				else {
					cout << "Library is full. Skipping extra data." << endl;
					break;
				}
			}
			file.close();
			cout << "Data loaded from " << path << endl;
		}
		else {
			cout << "Unable to open file for reading." << endl;
		}
	}
};

void main() {
	Library start;
	start.CreateList();
	start.LoadDataFromFile("library_data.txt");
	/*start.FillList();*/
	/*start.Show();
	start.Show();*/
	start.FillBookInfo(1);
	cout  << "\nBook info filled\n\n";
	/*start.Show();*/
	start.AddBook();
	cout << "\nBook Added\n\n";
	/*start.Show();*/
	start.Show();
	/*start.ChangeData(1);*/
	/*cout << "\nBook Data changed\n\n";
	start.Show();
	start.searchByAuthor("1");
	start.searchByGenre("2");
	start.searchByVudav("3");
	start.searchByTitle("1");*/
	start.SaveDataToFile("library_data.txt");
}