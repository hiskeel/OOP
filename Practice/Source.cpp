#include<iostream>
#include<map>
#include <list>
#include <string>
#include <fstream>
using namespace std;
int menu() {
	int choice = 0;
	cout << "Choose your action:\n1.Show full dictionary\n2.Add new word with translation\n3.Add translation to word\n4.Find translation of word\n5.Delete word with translation\n0.Exit" << endl;
	cin >> choice;
	cin.ignore();
	return choice;
}
class Dictionary {
private:
	string name;
	map<string, list<string>> words;
public:
	Dictionary(string name):name(name){}
	void Print() const {
		cout << name << endl;
		for (auto pair : words) {
			cout << pair.first << " - ";
			for (string t: pair.second) {
				cout << t << ", ";
			}
			cout << endl;
		}
	}
	void InsertWord(string word, list<string> translate) {
		words.insert(make_pair(word, list<string>( translate )));
	}
	void AddTranslation(string word, string translate) {
		words[word].push_back(translate);
	}
	bool IsExist(string word) {
		return words.find(word) != words.end();

	}
	void FindTranslation(string request)  {
		cout << request << " : ";
		for (string t : words[request]) {
			cout << t << " ";
		}
		cout << endl;
	}
	void DeleteWord(string request) {
		words.erase(request);
	}
	friend ostream& operator <<(ostream& out, Dictionary& d);
	friend istream& operator >> (istream& in, Dictionary& d);
};
ostream& operator <<(ostream& out, Dictionary& d) {
	out << d.name << endl;
	for (auto pair : d.words) {
		out << pair.first << endl;
		for (string t : pair.second) {
			out << t << endl;
		}
		out << "|" << endl;
	}
	return out;
}
istream& operator >> (istream& in, Dictionary& d) {
	getline(in, d.name);
	string word;
	string end = "|";
	while(!in.eof()) {
		getline(in, word);
		if (word.empty())break;
		list<string> list;
		string translate = end;
		do {
			getline(in, translate);
			if(translate != end)
				list.push_back(translate);
		} while (translate != end);
		d.words.insert(make_pair(word, list));
		
	}
	return in;
}

void main() {
	/*Dictionary dict("Eng-Ukr");
	dict.InsertWord("mind", { "rozym", "dymka" });
	dict.InsertWord("run", { "big","zapustutu", "keryvatu" });
	dict.InsertWord("ride", { "poyizdka", "oblava" });
	dict.InsertWord("make", { "robutu", "virib" });
	
	dict.Print();*/
	bool exit = false;
	Dictionary dict("");
	ifstream in("Dictionary.txt");
	in >> dict;
	int choice;
	cout << "Data succesfully loaded!";
	in.close();
	/*dict.Print();*/
	string word;
	list<string> list;
	string translate;
	while (!exit) {
		choice = menu();
		
		switch (choice) {
		case 1:
			system("cls");
			dict.Print();
			cout << endl;
			break;
		case 2:
			system("cls");
			cout << "Enter word you want to add: ";cin >> word;
			cin.ignore();
			if (dict.IsExist(word))cout << "Word is Already Exist!" << endl;
			else {
				do {
					cout << "Enter your translation: ";
					getline(cin, translate);
					/*cin.ignore();*/
					if(!translate.empty())list.push_back(translate);
					/*cin.ignore();*/
					
				} while (!translate.empty());
				dict.InsertWord(word, list);
			}
			cout << endl;
			break;
		case 3:
			system("cls");cout << "Enter word you want to add translation to: ";cin >> word;
			cin.ignore();
			if (!dict.IsExist(word))cout << "No word -" << word << " in your Dictionary!" << endl;
			else {
				do {
					cout << "Enter your translate: "; getline(cin, translate);
					if (!translate.empty())dict.AddTranslation(word, translate);
					
				} while (translate != "");

			}
			cout << endl;
			break;
		case 4:
			system("cls");
			cout << "Enter word you want to find: ";cin >> word;
			if (!dict.IsExist(word))cout << "No word -" << word << " in your Dictionary!" << endl;
			else {
				dict.FindTranslation(word);
			}
			cout << endl;
			break;
		case 5:
			system("cls");
			cout << "Enter word you want to delete: ";cin >> word;
			if (!dict.IsExist(word))cout << "No word -" << word << " in your Dictionary!" << endl;
			else {
				dict.DeleteWord(word);
			}
			cout << endl;
			break;
		case 0:
			system("cls");
			exit = true;
			cout << "Bye!" << endl;
			break;
		}


		
	}
	ofstream out("Dictionary.txt" );
	out << dict;
	out.close();
	
	
	//for (string str : dict["mind"]) {
	//	cout << str << " ";
	//}
	//cout << endl;

	//string input = "";
	//cout << "Enter word u want to translate: ";
	//getline(cin, input);
	//cin.ignore();

	//if (dict.find(input) == dict.end()) {
	//	cout << "Word " << input << " was not found!" << endl;
	//}
	//else {
	//	string translate = "";
	//	do {
	//		cout << "Enter translate: ";
	//		getline(cin, translate);
	//		dict[input].push_back(translate);
	//	} while (!translate.empty());
	//}
}