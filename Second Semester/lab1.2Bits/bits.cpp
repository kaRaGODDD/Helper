#include <iostream>
#include <conio.h>
#include <map>
#include <string>
#include <Windows.h>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <bitset>
#define br '\n'

using namespace std;

void InputDimension(size_t& sz) {
	
	
		cout << "Input dimension ot the array" << br;

		cin >> sz;

		if (sz <= 0) {
			throw exception ("Invalid dimension, try again...");
		}

		cout << br;

}

template<typename T>
void init(T*& arr, const size_t& sz) {
	arr = new T[sz];
}

template<>
void init(char*& str, const size_t& sz) {
	str = new char [sz];
}

void Random(int* arr, const size_t& sz) {

	cout << "You random array is " << br;

	for (int i = 0; i < sz; ++i) {
		arr[i] = rand() % 100;
	}

	for (int i = 0; i < sz; ++i) {
		cout << arr[i] << ' ';
	}
}

void ConvertingInt(int* arr, const size_t& sz, bitset<sizeof(char) * 8>& bits, size_t& count, string path, fstream& buffer, map<string, size_t>& FirstMap) {

	buffer.open(path, ios::out);

	cout << br << br;

	cout << "And how does it look like in bits ?" << br << br;

	Sleep(4000);
	for (int i = 0; i < sz; ++i) {
		bits = arr[i];
		count = bits.count();
		cout << bits << ' ' << count << ' ' << arr[i] << br;
		buffer << arr[i] << ' ' << count << br;
	}

	cout << br << br << br;

	buffer.close();

	buffer.open(path, ios::in);

	cout << "And the minimum amount of null is.. " << br << br;

	Sleep(4000);

	string key;
	size_t value;

	while (buffer >> key >> value) {
		FirstMap[key] = value;
	}

	cout << max_element(FirstMap.begin(), FirstMap.end(),
		[](const pair<string, int> A, pair<string, int> B)
		{
			return A.second < B.second;
		}
	)->first << std::endl;
}

void DoubleRandom(double* a, const size_t& sz) {

	cout.precision(4);

	cout << "Your random array is " << br;
	for (size_t i = 0; i < sz; ++i) {
		a[i] = ((double)rand() / RAND_MAX) * 100;
		cout <<fixed << setprecision(4) << a[i] << ' ';
	}

}

void ConvertingDouble(double* a, const size_t& sz, bitset<sizeof(char) * 8>& bits, size_t& count, string path, fstream& buffer, map<string, size_t>& SecondMap, double* copy, double* without, double* inpt, size_t& other_count, bitset<sizeof(char) * 8>& bit, int* all, double* strange,double* overview)
{
	buffer.open(path, ios::out);

	strange = new double[sz];
	all = new int[sz];
	overview = new double[sz];
	inpt = new double[sz];
	copy = new double[sz];
	without = new double[sz];

	for (size_t i = 0; i < sz; ++i) {
		inpt[i] = a[i];
		overview[i] = a[i];
		strange[i] = a[i];
		a[i] = modf(a[i], &a[i]);
		copy[i] = a[i];
		copy[i] *= 10000; // мантисса в copy[i]		
	}

	cout << br << br;


	for (size_t i = 0; i < sz; ++i) {
		inpt[i] = static_cast<int>(inpt[i]); // инты тут
	}



	cout << "Do you would like to see how the integer part is look like in bits?" << br << br;

	Sleep(5500);

	for (size_t i = 0; i < sz; ++i) {
		bit = inpt[i];
		cout << bit << br;

	}


	cout << br << "And do you would like to see how the mantissa look like in bits?" << br << br;

	Sleep(5500);

	for (size_t i = 0; i < sz; ++i) {
		bits = copy[i];
		cout << bits << br;
	}


	cout << br << "All overwiev is " << br << br;

	Sleep(5500);

	for (size_t i = 0; i < sz; ++i) {
		bit = inpt[i];
		bits = copy[i];
		cout << bit << "." << bits<<" -> " << overview[i] << br;
	}


	for (size_t i = 0; i < sz; ++i) {
		bit = inpt[i];
		count = bit.count();
		bits = copy[i];
		other_count = bits.count();
		all[i] = count + other_count; // значение в map
		buffer << strange[i] << ' ' << all[i] << br;
	}

	buffer.close();

	buffer.open(path, ios::in);


	string key;
	size_t value;

	while (buffer >> key >> value) {
		SecondMap[key] = value;
	}

	cout << br << br << "And with min amount of nulls is " << br;

	cout << max_element(SecondMap.begin(), SecondMap.end(),
		[](const pair<string, int> A, pair<string, int> B)
		{
			return A.second < B.second;
		}
	)->first << std::endl;

}

void CharRandom(char* str, const size_t& sz) {

	cout << "Your random char is " << br;

	for (size_t i = 0; i < sz; ++i) {
		str[i] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm"[(rand() % 52)];
		cout << str[i] << ' ';
	}

	cout << br;
}

void ConvertingChar(char* str, const size_t& sz, int* converting, bitset<sizeof(char) * 8>& bits, size_t& count, fstream& buffer, string& path, map<string, size_t>& FirstMap) {

	buffer.open(path, ios::out);

	converting = new int[sz];

	cout << br << "And how does it look like in accordance with ASCII table?" << br;

	for (size_t i = 0; i < sz; ++i) {
		converting[i] = static_cast<int>(str[i]);
		cout << converting[i] << ' ';
	}

	Sleep(4000);

	cout << br;

	cout << br << br << "And how does it look like in bits?" << br << br;

	for (size_t i = 0; i < sz; ++i) {
		bits = converting[i];
		count = bits.count();
		cout << bits << ' ' << count << ' ' << str[i] << br;
		buffer << str[i] << ' ' << count << br;
	}

	buffer.close();


	buffer.open(path, ios::in);


	cout <<br << "And the minimum amount of null is.. " << br << br;

	Sleep(4000);

	string key;
	size_t value;

	while (buffer >> key >> value) {
		FirstMap[key] = value;
	}

	cout << max_element(FirstMap.begin(), FirstMap.end(),
		[](const pair<string, int> A,const pair<string, int> B)
		{
			return A.second < B.second;
		}
	)->first << std::endl;




}

void DelDouble(double* a, double* copy, double* without, double* inpt, int* all, double* strange, double* overview) {
	delete[] a;
	delete[] copy;
	delete[]without;
	delete[]inpt;
	delete[]all;
	delete[]strange;
	delete[]overview;
}

void DelInt(int* arr) {
	delete[]arr;
}

void DelChar(char* str) {
	delete[]str;
}

void menu()
{
	
	try
	{
		srand(time(NULL));
		fstream buffer;
		string path = "text.txt";
		map<string, size_t> FirstMap;
		map<string, size_t> SecondMap;
		size_t sz;
		size_t other_count;
		size_t count;
		bitset <sizeof(char) * 8> bits;
		bitset<sizeof(char) * 8> bit;
		int* arr = 0;
		double* a;
		double* strange = 0;
		int* all = 0;
		double* copy = 0;
		double* without = 0;
		double* inpt = 0;
		double* overview = 0;
		int* converting = 0;
		char* str = 0;

		cout << "Type 1: Integer implementation" << br << "Type 2: Double  implementation" << br << "Type 3: Char    implementation" << br;

		switch (_getch())
		{
		case '1':
			system("cls");
			InputDimension(sz);
			init(arr, sz);
			Random(arr, sz);
			ConvertingInt(arr, sz, bits, count, path, buffer, FirstMap);
			DelInt(arr);
			break;
		case '2':
			system("cls");
			InputDimension(sz);
			init(a, sz);
			DoubleRandom(a, sz);
			ConvertingDouble(a, sz, bits, count, path, buffer, FirstMap, copy, without, inpt, other_count, bit, all, strange,overview);
			DelDouble(a, copy, without, inpt, all, strange, overview);
			break;
		case '3':
			system("cls");
			InputDimension(sz);
			init(str, sz);
			CharRandom(str, sz);
			ConvertingChar(str, sz, converting, bits, count, buffer, path, FirstMap);
			DelChar(str);
			break;
		default:
			system("cls");
			cout << "You press unvalid key, try again..." << br;
			Sleep(4000);
			system("cls");
			menu();
		}
	}
	catch (const exception& ex)
	{
		cout << ex.what();
	}
	
}


int main() {

  
	menu();

	cout << br;
	system("pause");
	return EXIT_SUCCESS;
}