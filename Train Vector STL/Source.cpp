#include<iostream>
#include<vector>
#include <fstream>
#include<string>
#include <algorithm>

using namespace std;

class Train {
	struct Time {
	public:
		short hours, minutes, sec;
		Time():hours(0), minutes(0), sec(0){}
		Time(short h, short m, short s) {
			bool validation = false;
			while (!validation) {
				if (h < 0 || h>24 || m < 0 || m>60 || s < 0 || s>60) {
					cout << "Enter correct time.\nEnter hours: ";
					cin >> hours;
					cout << "Enter minutes: ";
					cin >> minutes;
					cout << "Enter seconds: ";
					cin >> sec;
				}
				else {
					validation = true;
					hours = h;
					minutes = m;
					sec = s;
				}
			}
		}
		void ShowTime() {
			cout << hours << ":" << minutes << ":" << sec;
		}
	};
	int number;
	Time departureTime;
	string destination;

public:
	Train():number(0), departureTime(),destination("destination"){}
	Train(int n, int h, int m, int s, string d):number(n),departureTime(h,m,s),destination(d){}
	const void ShowTrain() {
		cout << "-------------------------------" << endl;
		cout << "Train number:" << number << endl;
		cout << "Departure time: ";
		departureTime.ShowTime();
		cout << "\nDestination: " << destination << "\n-------------------------------" << endl;
			
	}
	const int GetNumber() {
		return number;
	}
	void EnterTime() {
		bool validation = false;
		while (!validation) {
			
				cout << "Enter correct time.\nEnter hours: ";
				cin >> departureTime.hours;
				cout << "Enter minutes: ";
				cin >> departureTime.minutes;
				cout << "Enter seconds: ";
				cin >> departureTime.sec;
			if (departureTime.hours < 0 || departureTime.hours>24 || departureTime.minutes < 0 || departureTime.minutes>60 || departureTime.sec < 0 || departureTime.sec>60){}
			else {
				validation = true;
			}
		}
	}
	Train AddTrain(int n, int h, int m, int s, string d) {
		return Train(n,h,m,s,d);
	}
	string GetDestination() {return destination;}
	const short GetHours() {
		return departureTime.hours;
	}
	const short GetMinutes() {
		return departureTime.minutes;
	}
	const short GetSeconds() {
		return departureTime.sec;
	}

};

class Railway {
	vector <Train> trains;
	static bool CompareTrainsByArrivalTime( Train& a,  Train& b) {
		if (a.GetHours() != b.GetHours()) {
			return a.GetHours() < b.GetHours();
		}
		if (a.GetMinutes() != b.GetMinutes()) {
			return a.GetMinutes() < b.GetMinutes();
		}
		return a.GetSeconds() < b.GetSeconds();
	}
public:
	
	void AddTrain() {
		short h, m, s;
		string destination;
		int number;
		bool validation = true;
		do {
			validation = true;
			cout << "Enter number: ";cin >> number;
			for (int i = 0; i < trains.size(); i++) {
				if (number == trains[i].GetNumber())validation = false;
				
			}
			
		}
		while (!validation);
		
		do{
			cout << "Enter correct time.\nEnter hours: ";
			cin >> h;
			cout << "Enter minutes: ";
			cin >> m;
			cout << "Enter seconds: ";
			cin >> s;
			if (h < 0 || h>24 || m < 0 || m>60 || s < 0 || s>60) {
				validation = false;
			}
		else {
			validation = true;
		}
		} while (!validation);
		cout << "Enter destination: ";cin >> destination;
		trains.push_back(Train(number, h, m, s, destination));
	}
	const void ShowInfo(){
		for (int i = 0;i < trains.size(); i++) {
			trains[i].ShowTrain();
		}
	}
	const void ShowTrain(int number) {
		bool check = false;
		for (int i = 0; i < trains.size();i++) {
			if (trains[i].GetNumber() == number) {
				trains[i].ShowTrain();
				check = true;
			}
		}
		if (check == false)cout << "No such trains with number: " << number << endl;
	}
	void ChangeDepartureTime(int number) {
		bool check = false;
		for (int i = 0; i < trains.size();i++) {
			if (trains[i].GetNumber() == number) {
				trains[i].EnterTime();
				check = true;
			}
		}
		if (check == false)cout << "No such trains with number: " << number << endl;
	}
	const void ShowTrainsByDestination(string dest) {
		bool check = false;
		for (int i = 0; i < trains.size();i++) {
			if (trains[i].GetDestination() == dest) {
				trains[i].ShowTrain();
				check = true;
			}
		}
		if (check == false)cout << "No such trains with destination to: " << dest << endl;
	}
	
	const void SaveToFile() {
		ofstream out("Railway.txt", ios_base::out);
		for (int i = 0; i < trains.size(); i++) {
			out << trains[i].GetNumber() << " " << trains[i].GetHours() << " " << trains[i].GetMinutes() << " " << trains[i].GetSeconds() << " " << trains[i].GetDestination() << endl;
		}
		out.close();
	}
	void LoadFromFile() {
		ifstream in("Railway.txt", ios_base::in);
		if (!in.is_open()) {
			cerr << "Error opening file for reading.\n";
			return;
		}
		trains.clear();
		int num, h, m, s;
		string dest;
		while (in >> num >> h >> m >> s) {
			getline(in >> ws, dest);
			trains.emplace_back(num, h, m, s, dest);
		}

		in.close();
	}
	


	void SortTrainsByArrivalTime() {
		sort(trains.begin(), trains.end(), CompareTrainsByArrivalTime);
	}
	
};

void main() {
	
	Railway station;
	station.LoadFromFile();
	station.AddTrain();
	station.AddTrain();
	station.AddTrain();
	/*station.ChangeDepartureTime(1);*/
	
	station.ShowInfo();
	station.SortTrainsByArrivalTime();
	station.ShowInfo();
	station.SaveToFile();
	station.ShowTrainsByDestination("London");
	/*station.ShowTrain(4);*/

}