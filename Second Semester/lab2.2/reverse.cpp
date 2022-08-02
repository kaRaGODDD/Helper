#define _CRT_SECURE_NO_WARNINGS
#define br '\n'
#define MAX_LENGTH 256
#include <iostream>
#include <string.h>
#include <string.h>
using namespace std;


int Checker(char* s, int(*f)(int)) {
	return (!*s) ? 1 : f(*s) && Checker(s + 1, f);
}

void InputDel(char* del) {
	cout << "Input delimetrs" << br;
	cin.getline(del, MAX_LENGTH);
}

void InputString(char* s, char* str) {
	cout << "Input your string" << br;
	cin.getline(s, 256);
	strcpy(str, s);
}


void FirstPart(char* s, char* word, char* token, char* del,char* copy2,char* bigger) {
	char* revers = new char[MAX_LENGTH];
	word = strtok(s, del);
	while (word != NULL) {
		if (strlen(word) >= 4) {
			if (Checker(word, isalpha)) {
				token = word;
				for (int i = 0; i < strlen(token); ++i) {
					revers[i] = token[strlen(token) - i - 1];
					if (isalpha(revers[i])) {
						cout << revers[i];
					}
				}
			}

		}
		cout << ' ';
		word = strtok(NULL, del);
	}
	delete[] revers;
}

void SecondPart(char* str, char* secondword, char* anothertoken, char* copy2, char* bigger, char* del) {
	secondword = strtok(str, del);
	while (secondword != NULL) {
		if (strlen(secondword) >= 4) {
			anothertoken = secondword;
			for (int i = 0; i < strlen(anothertoken); ++i) {
				if (Checker(anothertoken, isalnum)) {
					copy2[i] = anothertoken[i];
					if (tolower(copy2[i])) {
						bigger[i] = toupper(copy2[i]);
						cout << bigger[i];
					}
				}
			}
		}
		cout << ' ';
		secondword = strtok(NULL, del);
	}
}



void Delete(char* s, char* str, char* del, char* secondword, char* anothertoken, char* copy2, char* bigger, char* word, char* token) {
	delete[] s;
	delete[] str;
	delete[] del;
	delete[] secondword;
	delete[] anothertoken;
	delete[] copy2;
	delete[] bigger;
	delete[] word;
	delete[] token;
}


int main() {

	char* s = new char[MAX_LENGTH];
	char* str = new char[MAX_LENGTH];
	char* del = new char[MAX_LENGTH];
	char* secondword = new char[MAX_LENGTH];
	char* anothertoken = new char[MAX_LENGTH];
	char* copy2 = new char[MAX_LENGTH];
	char* bigger = new char[MAX_LENGTH];
	char* word = new char[MAX_LENGTH];
	char* token = new char[MAX_LENGTH];


	InputString(s, str);
	InputDel(del);
	cout << "The new string is " << br;
	FirstPart(s, word, token, del,bigger,copy2);
	//SecondPart(str, secondword, anothertoken, copy2, bigger, del);

	Delete(s, str, del, secondword, anothertoken, copy2, bigger, word, token);
	cout << br;
	system("pause");
	return EXIT_SUCCESS;
}