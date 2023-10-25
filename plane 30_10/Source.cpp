#include<iostream>

using namespace std;
class Airplane {
	string model;
	string type;
	int countPassenger;
	int maxPassenger;
public:
	Airplane() {
		model = "Model";
		type = "type";
		countPassenger = 0;
		maxPassenger = 0;
	}
	Airplane(string mode, string typ, int pass, int maxPass) {
		model = mode;
		type = typ;
		countPassenger = pass;
		maxPassenger = maxPass;
	}
	explicit operator string()
	{

		return model;
	}
	void Show() {
		cout << " Model: " << model << endl;
		cout << " Type: " << type << endl;
		cout << " Passengers in: " << countPassenger << endl;
		cout << " Max Passengers: " << maxPassenger << endl;
	}
	friend void operator ++(Airplane& pl1);
	friend void operator --(Airplane& pl1);

	friend ostream& operator << (ostream& out, Airplane& plane);
	friend istream& operator >> (istream& in, Airplane& plane);

	friend bool operator ==(Airplane& pl1, Airplane& pl2);
	friend bool operator <(Airplane& pl1, Airplane& pl2);
	friend bool operator >(Airplane& pl1, Airplane& pl2);
	void operator ()(int value) {
		int left = 0;
		int check = 0;
		int count = 0;
		
		while(check == 0)
		{
			if (countPassenger < maxPassenger) {
				countPassenger++;
				count++;
				if (count == value) {
					check = 1;
				}
			}
			else {
				check = 1;
				cout << "There are maximum passengers in this plane!" << endl;
				left = value - count;
				cout << left << " passengers left out the board!" << endl;
			}
		}
	}
};

void operator ++(Airplane& pl1) {
	if(pl1.countPassenger < pl1.maxPassenger){ 
		pl1.countPassenger++; }
	else {
		cout << "Quantity of passengers is maximum for this plane!" << endl;
	}
	
}
void operator --(Airplane& pl1) {
	if (pl1.countPassenger > 0) {
		pl1.countPassenger--;
	}
	else {
		cout << "There is no passenger in this plane!" << endl;
	}
}
bool operator ==(Airplane& pl1, Airplane& pl2) {
	if (pl2.type == pl1.type) {
		return 1;
	}
	return 0;
}
bool operator <(Airplane& pl1, Airplane& pl2) {
	if (pl1.countPassenger < pl2.countPassenger) {
		return 1;
	}
	return 0;
}
bool operator >(Airplane& pl1, Airplane& pl2) {
	if (pl1.countPassenger > pl2.countPassenger) {
		return 1;
	}
	return 0;
}
ostream& operator << (ostream& out, Airplane& plane) {
	out << "Model: " << plane.model << endl;
	out << "Type: " << plane.type << endl;
	out << "Passengers in: " << plane.countPassenger << endl;
	out << "Max Passengers: " << plane.maxPassenger << endl;
	return out;
}
istream& operator >> (istream& in, Airplane& plane) {
	cout << " Enter Model: ";in >> plane.model;
	cout << " Enter Type: ";in >> plane.type;
	cout << " Enter Passengers in: ";in >> plane.countPassenger;
	cout << " Enter Max Passengers: ";in >> plane.maxPassenger;
	return in;
}

int main()
{

	Airplane plane("model", "1", 1, 1);
	Airplane plane2("model1", "2", 32, 44);
	/*cout << plane << endl;*/
	/*cout << string(plane) << endl;*/
	/*cin >> plane;
	cout << plane;*/
	cout << plane2;
	cout << endl;
	++(plane2);
	++(plane2);
	++(plane2);
	--(plane2);
	cout << plane2;
	cout << endl;
	if (plane < plane2) {
		cout << "plane1 have less passengers"<< endl;
	}
	else if(plane > plane2) {
		cout << "plane1 have more passengers" << endl;
	}
	cout << endl;
	plane2(7);
	cout << plane2;
	cout << endl;
	plane2(7);
	cout << endl;
	cout << plane2;
}