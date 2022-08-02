#include "MageCharacter.h"



void SetInf(Character& mage) {

	cout << "Set info for character . . . ";

	mage.SetMove(true);
	mage.SetName("Yennefer");
	mage.SetRace(Race::elf);
	mage.SetState(State::normal);

	Sleep(3000);
	std::system("cls");

}

void GetMethod(Character& mage) {

	cout << "ID: " << mage.GetID() << '\n';
	cout << "Name: " << mage.GetName() << '\n';

	switch (mage.GetState())
	{
	case State::normal:
		cout << "State: normal " << '\n';
		break;
	case State::dead:
		cout << "State: dead " << '\n';
		break;
	case State::paralyzed:
		cout << "State: paralyzed " << '\n';
		break;
	}

	switch (mage.GetRace())
	{
	case Race::dwarf:
		cout << "Race: dwarf " << '\n';
		break;
	case Race::elf:
		cout << "Race: elf " << '\n';
		break;
	case Race::human:
		cout << "Race: human " << '\n';
		break;
	}

	switch (mage.GetMove())
	{
	case true:
		cout << "Move: of course " << '\n';
		break;
	case false:
		cout << "Move: can not" << '\n';
		break;
	}

	Sleep(4000);
	std::system("cls");
}

void OperatorMethod(Character& mage) {
	mage.print(cout);
	Sleep(4000);
	std::system("cls");
}

void Compare(Character& mage, Character& rogue) {

	cout << "Now we are going to compare 2 objects of class " << '\n';
	Sleep(4000);
	std::system("cls");

	mage.print(cout);
	cout << endl;
	rogue.print(cout);

	if (mage == rogue) {
		cout << "\nTwo objects are similar" << '\n';
	}
	else {
		cout << "\nThey are not similar " << '\n';
	}
	Sleep(4000);
	system("cls");
}


void GetInf(Character& mage) {
	system("cls");
	cout << "Type 1: Information throught getter\nType 2: Information throught operator\n";

	switch (_getch())
	{
	case '1':
		system("cls");
		GetMethod(mage);
		break;
	case '2':
		system("cls");
		OperatorMethod(mage);
		break;
	default:
		system("cls");
		cout << "Try again..." << '\n';
		Sleep(3000);
		GetInf(mage);
	}
}


void SetInfo(MageCharacter& Person) {

	Person.SetArr(10);
	Person.SetCurrentMana(20);
	Person.SetMaxMana(200);
	Person.SetMonth(5);
	Person.SetMove(true);
	Person.SetName("Boolalpha");
	Person.SetRace(Race::dwarf);
	Person.SetState(State::normal);

}


void GetInfo(MageCharacter& Person) {


	cout << "ID: " << Person.GetID() << '\n';
	cout << "Name: " << Person.GetName() << '\n';

	switch (Person.GetState())
	{
	case State::normal:
		cout << "State: normal " << '\n';
		break;
	case State::dead:
		cout << "State: dead " << '\n';
		break;
	case State::paralyzed:
		cout << "State: paralyzed " << '\n';
		break;
	}

	switch (Person.GetRace())
	{
	case Race::dwarf:
		cout << "Race: dwarf " << '\n';
		break;
	case Race::elf:
		cout << "Race: elf " << '\n';
		break;
	case Race::human:
		cout << "Race: human " << '\n';
		break;
	}

	switch (Person.GetMove())
	{
	case true:
		cout << "Move: of course " << '\n';
		break;
	case false:
		cout << "Move: can not" << '\n';
		break;
	}

	cout << "Max mana: " << Person.GetMaxMana() << '\n';
	cout << "Current mana: " << Person.GetCurrentMana() << '\n';
	cout << "Month: " << Person.GetMonth() << '\n';
}

void GetInfoOperator(MageCharacter& Person) {
	Person.print(cout);
}


void All(MageCharacter& Person) {
	cout << "Type 1: Information throught getter\nType 2: Information throught operator\n";

	switch (_getch())
	{
	case '1':
		system("cls");
		GetInfo(Person);
		break;
	case '2':
		system("cls");
		GetInfoOperator(Person);
		break;
	default:
		system("cls");
		cout << "Try again..." << '\n';
		Sleep(3000);
		All(Person);
	}
}

void print(Character** arr) {
	for (int i = 0; i < 3; ++i) {
		cout << '\n';
		arr[i]->print(cout);
		cout << '\n';
	}
}


void ThirdPart(Character**& arr, MageCharacter& escape, size_t* a) {

	arr = new Character * [3];
	arr[0] = new MageCharacter(escape);
	arr[1] = new Character("Vasya", State::dead, Race::elf, false);
	arr[2] = new MageCharacter("vasya", State::paralyzed, Race::dwarf, true, 200, 12, a, 2);

}

void Sorted(Character**& arr) {

	sort(arr, arr + 3, [](Character* a, Character* b)->bool {
		string s = a->GetName();
		string ns = b->GetName();
		return tolower(s[0]) < tolower(ns[0]);
		});



	print(arr);

	Sleep(7000);
	system("cls");
}


void Amount(Character**& arr) {

	int count1 = 0, count2 = 0;

	for (int i = 0; i < 3; i++)
	{
		if (!strcmp(typeid(*arr[i]).name(), "class Character"))
			count1++;
		else
			count2++;
	}

	cout << "Objects class Character: " << count1 << "\nObjects class MageCharacter: " << count2;

	cout << "\n\n";
}

void Find(Character**& arr)
{
	cout << "Please input your mana: ";
	short mana;
	cin >> mana;
	assert(mana > 0);
	bool check = false;
	for (int i = 0; i < 3; i++) {
		MageCharacter* p = dynamic_cast<MageCharacter*>(arr[i]);
		if (p) {
			if (p->GetCurrentMana() < mana) {
				cout << endl;
				p->print(cout);
				cout << endl;
				check = true;
			}
		}
	}
	if (check == false)
		cout << "\nThere are no characters, sorry ";
}

void Delete(Character**& arr) {
	for (ptrdiff_t i = 0; i < 3; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}

int main() {

	try
	{
		Character mage;
		Character rogue("Torffin", State::paralyzed, Race::human, false);
		MageCharacter Person;

		size_t* a = 0;
		MageCharacter escape("Misha", State::dead, Race::elf, false, 200, 30, a, 1), b(escape);

		Character** arr;



		SetInf(mage);
		GetInf(mage);
		Compare(mage, rogue);
		SetInfo(Person);
		All(Person);



		ThirdPart(arr, escape, a);
		print(arr);
		Sleep(3000);
		system("cls");
		Sorted(arr);
		Amount(arr);
		Find(arr);
		Delete(arr);

	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}

	cout << "\n";
	std::system("pause");
	return EXIT_SUCCESS;
}