#include <iostream>
#include <string>

using namespace std;

// Клас, що представляє водія
class Driver {
private:
    string name;
    string surname;
    int age;
    int drivingExperience;
public:
    Driver(const string& name, const string& surname, int age, int drivingExperience)
        : name(name), surname(surname), age(age), drivingExperience(drivingExperience) {}

    void ShowDriverInfo() const {
        cout << "Driver Information:\n";
        cout << "Name: " << name << "\n";
        cout << "Surname: " << surname << "\n";
        cout << "Age: " << age << " years\n";
        cout << "Driving Experience: " << drivingExperience << " years\n";
    }

};

// Клас, що представляє автомобіль
class Car {
private:
    string engine;
    string body;
    string wheels;
    string doors;
    string transmission;
    string lights;
    string brand;
    string model;
    int year;
    Driver* driver;
public:
    // Конструктор за замовчуванням
    Car() : driver(nullptr) {}

    // Конструктор з параметрами
    Car(const string& engine, const string& body, const string& wheels,
        const string& doors, const string& transmission, const string& lights,
        const string& brand, const string& model, int year)
        : engine(engine), body(body), wheels(wheels), doors(doors), transmission(transmission),
        lights(lights), brand(brand), model(model), year(year), driver(nullptr) {}

    // Перевантажений конструктор для додавання водія через параметр
    Car(const string& engine, const string& body, const string& wheels,
        const string& doors, const string& transmission, const string& lights,
        const string& brand, const string& model, int year, Driver* driver)
        : engine(engine), body(body), wheels(wheels), doors(doors), transmission(transmission),
        lights(lights), brand(brand), model(model), year(year), driver(driver) {}

    // Метод для додавання водія через виклик методу
    void AddDriver(Driver* newDriver) {
        driver = newDriver;
    }

    // Метод для відображення інформації про автомобіль та водія (якщо він є)
    void Show() const {
        cout << "Car Information:\n";
        cout << "Brand: " << brand << "\n";
        cout << "Model: " << model << "\n";
        cout << "Year: " << year << "\n";
        cout << "Engine: " << engine << "\n";
        cout << "Body: " << body << "\n";
        cout << "Wheels: " << wheels << "\n";
        cout << "Doors: " << doors << "\n";
        cout << "Transmission: " << transmission << "\n";
        cout << "Lights: " << lights << "\n";

        if (driver) {
            driver->ShowDriverInfo();
        }
        else {
            cout << "No driver information available.\n";
        }
    }

};

int main() {
    // Створення водія
    Driver driver("John", "Doe", 30, 5);

    // Створення автомобіля та додавання водія через конструктор
    Car carWithDriver("V8", "Sedan", "18-inch Alloy", "4", "Automatic", "LED", "Toyota", "Camry", 2022, &driver);

    // Створення автомобіля та додавання водія через метод
    Car carWithoutDriver("V6", "SUV", "20-inch Alloy", "5", "Manual", "Xenon", "Honda", "CR-V", 2023);
    carWithoutDriver.AddDriver(&driver);

    // Виведення інформації про автомобілі
    carWithDriver.Show();
    cout << "\n";
    carWithoutDriver.Show();

    return 0;
}