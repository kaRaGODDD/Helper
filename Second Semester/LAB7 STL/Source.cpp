#include "Book.h"

struct Student
{
	string surname{};
	string name{};
	string middle_name{};
	short course{};
	short group{};

	friend ostream& operator << (ostream& out, const Student& right) {
		out << "Surname: " << right.surname << "\n";
		out << "Name: " << right.name << "\n";
		out << "Middle name: " << right.middle_name << "\n";
		out << "Course: " << right.course << "\n";
		out << "Group: " << right.group << "\n";
		out << "\n\n";
		return out;
	}

	friend istream& operator >> (istream& in, Student& right) {
		in >> right.surname;
		in >> right.name;
		in >> right.middle_name;
		in >> right.course;
		in >> right.group;
		return in;
	}

};

void input_info(int& rows, int& cols) {

	std::cout << "Input rows and cols " << "\n";

	std::cin >> rows >> cols;

	system("cls");

	if (rows <= 0 && cols <= 0) {
		throw std::exception("Rows and cols can`t be less than zero or equal to zero\n");
	}

}

void fill(std::vector<std::vector<int>>& a, const int& rows, const int& cols) noexcept {

	std::generate_n(std::back_inserter(a), rows, [cols]() -> std::vector<int>
		{
			std::vector<int> ivec;
			std::generate_n(std::back_inserter(ivec), cols, []() {
				return rand() % 212;
				});
			return ivec;
		});

}

void print(std::vector<std::vector<int>>& a) noexcept {

	std::cout << "\nMatrix is\n";

	std::for_each(a.begin(), a.end(), [](std::vector<int>& v)
		{
			std::for_each(v.begin(), v.end(), [](const auto& i)
				{
					std::cout << std::left << std::setw(5) << i;
				});
			std::cout << std::endl;
		});

}

int sum(std::vector<std::vector<int>>& a, const int& rows, const int& cols) noexcept {

	int s = 0;
	for (int i = 0; i < cols; i++)
		s += a[rows][i];
	return s;

}
void sort(std::vector<std::vector<int>>& a, const int& rows, const int& cols) noexcept {

	std::cout << "\nsort\n";

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows - i - 1; j++)
		{
			if (sum(a, j, cols) > sum(a, j + 1, cols))
			{
				swap(a[j], a[j + 1]);
			}
		}
	}

}

void find_max(std::vector<std::vector<int>>& a, const int& rows, const int& cols, int& max, int& first, int& second) noexcept {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (a[i][j] > max) {
				max = a[i][j];
				first = i;
				second = j;
			}
		}
	}
}

void check(const int& max, const int& first, const int& second) noexcept {
	std::cout << "\nMax Element is " << max << " with index of rows " << first << " index of cols " << second << "\n";
}

void del(std::vector<std::vector<int>>& a, const int& first, const int& second, int& rows, int& cols) noexcept {
	std::cout << "\n\nDeleted\n\n";
	for (int i = first; i < rows - 1; ++i) {
		for (int j = 0; j < cols; ++j) {
			a[i][j] = a[i + 1][j];
		}
	}
	for (int i = 0; i < rows; ++i) {
		for (int j = second; j < cols - 1; ++j) {
			a[i][j] = a[i][j + 1];
		}
	}
}

void print_without(std::vector<std::vector<int>>& a) noexcept {

	std::cout << "Matrix without\n";
	std::for_each(a.begin(), a.end() - 1, [](std::vector<int>& v)
		{
			std::for_each(v.begin(), v.end() - 1, [](const auto& i)
				{
					std::cout << std::left << std::setw(5) << i;
				});
			std::cout << std::endl;
		});

}

void read(vector<Student>& a, fstream& file, const string& filePath) {
	file.open(filePath, std::ios::in);
	std::copy(std::istream_iterator<Student>(file), std::istream_iterator<Student>(), std::back_inserter(a));
	file.close();
}

void sorted_by_alph(vector<Student>& a, fstream& file, string filePath) {
	sort(a.begin(), a.end(), [](const Student& a, const Student& b) {
		string str1 = a.surname;
		string str2 = b.surname;
		transform(str1.begin(), str1.end(), str1.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c); });
		transform(str2.begin(), str2.end(), str2.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c); });
		return str1 < str2;
		});
}


void sorted_by_other(vector<Student>& a, fstream& groups, const string& groupsPath) {
	groups.open(groupsPath, ios::out);

	sort(a.begin(), a.end(), [](const Student& lhs, const Student& rhs) {
		return lhs.course < rhs.course;
	});

	sort(a.begin(), a.end(), [](const Student& lhs, const Student& rhs) {
		if (lhs.course == rhs.course) {
			if (lhs.group == rhs.group)
			{
				string str1 = lhs.surname;
				string str2 = rhs.surname;
				transform(str1.begin(), str1.end(), str1.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c); });
				transform(str2.begin(), str2.end(), str2.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c); });
				return str1 < str2;
			}
			else {	
				return lhs.group < rhs.group;
			}
		}
		else {
			return lhs.course < rhs.course;
		}
	});

	groups.close();
}

void second_print(vector<Student>& a, fstream& groups, const string& groupsPath) {

	groups.open(groupsPath, ios::out);

	for (int i = 0; i < a.size(); ++i) {
		groups << a[i];
	}

	groups.close();
}

void print(vector<Student>& a, fstream& fio, const string& fioPath) {
	fio.open(fioPath, ios::out);

	for (int i = 0; i < a.size(); ++i) {
		fio << a[i];
	}

	fio.close();
}


void first_task() {

	srand(size_t(NULL));
	int rows;
	int cols;
	int max{};
	int first = -1;
	int second = -1;
	std::vector<std::vector<int>> a;
	input_info(rows, cols);
	fill(a, rows, cols);
	print(a);
	sort(a, rows, cols);
	print(a);
	find_max(a, rows, cols, max, first, second);
	check(max, first, second);
	del(a, first, second, rows, cols);
	print_without(a);

}


void second_task() {
	std::cout << "Check files\n";
	vector<Student> a;
	fstream file;
	string filePath = "Students.txt";

	fstream fio;
	string fioPath = "fio.txt";

	fstream groups;
	string groupsPath = "groups.txt";

	read(a, file, filePath);
	sorted_by_alph(a, file, filePath);
	print(a, fio, fioPath);

	sorted_by_other(a, groups, groupsPath);
	second_print(a, groups, groupsPath);

}



void get_list_of_authors(fstream& file, const string& filePath, string& str, regex& e, fstream& authors, const string& authorsPath) {

	file.open(filePath, ios::in);
	authors.open(authorsPath, ios::out);
	while (getline(file, str)) {
		sregex_iterator pos(str.cbegin(), str.cend(), e);
		sregex_iterator end;
		for (; pos != end; ++pos) {
			authors << pos->str(2);
		}
		authors << "\n";
	}
	file.close();
	authors.close();

}

void print_book(const Book& book) {
	cout << book;
}

void parse_all(fstream& file, const string& filePath, fstream& authors, const string& authorsPath, regex regular, string& str, string& surname, string& name, string& fathername, list<Author>& lst, Author& author, Book& book, regex e, string noname, list<Book>& library) {

	authors.open(authorsPath, ios::in);
	file.open(filePath, ios::in);

	const char* _year{};
	const char* _udc{};
	unsigned int fake_udc{};
	unsigned int fake_year{};
	string udc{};
	string year{};
	string _title{};

	while (getline(authors, str) && getline(file, noname)) {

		sregex_iterator pos(str.cbegin(), str.cend(), regular);
		sregex_iterator end;

		for (; pos != end; ++pos) {

			surname = pos->str(1);
			name = pos->str(2);
			fathername = pos->str(3);
			Author authorr(surname, name, fathername);
			list<Author> pattern;
			pattern.push_back(authorr);
			book.setAuthors(pattern);

			sregex_iterator position(noname.cbegin(), noname.cend(), e);
			sregex_iterator endition;

			for (; position != endition; ++position) {
				udc = position->str(1);
				_udc = udc.c_str();
				fake_udc = atoi(_udc);
				year = position->str(4);
				_year = year.c_str();
				fake_year = atoi(_year);
				_title = position->str(3);
			}

			book.setUdc(fake_udc);
			book.setTitle(_title);
			book.setYear(fake_year);
			library.push_back(book);
			//print_book(book);
		}
	}

	file.close();
	authors.close();
}

void print_library(list<Book>& library) {
	for (auto&& x : library) {
		cout << x;
	}
}

void add_book(list<Book>& library, Book& boo)
{
	library.push_back(boo);
	library.sort();
}


void erase_book(list<Book>& library) {

	cout << "Input title\n";

	string title;
	cin >> title;

	library.erase(remove_if(library.begin(), library.end(), [&title](Book& name) {
		return name.GetTitle() == title;
	}));

}


list<Book>::iterator search_by_title(list<Book>& library, string& _title)
{
	bool found = false;

	auto result = find_if(library.begin(), library.end(), [&_title](Book& obj) {
		return obj.GetTitle() == _title;
	});

	if (result != library.end()) {
		found = true;
	}

	(found == true) ? cout << "Yep, i`m find\n\n" : cout << "No, i don`t find\n\n";

	return result;
}


list<Book>::iterator search_by_author(list<Book>& library, const Author& auth) {

	bool found = false;

	auto result = find_if(library.begin(), library.end(), [&auth](Book& obj) {
		for (auto x : obj.GetList()) {
			return (x == auth);
		}
	});

	if (result != library.end()) {
		found = true;
	}

	(found == true) ? cout << "Yep, i`m find books\n\n" : cout << "No, i don`t find books\n\n";
	return result;
}


void delete_by_author(string& _title, list<Book>& library) {

	auto result = search_by_title(library, _title);

	if (result != library.end()) {
		library.erase(result);
		cout << "Book was removed\n\n";
	}
	else {
		cout << "No, book has not been deleted \n\n";
	}
}

void add_by_author(list<Book>& library, const Author& lenin) {

	cout << "Input title\n";

	string __title;
	cin >> __title;

	list<Author> for_lenin;
	for_lenin.push_back(lenin);
	Book my_book(23, __title, 333, for_lenin);

	library.push_back(my_book);

}

void for_third(fstream& file, string filePath, string str, regex e, fstream& authors, string authorsPath, regex regular, string& surname, string& name, string& fathername, list<Author>& lst, Author& author, Book& book, string noname, list<Book>& library, Book& boo, string& _title, const Author& auth, const Author& lenin) {

	get_list_of_authors(file, filePath, str, e, authors, authorsPath);
	std::cout << "Now i parse all data with help regular expression\n\n";
	parse_all(file, filePath, authors, authorsPath, regular, str, surname, name, fathername, lst, author, book, e, noname, library);
	std::cout << "now you see the list after parse\n\n";
	print_library(library);
	/*Sleep(7000);
	system("cls");
	std::cout << "Now i add the book in my library\n\n";
	add_book(library, boo);
	Sleep(7000);
	system("cls");
	std::cout << "After add\n";
	print_library(library);
	Sleep(7000);
	system("cls");
	std::cout << "Now i will find the book by title\n";
	cout << *search_by_title(library, _title);
	Sleep(7000);
	system("cls");
	std::cout << "Now i will find the book by author\n\n";
	cout << *search_by_author(library, auth);
	Sleep(7000);
	system("cls");
	std::cout << "Now i delete book\n\n";
	erase_book(library);
	print_library(library);
	Sleep(7000);
	system("cls");
	std::cout << "Now i delete book by author\n\n";
	delete_by_author(_title, library);
	print_library(library);
	Sleep(7000);
	system("cls");
	std::cout << "Now i add book with author in my library\n\n";
	add_by_author(library, lenin);
	print_library(library);
	Sleep(7000);
	system("cls");
	std::cout << "\t\t\t\t Bye \t\t\t\t\n";
	system("pause");*/

}

void third_task() {

	list<Book> library;
	fstream authors;
	string authorsPath = "authors.txt";
	string str;
	string noname;
	list<Author> lst;
	fstream file;
	string filePath = "input.txt";
	string surname;
	string name;
	string fathername;

	regex e("([0-9]+);([\\D]+);([\\D]+);([0-9]+)");
	regex regular("([\\D]+)\\s([\\D]+)\\s([\\D]+)");

	Author author;
	Book book;
	Author _au("Three", "Days", "grays");
	list<Author> _boo;
	_boo.push_back(_au);
	Book boo(883, "IOO", 776, _boo);
	string _title = "IOO";
	Author auth("Aksakov", "Sergey", "Timofeevich");
	Author lenin("Ylyanov", "Vladimir", "Ilich");
	for_third(file, filePath, str, e, authors, authorsPath, regular, surname, name, fathername, lst, author, book, noname, library, boo, _title, auth, lenin);

}


void menu() {
	try
	{
		std::cout << "Type 1: first task.\nType 2: second task.\nType 3: third task.\n";

		switch (_getch())
		{
		case '1':
			system("cls");
			first_task();
			break;
		case '2':
			system("cls");
			second_task();
			break;
		case '3':
			system("cls");
			third_task();
			break;
		default:
			system("cls");
			std::cout << "Try again...\n";
			Sleep(3000);
			system("cls");
			menu();
		}
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}

}

int main() {

	menu();

	return EXIT_SUCCESS;
}