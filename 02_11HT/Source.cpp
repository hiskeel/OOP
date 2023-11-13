#include <iostream>

using namespace std;

class Date {
private:
	int days; // avg value for month 30 days
	int month;
	int year;
public:
	Date() {
		days = 0;
		month = 0;
		year = 0;
	}
	Date(int days, int month, int year) {
		this->days = days;
		this->month = month;
		this->year = year;
	}
	void ShowDate() {
		cout << days << "." << month << "." << year << endl;
	}
	void AddDays(int countD) {
		
		days += countD;
		int mon = days / 30;
		if (mon > 0) {
			month += mon;
			days = days % 30;
		}
	}
	void DecDays(int countD) {
		
		days -= countD;
		
		if (days < 0) {
			month--;
			int mon = days*-1/30;
			month -= mon;
			days = 30 - days * -1 % 30;
		}
	}
	void operator ++() {

		if(days <30)days++;
		else {
			days = 1;
			month++;
			if (month > 12) {
				year++;
				month = 1;
			}
		}
	}
	void operator --() {
		if (days > 1)days--;
		else {
			days = 30;
			month--;
			if (month < 1) {
				year--;
				month = 12;
			}
		}
	}
	friend bool operator ==(Date date, Date other);
	friend bool operator !=(Date date, Date other); 
	friend bool operator <(Date date, Date other);
	friend bool operator >(Date date, Date other);
	
};
bool operator !=(Date date, Date other) {
	return date.year != other.year || date.month != other.month || date.days != other.days;
}
bool operator ==(Date date, Date other) {
	return date.year == other.year && date.month == other.month && date.days == other.days;
}
bool operator <(Date date, Date other) {
	if (date.year < other.year)return true;
	else if (date.year == other.year && date.month < other.month)return true;
	else if (date.year == other.year && date.month == other.month && date.days < other.days)return true;
	else { return false; }
}
bool operator >(Date date, Date other) {
	if (date.year > other.year)return true;
	else if (date.year == other.year && date.month > other.month)return true;
	else if (date.year == other.year && date.month == other.month && date.days > other.days)return true;
	else { return false; }
}


Date operator +=(Date date, int value) {
	date.AddDays(value);
	return date;
}
void operator -=(Date date, int value) {
	date.DecDays(value);
}
void main() {
	Date date(20, 11, 2022);
	date.ShowDate();
	
	date.ShowDate();
}