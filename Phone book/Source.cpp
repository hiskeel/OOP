#include<iostream>
#include <fstream>
#include<string>

using namespace std;
class PIB {
private:
	string name;
	string surname;
	string fatherName;
public:
	void FillPIB(string name, string surname, string fatherName) {
		this->name = name;
		this->surname = surname;
		this->fatherName = fatherName;
	}
	string GetPib() {
		string pib = name + surname + fatherName;
		return pib;
	}
	void PrintPib() {
		cout << surname << " " << name << " " << fatherName;
	}


};
class Abonents {
private:

	PIB pib;
	int homeNumb;
	int workNumb;
	int phoneNumb;
	string addInfo;
public:
	Abonents() {
		pib.FillPIB("name", "surname", "fatherName");
		this->homeNumb = 0;
		this->workNumb = 0;
		this->phoneNumb = 0;
		this->addInfo = "addInfo";
	}
	string GetPib() {
		return pib.GetPib();
	}
	int GethomeNumb() {
		return homeNumb;
	}
	int GetworkNumb() {
		return workNumb;
	}
	int GetphoneNumb() {
		return phoneNumb;
	}
	string GetaddInfo() {
		return addInfo;
	}
	void FillAbInf(string name, string surname, string fatherName, int hNumb, int workNumb, int phoneNumb, string addInfo) {
		this->pib.FillPIB(name, surname, fatherName);
		this->homeNumb = hNumb;
		this->workNumb = workNumb;
		this->phoneNumb = phoneNumb;
		this->addInfo = addInfo;
	}
	Abonents(string name, string surname, string fatherName, int hNumb, int workNumb, int phoneNumb, string addInfo) {
		FillAbInf(name, surname, fatherName, hNumb, workNumb, phoneNumb, addInfo);
	}

	void Print() {
		pib.PrintPib();
		cout << "\nHome number: " << homeNumb << "\nWork Number: " << workNumb << "\nPhone number: " << phoneNumb << "\nAdditional info: " << addInfo << endl;
		cout << "_____________________________________" << endl;
	}
	inline string GetPib1() {

		return pib.GetPib();
	}
};
class PhoneBook {
	PIB pib;
	Abonents* abonents;
	int countAb = 0;
public:
	void AddDefaultAb() {
		Abonents* temp = new Abonents[countAb + 1];
		for (int i = 0; i < countAb; i++)
		{
			temp[i] = abonents[i];
		}

		delete[] abonents;
		abonents = temp;


		this->countAb++;
	}
	void AddAbonent() {
		string name, surname, fatherName, addInfo;

		int homeNumb, workNumb, phoneNumb;
		cout << "Enter name: ";cin >> name;
		cout << "Enter surname: ";cin >> surname;
		cout << "Enter fatherName: ";cin >> fatherName;
		pib.FillPIB(name, surname, fatherName);

		cout << "Enter home Number: ";cin >> homeNumb;
		cout << "Enter work Number: ";cin >> workNumb;
		cout << "Enter phone Number: ";cin >> phoneNumb;
		cout << "Enter additional Info: ";cin >> addInfo;


		Abonents* temp = new Abonents[countAb + 1];
		for (int i = 0; i < countAb; i++)
		{
			temp[i] = abonents[i];
		}
		temp[countAb].FillAbInf(name, surname, fatherName, homeNumb, workNumb, phoneNumb, addInfo);
		delete[] abonents;
		abonents = temp;


		this->countAb++;
	}
	inline void CreatePhoneBook() {
		abonents = new Abonents[countAb + 1];
	}
	PhoneBook() {

		CreatePhoneBook();

	}

	~PhoneBook() {
		delete[] abonents;
	}
	inline void ShowAll() {
		cout << "=============================\nPhone book list: " << endl;
		for (int i = 0; i < countAb; i++) {
			abonents[i].Print();
		}
	}
	string request(string type) {
		string name, surname, fatherName;
		cout << "Enter name to " << type << ": ";cin >> name;
		cout << "Enter surname to search: ";cin >> surname;
		cout << "Enter fatherName to search: ";cin >> fatherName;
		pib.FillPIB(name, surname, fatherName);
		return pib.GetPib();
	}
	void FindByPIB(string request) {
		int check = 0;

		for (int i = 0; i < countAb;i++) {
			if (request == abonents[i].GetPib()) {
				cout << "\nResult of search:" << endl;
				abonents[i].Print();
				check++;
			}
		}
		if (check == 0) {
			cout << "\nSearched abonent was no find!" << endl;
		}
	}
	void DeleteAbonent(string request) {



		Abonents* temp = new Abonents[countAb - 1];
		int check = 0;
		for (int i = 0; i < countAb - 1; i++)
		{
			if (request == abonents[i].GetPib()) {
				check = 1;
			}
			if (check == 0) {
				temp[i] = abonents[i];
			}
			else {
				temp[i] = abonents[i + 1];
			}
		}

		delete[] abonents;
		abonents = temp;


		this->countAb--;
	}
	void SaveDataToFile(string path) {
		ofstream file(path);
		if (file.is_open()) {
			for (int i = 0; i < countAb; i++) {
				file << abonents[i].GetPib() << "\n";
				file << abonents[i].GethomeNumb() << "\n";
				file << abonents[i].GetworkNumb() << "\n";
				file << abonents[i].GetphoneNumb() << "\n";
				file << abonents[i].GetaddInfo() << "\n";

			}
			file.close();
			cout << "Data saved to " << path << endl;
		}
		else {
			cout << "Unable to open file for writing." << endl;
		}
	}

	// Load data from a file
	/*void LoadDataFromFile(string path) {
		ifstream file(path);
		if (file.is_open()) {
			int i = 0;
			while (!file.eof()) {
				string title, genre, author, vudavnyctvo;
				getline(file, title);
				getline(file, genre);
				getline(file, author);
				getline(file, vudavnyctvo);
				if (i < countAb) {
					abonents[i].FillAbInf(title, genre, author, vudavnyctvo);
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
*/
};



void main() {
	PhoneBook list;
	list.AddDefaultAb();
	list.AddAbonent();
	list.AddAbonent();
	list.AddAbonent();

	list.ShowAll();

	list.FindByPIB(list.request("search"));
	list.DeleteAbonent(list.request("delete"));
	list.ShowAll();
	list.SaveDataToFile("db.txt");



}