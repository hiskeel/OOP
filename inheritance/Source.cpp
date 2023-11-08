#include <iostream>

using namespace std;

class Student {
protected:
	string name;
	string surname;
	string spec;
	int age;
public:
	Student() {
		name = "name";
		surname = "surname";
		spec = "spec";
		age = 0;

	}
	Student(string n, string sn, string sp, int ag) {
		name = n;
		surname = sn;
		spec = sp;
		age = ag;
	}
	void Show() {
		cout << "-------------------" << endl;
		cout << "Name: " << name << "\nSurname: " << surname << "\nSpecialization: " << spec << "\nAge: " << age << endl;
	}
};
class Aspirant:public Student {
private:
	string diplTopic;
	string diplName;
	bool diplStatus;
public:
	Aspirant(): Student() {
		diplTopic = "Topic";
		diplName = "Title";
		diplStatus = false;
	}
	Aspirant(string n, string sn, string sp, int ag ,string topic, string title, bool status):diplTopic(topic), diplName(title), diplStatus(status), Student(n,sn,sp,ag){}
	void Print() {
		Show();
		cout << "Topic of diplom work: " << diplTopic << "\nTitle: " << diplName << "\nIs work done: " << diplStatus << endl;
	}
};
class Pasport {
protected:
	string name;
	string surname;
	int pasportNumber;
	int ipn;
public:
	Pasport():name("name"),surname("surname"),pasportNumber(1),ipn(1){}
	Pasport(string n, string sr, int pN, int ip):name(n), surname(sr), pasportNumber(pN), ipn(ip){}
	void ShowPasp() {
		cout << "---------------" << endl;
		cout << "Name: " << name << "\nSurname: " << surname << "\nPasp Number: " << pasportNumber << "\nIPN: " << ipn << endl;
	}

};
class ForeignPasport : public Pasport {
	string visa;
public:
	ForeignPasport(): visa("visa"),Pasport(){}
	ForeignPasport(string n, string sr, int pN, int ip,string v): visa(v), Pasport(n,sr,pN,ip){}
	void Show() {
		ShowPasp();
		cout << "Visa: " << visa << endl;
	}
};

void main() {
	Aspirant misha("Misha","Rogutko","Computer Science", 25,"Assembler","Assembler what is this?", false);
	misha.Print();
	ForeignPasport mypasp("Mykola", "Borovets", 111111, 222222, "USA");
	mypasp.Show();
}