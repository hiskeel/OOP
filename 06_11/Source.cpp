#include <iostream>
#include <string>
#include<random>


using namespace std;


template <class T>

class Array
{
private:
    int m_length;
    T* arr;

public:
    Array()
    {
        m_length = 0;
        arr = nullptr;
    }

    Array(initializer_list<T> list)
    {
        m_length = list.size();
        arr = new T[m_length];
        int i = 0;
        for (const auto& item : list) {
            arr[i] = item;
            ++i;
        }
    }
    Array(T value) {
        Add(value);
    }

    ~Array()
    {
        delete[] arr;
    }

    void Erase()
    {
        delete[] arr;
        arr = nullptr;
        m_length = 0;
    }
    void Add(T value) {
        T* temp = new T[m_length + 1];
        for (int i = 0; i < m_length; i++) {
            temp[i] = arr[i];
        }
        temp[m_length] = value;
        delete[]arr;
        arr = temp;
        m_length++;
    }
    int Size() {
        return m_length;
    }
    void Print()const
    {
        for (int i = 0; i < m_length; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

    }

    T& operator[](int index)
    {
        if (index >= 0 && index < m_length) {
            return arr[index];
        }
    }
};
template <typename T>
T FindMax(Array<T>& arr)
{
    T maxVal = arr[0];
    for (int i = 1; i < arr.Size(); ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}
template <typename T>
T FindMin(Array<T>& arr)
{
    T minVal = arr[0];
    for (int i = 1; i < arr.Size(); ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}
template <typename T>
void SortArray(Array<T>& arr)
{
    int n = arr.Size();

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
template <typename T>
int BinarySearch(Array<T>& arr, T key)
{
    int left = 0;
    int right = arr.Size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

template <typename T>
void ReplaceElement(Array<T>& arr, int index, T value)
{
    if (index >= 0 && index < arr.Size()) {
        arr[index] = value;
    }
}




void main() {
    srand(time(NULL));
    Array<int> arr = Array<int>();
    for (int i = 0; i <= 10; i++) {
        arr.Add(1 + rand() % 100);
    }
    arr.Print();
    cout << "=========================" << endl;
    cout << "Min value: " << FindMin(arr) << endl;
    cout << "Max value: " << FindMax(arr) << endl;
    cout << "=========================" << endl;
    ReplaceElement(arr, 1, 7);
    arr.Print();
    SortArray(arr);
    arr.Print();
    cout << "Binary search result is in element #: " << BinarySearch(arr, 7);

    //arr.Print();
}