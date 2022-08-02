#define _CRT_SECURE_NO_WARNINGS
#define br '\n'
#define MAX_LENGTH 256
#include <iostream>
#include <string.h>

using namespace std;


void Input(char* str, char* s, char* ThirdString) {
	cout << "Input your string" << br;
	cin.getline(str, MAX_LENGTH);
	strcpy(s, str);
	strcpy(ThirdString, str);
	system("cls");
}

void Delims(char* del) {
	cout << "Input your delims" << br;
	cin.getline(del, MAX_LENGTH);
	system("cls");
}

char* FindMax(char* str, char* del, char* token, char* MaxWord, size_t& MaxLength, size_t& MaxPos) {

	cout << br;
	size_t curLength = 0;
	token = strtok(str, del);
	while (token != nullptr) {
		curLength = strlen(token);
		if (curLength > MaxLength) {
			MaxLength = curLength;
			MaxWord = token;
		}
		token = strtok(nullptr, del);
	}

	MaxPos = (MaxWord - str);


	if (MaxLength == 0) {
		throw("Only delimetrs");
	}

	return MaxWord;
}


char* FindMin(char* s, char* del, char* OneMoreToken, char* MinWord, size_t& MinLength, size_t& MinPos) {

	size_t curLength = 0;
	OneMoreToken = strtok(s, del);
	MinLength = strlen(OneMoreToken);
	while (OneMoreToken != nullptr) {
		curLength = strlen(OneMoreToken);
		if (curLength <= MinLength) {
			MinLength = curLength;
			MinWord = OneMoreToken;
		}
		OneMoreToken = strtok(nullptr, del);
	}

	MinPos = (MinWord - s);

	if (MinLength == 0) {
		throw "Only delimetrs";
	}

	return MinWord;
}



void Changing(char* ThirdString, char* MaxWord, char* MinWord, size_t& MaxPos, size_t& MinPos,const size_t& MaxLen,const size_t& MinLen) {
	if (MaxPos > MinPos) {

		int len = strlen(ThirdString);

		int diff = MaxLen - MinLen;

		for (int i = 0; i < diff; i++)
		{
			strcat(ThirdString, " ");
		}

		int x = MinPos + strlen(MinWord);

		for (ptrdiff_t i = 0; i < diff; ++i) {
			for (ptrdiff_t j = len; j > x; --j) {
				swap(ThirdString[j], ThirdString[j - 1]);
			}
			++len;
			++x;
		}
		for (ptrdiff_t i = MinPos, j = MaxPos + diff; i < MinPos + MinLen + diff; i++, j++)
			swap(ThirdString[i], ThirdString[j]);


		for (ptrdiff_t i = MaxPos + diff + MinLen; i < len - diff; i++)
		{
			swap(ThirdString[i], ThirdString[i + diff]);
		}


		ThirdString[strlen(ThirdString) - diff] = '\0';

		cout << endl << ThirdString;


	}

	if (MinPos > MaxPos)
	{

		int len = strlen(ThirdString);
		int diff = strlen(MaxWord) - strlen(MinWord);
		for (int i = 0; i < diff; i++)
		{
			strcat(ThirdString, " ");
		}

		int x = MinPos + strlen(MinWord);
		for (ptrdiff_t i = 0; i < diff; i++)
		{
			for (ptrdiff_t j = len; j > x; j--)
			{
				swap(ThirdString[j], ThirdString[j - 1]);
			}
			len++;
			x++;
		}

		for (ptrdiff_t i = MinPos, j = MaxPos; i < MinPos + MinLen + diff; i++, j++)
			swap(ThirdString[i], ThirdString[j]);

		for (ptrdiff_t i = MaxPos + MinLen; i < len - diff; i++)
		{
			swap(ThirdString[i], ThirdString[i + diff]);
		}

		ThirdString[strlen(ThirdString) - diff] = '\0';

		cout << endl << ThirdString;
	}
}


int main() {
	try
	{

		setlocale(0," ");
		char* str =          new char[MAX_LENGTH];
		char* del =          new char[MAX_LENGTH];
		char* s   =          new char[MAX_LENGTH];
		char* OneMoreToken = new char[MAX_LENGTH];
		char* MinWord =      new char[MAX_LENGTH];
		char* ThirdString =  new char[MAX_LENGTH];
		char* token =        new char[MAX_LENGTH];
		char* MaxWord =      new char[MAX_LENGTH];

		size_t MaxLength = 0;
		size_t MinLength = 0;

		size_t MaxPos = 0;
		size_t MinPos = 0;

		Input(str, s, ThirdString);

		Delims(del);

		MaxWord = FindMax(str, del, token, MaxWord, MaxLength, MaxPos);
		MinWord = FindMin(s, del, OneMoreToken, MinWord, MinLength, MinPos);

		size_t MaxLen = strlen(MaxWord);
		size_t MinLen = strlen(MinWord);

		cout << "MyString is " << br << ThirdString << br << br;

		cout << "Max Word is " << MaxWord << " -> " << " Length is " << MaxLength << br << "Min Word is " << MinWord << " -> " << " Length is " << MinLength << br;

		cout << '\n' << '\n';

		cout << "Changed string ";
		Changing(ThirdString, MaxWord, MinWord, MaxPos, MinPos,MaxLen,MinLen);
		
	}
	catch (const char* ex)
	{
		cout << ex << br;
	}


	cout << br;
	system("pause");
	return 0;
}