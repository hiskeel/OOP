#include<iostream>

using namespace std;

class Animal {
protected:
	string type;
	float speed;
	float weight;
	string env;
public:
	Animal():type("type"),speed(0),weight(0),env("Envirment") {}
	Animal(string t, float s, float w, string e): type(t), speed(s), weight(w), env(e){}
	void Move() {
		cout << type << " moving with speed: " << speed << "km/h" << endl;
		cout << "Way of movement: ";
	}
	void Show() {
		cout << "Type: " << type << "\nSpeed: " << speed << " km/h\nWeight: " << weight << "kg.\nEnviroment: " << env << endl;
	}
	void Voice() {
		cout << type << " is ";
	}
};

class Bird : public Animal {
private:
	string movement;
	string voice;
public:
	Bird():movement("movement"), voice("voice"),Animal(){}
	Bird(string t, float s, float w, string e, string movment, string voice):movement(movment), voice(voice), Animal(t,s,w,e){}
	void Show() {
		Animal::Show();
		cout << "Movement: " << movement << "\nVoice: " << voice << endl;
	}
	void Voice() {
		Animal::Voice();
		cout << voice <<"ing" << endl;
	}
	void Move() {
		Animal::Move();
		cout << movement << endl;
	}
	

};
class Fish : public Animal {
private:
	string movement;
	string voice;
public:
	Fish() :movement("movement"), voice("voice"), Animal() {}
	Fish(string t, float s, float w, string e, string movment, string voice) :movement(movment), voice(voice), Animal(t, s, w, e) {}
	void Show() {
		Animal::Show();
		cout << "Movement: " << movement << "\nVoice: " << voice << endl;
	}
	void Voice() {
		Animal::Voice();
		cout << voice << "ing" << endl;
	}
	void Move() {
		Animal::Move();
		cout << movement << endl;
	}


};
class Reptile : public Animal {
private:
	string movement;
	string voice;

public:
	
	Reptile() :movement("movement"), voice("voice"), Animal() {}
	Reptile(string t, float s, float w, string e, string movment, string voice) :movement(movment), voice(voice), Animal(t, s, w, e) {}
	void Show() {
		Animal::Show();
		cout << "Movement: " << movement << "\nVoice: " << voice << endl;
	}
	void Voice() {
		Animal::Voice();
		cout << voice << "ing" << endl;
	}
	void Move() {
		Animal::Move();
		cout << movement << endl;
	}


};

void main() {

	Bird gorobec("Sparrow", 20, 0.1, "Everywere", "Fly", "Cvirk");
	gorobec.Show();
	cout << "-----------------" << endl;
	gorobec.Voice();
	cout << "-----------------" << endl;
	gorobec.Move();
	cout << "\n\n==================" << endl;
	Reptile rept("frog", 8, 0.2, "Swamp", "povz", "kvak");
	rept.Show();
	cout << "-----------------" << endl;
	rept.Voice();
	cout << "-----------------" << endl;
	rept.Move();
	cout << "\n\n==================" << endl;
	Fish karac("Karac", 10, 0.3, "water", "swim", "splash");
	karac.Show();
	cout << "-----------------" << endl;
	karac.Voice();
	cout << "-----------------" << endl;
	karac.Move();
}