#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Animal
{
    string name;
    string place;
    float weight;
public:
    Animal() :name("no name"), place("no place"), weight(0) {}
    Animal(string name, string place, float weight) :name(name), place(place)
    {
        this->weight = weight > 0 ? weight : 0;
    }
    void ShowInfo()const
    {
        cout << "Name : " << name << endl;
        cout << "Place : " << place << endl;
        cout << "Weight : " << weight << endl;
    }
    friend ostream& operator << (ostream& out, const Animal& animal);
    friend istream& operator >> (istream& in, Animal& animal);
};
ostream& operator << (ostream& out, const Animal& animal)
{
    out << animal.name << " " << animal.place << " " << animal.weight;
    return out;
}
istream& operator >> (istream& in, Animal& animal)
{
    in >> animal.name >> animal.place >> animal.weight;
    return in;
}
class Zoo
{
private:
    string name;
    Animal* animals;
    int countAnimal;
public:
    Zoo(string name) :name(name), animals(nullptr), countAnimal(0) {}
    void AddAnimal(Animal animal)
    {
        Animal* temp = new Animal[countAnimal + 1];
        for (int i = 0; i < countAnimal; i++)
        {
            temp[i] = animals[i];
        }
        temp[countAnimal] = animal;
        if (animals != nullptr)
            delete[]animals;
        countAnimal++;
        animals = temp;
    }
    void ShowZoo()const
    {
        cout << "----------------- " << name << "----------------" << endl;
        for (int i = 0; i < countAnimal; i++)
        {
            animals[i].ShowInfo();
            cout << endl;
        }
    }
    ~Zoo()
    {
        if (animals != nullptr) {
            
                delete[] animals;
            
        }
            
    }

    void Save()const
    {
        ofstream out("zoo.txt", ios_base::out);
        out << name << endl;
        out << countAnimal << endl;
        for (int i = 0; i < countAnimal; i++)
        {
            out << animals[i] << endl;
        }
        out.close();
    }
    void Load()
    {
        ifstream in("zoo.txt", ios_base::in);
        //char buff[255];
       // in.getline(buff, 255);
        getline(in, name);//in >> name;
        in >> countAnimal;
        if (animals != nullptr)
            delete[]animals;

        animals = new Animal[countAnimal];
        for (int i = 0; i < countAnimal; i++)
        {
            in >> animals[i];
        }
        in.close();

    }
    void SaveBinary()
    {
        ofstream out("Zoo.bin", ios_base::out | ios_base::binary);
        out.write((char*)&name, sizeof(name));
        out.write((char*)&countAnimal, sizeof(countAnimal));
        for (int i = 0; i < countAnimal; i++)
        {
            out.write((char*)&animals[i], sizeof(animals[i]));
        }
        out.close();
    }
    void LoadBinary()
    {
        ifstream in("Zoo.bin", ios_base::in | ios_base::binary);
        in.read((char*)&name, sizeof(name));
        in.read((char*)&countAnimal, sizeof(countAnimal));
        if (animals != nullptr)
            delete[]animals;

        animals = new Animal[countAnimal];
        for (int i = 0; i < countAnimal; i++)
        {
            in.read((char*)&animals[i], sizeof(animals[i]));
        }
        
        in.close();
    }

};


int main()
{/*
    Animal animal("Tom", "Flat", 6);
    animal.ShowInfo();*/

     /* Zoo zoo("Rivne Zoo");
      
      zoo.AddAnimal(Animal("Lion Alex", "Madagascar", 120));
      zoo.AddAnimal(Animal("Marty", "Madagascar", 90));
      zoo.AddAnimal(Animal("Shkiper", "Madagascar", 5));

      zoo.ShowZoo();
      zoo.SaveBinary();*/
      /* zoo.Save();
       Zoo zoo("Test");
       zoo.Load();
       zoo.ShowZoo();*/

    Zoo zoo("Test");
    zoo.LoadBinary();
    zoo.ShowZoo();

}