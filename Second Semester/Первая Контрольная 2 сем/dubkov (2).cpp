#include "Translator.h"

using std::cout;

void first_compare(Literary& a, Literary& b) {
	cout << "Hello, this is my control work\n";
	Sleep(3000);
	system("cls");
	cout << "Now we will compare 2 objects of the same class . . . \n";
	Sleep(3000);
	system("cls");
	if (a == b) {
		cout << "Yeah, they are similar" << "\n";
	}
	else {
		cout << "They are not similar" << "\n";
	}
	Sleep(3000);
	system("cls");
}

void second_compare(Literary& a, Translator& c) {
	cout << "Now we will compare 2 objects of different classes . . . \n";
	Sleep(3000);
	system("cls");
	if (a == c) {
		cout << "Yeah, they are similar" << "\n";
	}
	else {
		cout << "They are not similar" << "\n";
	}
	Sleep(4000);
	
}


void init(Literary**& arr) {
	arr = new Literary * [4];
	arr[0] = new Literary("name", 213, Type::other);
	arr[1] = new Literary("Asya", 22, Type::roman);
	arr[2] = new Translator("Trans", 123, 4, Type::story, 3);
	arr[3] = new Translator("asdf", 22, 4, Type::poem,3);
}


void count(Literary** arr) {
	system("cls");
	cout << "Now we will count a little bit . . . \n";
	Sleep(4000);
	system("cls");

	auto oth = count_if(arr, arr + 4, [](Literary* a) {

		return a->GetType() == Type::other;

		});

	auto rom = count_if(arr, arr + 4, [](Literary* a) {

		return a->GetType() == Type::roman;

		});
	auto poe = count_if(arr, arr + 4, [](Literary* a) {

		return a->GetType() == Type::poem;

		});

	auto st = count_if(arr, arr + 4, [](Literary* a) {

		return a->GetType() == Type::story;

		});
	cout << "\n";
	cout << "Genre -> other: " << oth << "\n";
	cout << "Genre -> roman: " << rom << "\n";
	cout << "Genre -> poem:  " << poe << "\n";
	cout << "Genre -> story: " << st << "\n";
	cout << "\n\n";
	Sleep(4000);
	system("cls");
}

void obj(Literary** arr) {
	
	int count1 = 0, count2 = 0;

	for (int i = 0; i < 4; i++)
	{
		if (!strcmp(typeid(*arr[i]).name(), "class Literary"))
			count1++;
		else
			count2++;
	}

	cout << "\nObjects class Literary: " << count1 << "\nObjects class Translator: " << count2;

	cout << "\n\n";
	Sleep(4000);
	system("cls");
}

void print(Literary** arr) {
	for (ptrdiff_t i = 0; i < 4; ++i) {
		cout << "\n";
		arr[i]->print(cout);
		cout << "\n";
	}
}

void great(Literary** arr) {

	system("cls");
	cout << "Sorted in ascending order\n" ;

	sort(arr, arr + 4, [](Literary* a, Literary* b)->bool {
		
		return a->getName() < b->getName();
		
		});

	print(arr);
	Sleep(4000);
	system("cls");
}

void second_great(Literary** arr) {

	cout << "Looking for a match\n";

	bool flag = false;
	for (int i = 0; i < 4; i++) {
		Translator* p = dynamic_cast<Translator*>(arr[i]);
		if (p) {
			if(p->GetYear() == arr[i]->GetYear()){
				flag = true;
				sort(arr, arr + 4, [](Literary* a, Literary* b)->bool {
					return a->getName()> b->getName();
					});
				cout << "\n";
				p->print(cout);
				cout << "\n";
			}
			else {
				flag = false;
			}
			
		}
	}

	
	if (flag == false) {
		cout << "No Matches found" << '\n';
	}

}


void parameterization(Literary** arr) {
	cout << "Input year:\n";
	int year;
	cin >> year;
	assert(year > 0);
	bool check = false;
	for (int i = 0; i < 4; i++) {
		Translator* p = dynamic_cast<Translator*>(arr[i]);
		if (p) {
			if (p->GetYear() < year) {
				cout << "\n";
				p->print(cout);
				cout << "\n";
				check = true;
			}
		}
	}
	if (check == false)
	cout << "\nThere are no transfers after the specified year, sorry\n";
}



void menu() {

	Literary a("names", 213, Type::poem);
	Literary b("ehji", 66, Type::story);

	Translator c("Nas", 213, 4, Type::roman, 7);

	first_compare(a, b);
	
	second_compare(a, c);

	Literary** arr = 0;

	init(arr);
	
	count(arr);

	obj(arr);

	great(arr);

	second_great(arr);

	parameterization(arr);

}



int main() {
	try
	{
		menu();
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}
	
	cout << "\n";
	system("pause");
	return EXIT_SUCCESS;
}