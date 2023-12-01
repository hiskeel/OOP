#include <iostream>
#include <vector>
#include<random>

using namespace std;


class Animal {
protected:
    string habitat;

public:
    Animal(const string& habitat) : habitat(habitat) {}

    virtual void eat() const = 0;
    virtual void die() const = 0;

    virtual ~Animal() {}
};

class Plant {
public:
    virtual void grow() const = 0;
    virtual ~Plant() {}
};

class Rabbit : public Animal {
public:
    Rabbit(const string& habitat) : Animal(habitat) {}

    void eat() const override {
        cout << "Rabbit is eating grass." << endl;
    }

    void die() const override {
        cout << "Rabbit has died." << endl;
    }
};

class Fox : public Animal {
private:
    int age;

public:
    Fox(const string& habitat, int age) : Animal(habitat), age(age) {}

    void eat() const override {
        cout << "Fox is eating rabbit." << endl;
    }

    void die() const override {
        cout << "Fox has died." << endl;
    }

    int getAge() const {
        return age;
    }
};

class Grass : public Plant {
public:
    void grow() const override {
        cout << "Grass is growing." << endl;
    }
};

class Life {
    vector <Rabbit> rabbits;
    vector <Fox> foxes;
    vector <Grass> grass;
public:
    void InitLife() {
        srand(time(NULL));
        for (int i = 0; i < 15; i++) {

            Grass g;
            Rabbit r("Forest");
            Fox f("Forest", 1 + rand() % 15);
            if (foxes.size() <= 5) {
                int random = 1 + rand() % 3;
                switch (random) {
                case 1:
                    rabbits.push_back(r);
                    break;
                case 2:
                    foxes.push_back(f);
                    break;
                case 3:
                    grass.push_back(g);
                    break;
                default:
                    break;
                }
            }
            else {
                int random = 1 + rand() % 2;
                switch (random) {
                case 1:
                    rabbits.push_back(r);
                    break;
                case 2:
                    grass.push_back(g);
                    break;
                default:
                    break;
                }
            }

        }

    }
    void LifeCircle() {
        for (int i = 0; i < foxes.size(); i++) {
            if (foxes[i].getAge() >= 12) foxes.erase(foxes.begin() + i);
        }
        if (foxes.size() > rabbits.size()) {
            foxes[0].eat();
            cout << "";
        }
        else if (rabbits.size() > grass.size()) {
            rabbits[0].eat();
        }
        else {
            cout << "Only grass lefted." << endl;
        }

    }
};

void main() {


    Life l;
    l.InitLife();
    l.LifeCircle();
}