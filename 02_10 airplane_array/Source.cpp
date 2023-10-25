#include <iostream>
#include<string>

using namespace std;
class Array
{
private:
    int size;
    int* arr;
public:
    Array()
    {
        arr = nullptr;
        size = 0;
    }
    explicit Array(int size)
    {
        this->size = size;
        arr = new int[size];
        /* for (int i = 0; i < size; i++)
         {
             arr[i] = rand() % 30;
         }*/
    }
    Array(int size, int a)
    {
        this->size = size;
        arr = new int[size];
        /* for (int i = 0; i < size; i++)
         {
             arr[i] = rand() % 30;
         }*/
    }
    ~Array()
    {
        delete[]arr;
    }

    int getSize()const
    {
        return size;
    }
    void setArray(int value, int index)
    {
        arr[index] = value;
    }
    void display(int index)const
    {
        cout << arr[index] << " ";
    }
    void operator()(int count)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] += count;
        }
    }
    void operator()(int count, int number)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == number)
                arr[i] += count;
        }
    }
    int operator[](int index)//71
    {
        if (index < 0 || index >= size) return 0;
        return arr[index];
    }
    explicit operator int()
    {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum;
    }
    explicit operator string()
    {
        string res;
        for (int i = 0; i < size; i++) {
            res += to_string(arr[i]) + " ";
        }
        return res;
    }

};
void Display(const Array& arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        arr.display(i);
    }
    cout << endl;
}

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
    friend ostream& operator << (ostream& out, Airplane& plane);
    friend istream& operator >> (istream& in, Airplane& plane);

    friend bool operator ==(Airplane& pl1, Airplane& pl2);

};
bool operator ==(Airplane& pl1, Airplane& pl2) {
    if (pl2.type == pl1.type) {
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
    /*cout << plane << endl;*/
    cout << string(plane) << endl;
    cin >> plane;
    cout << plane;

    Array arr(10);
    int size = arr.getSize();
    for (int i = 0; i < arr.getSize(); i++)
    {
        arr.setArray(i + 1, i);
    }
    Display(arr);

    int sum = int(arr);
    cout << "Sum of elements in array = " << sum;
    cout << endl;
    string myStr = string(arr);

    cout << myStr;
}