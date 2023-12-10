#include <iostream>
#include <conio.h>


extern "C" int __stdcall second_lab(int, int*);
extern "C" int __cdecl under(int, int*);
extern "C" int __fastcall joke(int*, int);

void print(int*& arr, const int& n) {
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	int n;
	std::cout << "Введите кол-во элементов:\n";
	std::cin >> n;
	int* arr = new int[n];
	std::cout << "Введите элементы:\n";
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	
	std::cout << "1 -> __stdcall\n2 -> __cdecl\n3 -> __fastcall\n";

	switch (_getch()) {
	case '1':
		second_lab(n, arr);
		print(arr, n);
		break;
	case '2':
		under(n, arr);
		print(arr, n);
		break;
	case '3':
		joke(arr, n);
		print(arr, n);
		break;
	default:
		std::cout << "unvalid";
	}

	std::cout << "\n";
	system("pause");
	return 0;
}