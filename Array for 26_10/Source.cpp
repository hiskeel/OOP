#include<iostream>

using namespace std;

class Array {
private:
	int* arr;
	int size;
public:
	Array(int size) {
		this->size = size;
		this->arr = new int[size];
		for (int i = 0; i < size;i++) {
			arr[i] = 0;
		}
		

	}
	Array(const Array& other) {
		this->size = other.size;
		this->arr = new int[other.size];
		for (int i = 0; i < this->size;i++) {
			arr[i] = other.arr[i];
		}
	
	}
	Array() {
		this->arr = nullptr;
		this->size = 0;
	}
	int GetSize() {
		return size;
	}
	void SetSize(int size) {
		this->size = size;
	}

	void FillArrayZero() {
		for (int i = 0; i < size; i++) {
			arr[i] = 0;
		}
	}
	void FillArrayRandom() {
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % 30;
		}
	}
	void FillArrayKeyboard() {
		for (int i = 0; i < size; i++) {
			cout << "arr[" << i << "]: ";
			cin >> arr[i];
		}
	}
	 void PrintArray() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";

		}
		cout << endl;
	}
	void AddToArray(int value) {
		int* temp;
		temp = new int[size + 1];
		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		temp[size] = value;
		delete[] arr;
		arr = temp;
		size++;
	}
	~Array() {
		delete[] arr;
	}
	void DeleteByIndex(int index) {
		int* temp;
		temp = new int[size - 1];
		for (int i = 0; i < size - 1; i++) {
			if (i < index) {
				temp[i] = arr[i];
			}
			else if (i >= index) {
				temp[i] = arr[i + 1];
			}
		}

		delete[] arr;
		arr = temp;
		size--;
	}
	void DeleteByValue(int value) {
		int* temp;
		int countValue = 0;
		temp = new int[size - 1];
		for (int i = 0; i < size - 1; i++) {
			if (arr[i] == value) {
				countValue++;
			}
			if (countValue < 1) {
				temp[i] = arr[i];
			}
			else if (countValue >= 1) {
				temp[i] = arr[i + 1];
			}
		}

		delete[] arr;
		arr = temp;
		size--;
	}
	void sortInc() {
		int temp = 0;
		for (int i = 0;i < size;i++) {
			for (int j = 0; j < size; j++) {
				if (arr[i] < arr[j]) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	void sortDec() {
		int temp = 0;
		for (int i = 0;i < size;i++) {
			for (int j = 0; j < size; j++) {
				if (arr[i] > arr[j]) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	void FindMax() {
		int max = arr[0];
		int index = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] > max) {
				max = arr[i];
				index = i;
			}
		}
		cout << "Max Value: " << max << "\nOn index: " << index << endl;
		
	}
	void FindMin() {
		int min = arr[0];
		int index = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] < min) {
				min = arr[i];
				index = i;
			}
		}
		cout << "Min Value: " << min << "\nOn index: " << index << endl;

	}
	void FindAVG() {
		int sum = 0;
		double res = 0;
		for (int i = 0; i < size; i++) {
			sum += arr[i];
		}
		res = sum / size;
		cout << "AVG: " << sum << " / " << size << " = " << res;
	}
};

void main() {
	srand(time(0));
	Array arr(5);
	arr.FillArrayRandom();
	Array arr2(arr);
	arr.PrintArray();
	cout << "\nCopied Array:" << endl;
	/*arr2.PrintArray();
	arr.PrintArray();
	arr.AddToArray(5);
	arr.PrintArray();
	arr.DeleteByIndex(1);
	arr.AddToArray(8);
	arr.PrintArray();
	arr.AddToArray(8);
	arr.AddToArray(8);
	arr.DeleteByValue(8);*/
	arr.PrintArray();
	arr.sortInc();
	arr.PrintArray();
	arr.sortDec();
	arr.PrintArray();
	arr.FindMax();
	arr.FindMin();
	arr.FindAVG();

}