#include <iostream>
#include <string>

using namespace std;

struct Date {
    int day;
    string month;
    int year;
};

class Student {
private:
    string name;
    string surname;
    string lastname;
    Date birthday;
    unsigned long phone;
    string city;
    string country;
    string unv_name;
    string unv_city;
    string unv_country;
    string group_name;
    int* marks;
    int count_marks;
    float avg;
    void SetAverage() {
        float sum = 0;
        for (int i = 0; i < count_marks; i++) {
            sum += marks[i];
        }
        avg = (float)sum / count_marks;
    }
public:
    Student() {
        name = "no name";
        surname = "no surname";
        lastname = "no lastname";
        birthday = { 0, "no month", 0 };
        phone = 0;
        city = "no city";
        country = "no country";
        unv_name = "no unv name";
        unv_city = "no unv city";
        unv_country = "no unv country";
        group_name = "no group name";
        marks = nullptr;
        count_marks = 0;
        avg = 0;
    }

    Student(string name, string surname, string lastname) {
        this->name = name;
        this->surname = surname;
        this->lastname = lastname;

    }

    void InitFromKeyboard() {
        cout << "Enter a name of student: ";
        getline(cin, name);
        cout << "Enter a surname of student: ";
        getline(cin, surname);
        cout << "Enter a lastname of student: ";
        getline(cin, lastname);
        cout << "Enter a day of the birthday: ";
        cin >> birthday.day;
        cout << "Enter a month of the birthday: ";
        cin >> birthday.month;
        cout << "Enter a year of the birthday: ";
        cin >> birthday.year;
        cout << "Enter a phone number: ";
        cin >> phone;
        cin.ignore();
        cout << "Enter a city: ";
        getline(cin, city);
        cout << "Enter a country: ";
        getline(cin, country);
        cout << "Enter a university name: ";
        getline(cin, unv_name);
        cout << "Enter a university city: ";
        getline(cin, unv_city);
        cout << "Enter a university country: ";
        getline(cin, unv_country);
        cout << "Enter a group name: ";
        getline(cin, group_name);
    }

    void Print() {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Last name: " << lastname << endl;
        cout << "Birthday: " << birthday.day << " " << birthday.month << " " << birthday.year << endl;
        cout << "Phone number: " << phone << endl;
        cout << "City: " << city << endl;
        cout << "Country: " << country << endl;
        cout << "University name: " << unv_name << endl;
        cout << "University city: " << unv_city << endl;
        cout << "University country: " << unv_country << endl;
        cout << "Group name: " << group_name << endl;
        cout << "Rating: " << avg << endl;
        cout << "Marks: " << endl;
        for (int i = 0; i < count_marks; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }

    void AddMark(int mark) {
        int* temp = new int[count_marks + 1];
        for (int i = 0; i < count_marks; i++) {
            temp[i] = marks[i];
        }
        temp[count_marks] = mark;
        if (marks != nullptr) {
            delete[]marks;
        }
        count_marks++;
        marks = temp;
        SetAverage();
    }

    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    void setSurname(string surname) {
        this->surname = surname;
    }

    string getSurname() {
        return surname;
    }

    void setLastname(string lastname) {
        this->lastname = lastname;
    }

    string getLastname() {
        return lastname;
    }

    void setBirthday(Date b) {
        birthday.day = b.day;
        birthday.month = b.month;
        birthday.year = b.year;
    }

    Date getBirthday() {
        return birthday;
    }

    void setPhone(unsigned long phone) {
        this->phone = phone;
    }

    unsigned long getPhone() {
        return phone;
    }

    void setCity(string city) {
        this->city = city;
    }

    string getCity() {
        return city;
    }

    void setCountry(string country) {
        this->country = country;
    }

    string getCountry() {
        return country;
    }

    void setUnvName(string unv_name) {
        this->unv_name = unv_name;
    }

    string getUnvName() {
        return unv_name;
    }

    void setUnvCountry(string unv_country) {
        this->unv_country = unv_country;
    }

    string getUnvCountry() {
        return unv_country;
    }

    void setGroupName(string group_name) {
        this->group_name = group_name;
    }

    string getGroupName() {
        return group_name;
    }

    void Init() {
        name = "no name";
        surname = "no surname";
        lastname = "no lastname";
        birthday = { 0, "no month", 0 };
        phone = 0;
        city = "no city";
        country = "no country";
        unv_name = "no unv name";
        unv_city = "no unv city";
        unv_country = "no unv country";
        group_name = "no group name";
    }

    ~Student() {
        cout << "Desctructor" << name << endl;
    }

};

/*Створити клас Rectangle, який буде описувати прямокутник.
  * Клас містить розміри: ширина, висота, символ, який відображатиме
  * прямокутник на екрані та координати розміщення. Для збереження
  * координат створити структуру Coord, яка міститиме X та Y координату.

 Клас повинен містити наступні конструктори:

 Конструктор по замовчуванню, який встановлюватиме «дефолтні» дані
 Параметризований конструктор, який приймає один параметр «розмір» та
  ініціалізує ним ширину та висоту
 Параметризований конструктор, який приймає два параметри «ширину» та «висоту»,
  які являються розмірами об’єкта

 Та наступні методи:

 Вивід фігури на екран, відповідного розміру, символом та у
  відповідних координатах
 Зміна розміру прямокутника. Метод приймає два парметри:
  1 – зміна висоти, 2 – ширини
 Переміщення прямокутника. Метод приймає два парметри: 1 – величина переміщення
  по осі X, 2 – по осі Y

 Методи повинні включати перевірку на коректність даних (від’ємна ширина,
  координати і тд). Створити екземпляр об’єкту та протестувати написаті методи.*/

struct Coord {
    int x;
    int y;
};

class Rectangle {
private:
    int width;
    int height;
    char symbol;
    Coord coordinates;
public:

    Rectangle() {
        width = 0;
        height = 0;
        symbol = ' ';
        coordinates.x = 0;
        coordinates.y = 0;
    }

    Rectangle(int width, int height, char symbol) {
        this->width = width;
        this->height = height;
        this->symbol = symbol;
        coordinates.x = 0;
        coordinates.y = 0;
    }

    void Print() {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                cout << symbol << " ";
            }
            cout << endl;
        }
    }

    void ChangeSize(int width, int height) {
        if (width >= 0 && height >= 0) {
            this->width = width;
            this->height = height;
        }
        else {
            this->width = 0;
            this->height = 0;
        }

    }

};

int main() {
    //    Student st;
    //    st.Init();
    //    st.setName("misha");
    //    //st.Print();
    //
    //    Student st2("Oleg", "Vinnyk", "Mykolayovych");
    //
    //    st2.Print();
    //    st2.AddMark(5);
    //    st2.AddMark(4);
    //    st2.Print();

    Rectangle a(10, 10, '*');
    Rectangle b(5, 7, '&');
    a.Print();
    b.Print();

    cout << endl;
    a.ChangeSize(10, 5);
    a.Print();

    return 0;
}