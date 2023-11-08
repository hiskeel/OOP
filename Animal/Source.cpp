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
	string movment;
	string voice;

};

void main() {


}