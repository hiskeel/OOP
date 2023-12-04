#include <iostream>
#include<list>
#include<algorithm>
#include<string>
#include<random>
#include<fstream>

using namespace std;


struct Date {
	int year;
	int month;
	int day;
};
struct Passanger {
	string name;
	string surname;
};

class Ticket
{
private:
	int flight_number;
	Date departureDate;
	Passanger passanger;
	string destination;
public:
	Ticket(int number, Date date, Passanger pass, string dest) :flight_number(number), departureDate(date), passanger(pass), destination(dest) {}
	int GetNumber() {
		return flight_number;
	}
	string GetStation() {
		return destination;
	}
	Date GetDate() {
		return departureDate;
	}
	int GetYear() {
		return departureDate.year;
	}
	int GetMonth() {
		return departureDate.month;
	}
	int GetDay() {
		return departureDate.day;
	}
	Passanger GetPass() {
		return passanger;
	}
	string GetName() {
		return passanger.name;
	}
	string GetSurName() {
		return passanger.surname;
	}

	friend ostream& operator << (ostream& out, const Ticket& ticket);
	friend istream& operator >> (istream& in, Ticket& ticket);
	friend bool compareDate(Ticket& ticket1, Ticket& ticket2);
	friend bool compareDestination(Ticket& ticket1, Ticket& ticket2);
};
ostream& operator << (ostream& out, const Ticket& ticket) {
	out << "Number: " << ticket.flight_number << endl;
	out << "Date: " << ticket.departureDate.year << ".";
	out << ticket.departureDate.month << "." << ticket.departureDate.day << endl;
	out << "Name: " << ticket.passanger.name << "\n" << "Surname: " << ticket.passanger.surname << endl;
	out << "Station: " << ticket.destination << endl;
	return out;
}
istream& operator >> (istream& in, Ticket& ticket) {
	in >> ticket.flight_number;
	in >> ticket.departureDate.year;
	in >> ticket.departureDate.month;
	in >> ticket.departureDate.day;
	in >> ticket.destination;
	return in;
}

bool compareDate(Ticket& ticket1, Ticket& ticket2) {
	if (ticket1.departureDate.year < ticket2.departureDate.year) {
		return true;
	}
	else if (ticket1.departureDate.year <= ticket2.departureDate.year && ticket1.departureDate.month < ticket2.departureDate.month) {
		return true;
	}
	else if (ticket1.departureDate.year <= ticket2.departureDate.year && ticket1.departureDate.month <= ticket2.departureDate.month && ticket1.departureDate.day < ticket2.departureDate.day) {
		return true;
	}
	else {
		return false;
	}
}
bool compareDestination(Ticket& ticket1, Ticket& ticket2) {
	return ticket1.destination < ticket2.destination;
}
class Airport
{
private:
	list<Ticket> airport;
public:
	bool IsEmpty() {
		return airport.size() == 0;
	}
	void RandomInit() {
		int n = 1 + rand() % 998;
		unsigned short y = 2023 + rand() % 2;
		unsigned short m = rand() % 12;
		unsigned short d = rand() % 31;
		int ch;
		string station;
		string name;
		string surname;
		for (int i = 0; i < 12; i++) {
			ch = 128 + rand() % 36;
			station += char(ch);
		}
		for (int i = 0; i < 12; i++) {
			ch = 128 + rand() % 36;
			name += char(ch);
		}
		for (int i = 0; i < 12; i++) {
			ch = 128 + rand() % 36;
			surname += char(ch);
		}
		airport.push_back(Ticket(n, { y,m,d }, { name,surname }, station));
	}
	void AddTicket() {
		int y, m, d;
		cout << "Enter number of train:"; int n; cin >> n;
		do {
			cout << "Enter departure year:"; cin >> y;
			cout << "month:"; cin >> m;
			cout << "days :"; cin >> d;
		} while ((y < 2023 || y >= 2025) || (m < 0 || m > 12) || (d < 0 || d > 31));
		cout << "Enter destination station:";
		cin.ignore();
		string station;
		string name;
		string surname;
		getline(cin, station);
		cout << "\nEnter name:";
		getline(cin, name);
		cout << "\nEnter surname:";
		getline(cin, surname);

		airport.push_back(Ticket(n, { y,m,d }, { name,surname }, station));
	}
	void DeleteTicketByNumber() {
		cout << "Enter number of train:"; int sch; cin >> sch; cin.ignore();
		for (auto iter = airport.begin(); iter != airport.end(); ++iter) {

			if (iter->GetNumber() == sch) {
				airport.erase(iter);
				return;
			}
		}
	}
	void DeleteTicketByPassanger() {
		Passanger temp_pass;
		cout << "Enter name:"; cin >> temp_pass.name;
		cout << "Enter surname:"; cin >> temp_pass.surname;
		for (auto iter = airport.begin(); iter != airport.end(); ++iter) {
			if (iter->GetPass().name == temp_pass.name && iter->GetPass().surname == temp_pass.surname) {
				airport.erase(iter);
				return;
			}
		}

	}
	void ShowAll() {
		for (auto item : airport) {
			cout << item;
			cout << "################################################\n";
		}
		cout << endl;
	}
	void ShowByNumber() {
		cout << "Enter number of train:"; int sch; cin >> sch; cin.ignore();
		for (list<Ticket>::iterator iter = airport.begin(); iter != airport.end(); iter++) {
			Ticket temp = *iter;
			if (temp.GetNumber() == sch) {
				cout << temp;
				cout << "################################################\n";
			}
		}
	}
	void ShowByStation() {
		cin.ignore();
		cout << "Enter destination station:"; string sch; getline(cin, sch);
		for (list<Ticket>::iterator iter = airport.begin(); iter != airport.end(); iter++) {
			Ticket temp = *iter;
			if (temp.GetStation() == sch) {
				cout << temp;
				cout << "################################################\n";
			}
		}
	}
	void SortByDate() {
		airport.sort(compareDate);
	}
	void SortByStation() {
		airport.sort(compareDestination);
	}
	//Function for writing info into file
	void WriteInfo() {
		fstream file;
		file.open("Tickets registration.txt", ios_base::out);
		if (file.is_open()) {
			for (auto item : airport) {
				file << item.GetNumber() << "\n";
				file << item.GetYear() << "\n";
				file << item.GetMonth() << "\n";
				file << item.GetDay() << "\n";
				file << item.GetName() << "\n";
				file << item.GetSurName() << "\n";
				file << item.GetStation() << "\n";
			}
		}
		file.close();
	}
	//Function for geting info from file and put it on dynamic array
	void GetInfo() {
		fstream file;
		file.open("Tickets registration.txt", ios_base::in);
		if (file.is_open()) {
			string line;
			int count = 0;
			while (getline(file, line)) {
				count++;
			}
			int size = count / 7;
			file.clear();
			file.seekg(0, ios::beg);
			int i = 0;
			while (i < size) {
				int n; getline(file, line);
				n = stoi(line);
				int y, m, d;
				string name;
				string surname;
				getline(file, line);
				y = stoi(line);
				getline(file, line);
				m = stoi(line);
				getline(file, line);
				d = stoi(line);
				getline(file, line);
				name = line;
				getline(file, line);
				surname = line;
				getline(file, line);
				string st = line;
				airport.push_back(Ticket(n, { y,m,d }, { name,surname }, st));
				i++;
			}
		}
		file.close();
	}

};
void Menu(Airport& airport) {
	airport.GetInfo();
	if (airport.IsEmpty()) {
		cout << "There are no tickets in the list yet." << endl;
		system("pause");
		system("cls");
	}
	bool ex = false;
	while (!ex) {
		int choice = 0;
		int iner = 0;
		cout << "Welcome to our airport:";
		cout << "Please, make your choice:\n";
		cout << "1-add/create a new ticket.\n";
		cout << "2-show the list of the tickets.\n";
		cout << "3-delete the ticket.\n";
		cout << "4-sort tickets.\n";
		cout << "0-exit.\n";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			cout << "1-add random ticket.\n2-add ticket manualy.";
			cin >> iner;
			switch (iner) {
			case 1:
				airport.RandomInit();
				system("cls");
				break;
			case 2:
				system("cls");
				airport.AddTicket();
				break;
			default:
				break;
			}
			system("cls");
			break;
		case 2:
			cout << "1-show all tickes.\n2-show tickets by number.\n3-show by station." << endl;
			cin >> iner;
			switch (iner)
			{
			case 1:
				system("cls");
				airport.ShowAll();
				break;
			case 2:
				system("cls");
				airport.ShowByNumber();
				break;
			case 3:
				system("cls");
				airport.ShowByStation();
				break;
			default:
				break;
			}
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "1-delete ticket by passanger.\n2-delete ticket by number." << endl;
			cin >> iner;
			switch (iner)
			{
			case 1:
				system("cls");
				airport.DeleteTicketByPassanger();
				break;
			case 2:
				system("cls");
				airport.DeleteTicketByNumber();
				break;
			default:
				break;
			}
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "1-sort tickes by date.\n2-sort tickets by station." << endl;
			cin >> iner;
			switch (iner)
			{
			case 1:
				system("cls");
				airport.SortByDate();
				cout << "Tickets have been sorted by date." << endl;
				break;
			case 2:
				system("cls");
				airport.SortByStation();
				cout << "Tickets have been sorted by station." << endl;
				break;
			}
			system("pause");
			system("cls");
			break;
		case 0:
			ex = true;
		default:
			break;
		}
	}
	airport.WriteInfo();
}

void main() {
	srand(time(NULL));
	Airport airport;
	Menu(airport);
}