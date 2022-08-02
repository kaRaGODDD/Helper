#include <iostream>
#include <fstream>
#include <regex>
#include <Windows.h>
#include <functional>
#include <conio.h>
#include <map>
#include <iomanip>

struct SMark
{
	std::string subject{};
	int mark{};
	SMark(std::string subject_, int mark_) :
		subject(subject_), mark(mark_) {}
	friend std::ostream& operator << (std::ostream& out, const SMark& right) {
		out << "Предмет:" << right.subject << "\n";
		out << "Оценка:" << right.mark << "\n";
		return out;
	}
};

struct SStudData
{
	std::string name{};
	int number{};
	long double average{};
	std::vector<SMark> marks;
	SStudData(std::string name_, std::vector<SMark> marks_, long double avg) : name(name_), average(avg) {
		marks.clear();
		marks.assign(marks_.begin(), marks_.end());
	}
	friend std::ostream& operator << (std::ostream& out, const SStudData& right) {
		out << "Имя: " << right.name << "\n";
		for (const auto& x : right.marks) {
			out << x;
		}
		out << "Средний балл:" << right.average;
		out << "\n\n";
		return out;
	}

};


void check_file(std::fstream& file, const std::string& filePath) {
	file.open(filePath, std::ios::in);

	if (file.is_open()) {
		std::cout << "Файл открыт" << "\n";
	}
	else
	{
		throw std::exception("Файл не был открыт");
	}
	if (file.peek() != EOF) {
		std::cout << "Файл не пуст" << "\n";
	}
	else
	{
		throw std::exception("Файл пуст");
	}
	if (file.bad() == false) {
		std::cout << "Файл существует" << "\n";
	}
	else
	{
		throw std::exception("Файл не существует");
	}
	file.close();
}

void parse_all(std::fstream& file, const std::string& filePath, const std::regex& regular, std::map<int, SStudData, std::greater<int>>& mp) {
	file.open(filePath, std::ios::in);
	std::string subject1{};
	std::string subject2{};
	std::string subject3{};
	int mark1{};
	int mark2{};
	int mark3{};
	std::string name{};
	int number{};
	std::string temp;
	while (std::getline(file, temp)) {
		std::sregex_iterator pos(temp.cbegin(), temp.cend(), regular);
		std::sregex_iterator end;
		for (; pos != end; ++pos) {
			name = pos->str(1);
			number = stoi(pos->str(2));
			subject1 = pos->str(3);
			mark1 = stoi(pos->str(4));
			subject2 = pos->str(5);
			mark2 = stoi(pos->str(6));
			subject3 = pos->str(7);
			mark3 = stoi(pos->str(8));
			long double avg = (mark1 + mark2 + mark3) / 3;
			SMark obj1(subject1, mark1);
			SMark obj2(subject2, mark2);
			SMark obj3(subject3, mark3);
			std::vector<SMark> tempoviy;
			tempoviy.push_back(obj2);
			tempoviy.push_back(obj3);
			tempoviy.push_back(obj1);
			mp.insert(std::make_pair(number, SStudData(name, tempoviy, avg)));
		}
	}
	file.close();
}

void print_map(std::map<int, SStudData, std::greater<int>>& mp) {
	for (auto&& [key, value] : mp) {
		std::cout << "Зачетка: " << key << "\n" << value;
	}
}

void _emplace(std::map<int, SStudData, std::greater<int>>& mp, std::vector<std::pair<int, SStudData>>& stud) {
	for (auto&& [key, value] : mp) {
		stud.emplace_back(key, value);
	} 
}

void print_by_number(std::vector<std::pair<int, SStudData>>& stud) {

	std::function<bool(const std::pair<int, SStudData>, const std::pair<int, SStudData>)> f = [](const std::pair<int, SStudData>& a, const std::pair<int, SStudData>& b) {
		if (a.second.name == b.second.name) {
			return a.first > b.first;
		}
		return a.second.name.compare(b.second.name) < 0;
	};

	std::sort(stud.begin(), stud.end(), f);
	int i = 1;
	for (auto&& [key, value] : stud) {
		std::cout << "Номер: " << i++ << '\n' << "Зачетка: " << key << "\n" << value << "\n";
	}

}


void input_range(int& x, int& y) {
	std::cout << "Сейчас мы будем вводить диапазон\n";
	std::cout << "Введите первую границу диапазона\n";
	std::cin >> x;
	std::cout << "Введите вторую границу диапазона\n";
	std::cin >> y;
	if (x <= 0 || y <= 0) {
		throw std::exception("То значение, которое вы ввели, не может быть диапазоном");
	}
	if (x > 10 || y > 10) {
		system("cls");
		throw std::exception("То значение, которое вы ввели,не может быть диапазоном");
	}
	system("cls");
}

bool print_by_range(const int& x, const int& y, std::vector<std::pair<int, SStudData>>& stud) {

	bool flag = false;
	for (auto&& [key, value] : stud) {
		if (value.average >= x && value.average <= y) {
			std::cout << "Зачетка: " << key << "\n" << value;
			flag = true;
		}
	}
	return flag;
}


void print_by_subject(std::map<int, SStudData, std::greater<int>>& mp) {
	
	int index = 0;
	std::cout << "Введите предмет\n";
	std::string subject;
	std::cin >> subject;

	for (auto&& [key, value] : mp) {		
		for (auto&& sub : value.marks) {
			if (sub.subject == subject) {
				index++;
			}
		}
	}
	if (index == 0) {
		system("cls");
		throw std::exception("Данного предмета нет");
	}
	std::cout << "Данный предмет " << subject << " сдавало: " << index;

	
}

void print_subject(std::map<std::string, int>& subjects) {
	for (auto&& [key, value] : subjects) {
		std::cout << key << " : " << value << "\n";
	}
}

void all_subjects(std::map<int, SStudData, std::greater<int>>& mp, std::map<std::string, int>& subjects) {

	for (auto&& [key, value] : mp) {
		for (auto&& x : value.marks) {
			subjects.insert(std::make_pair((x.subject), 0));
		}
	}

	for (auto&& [key, value] : mp) {
		for (auto&& x : value.marks) {
			subjects.find(x.subject)->second++;
		}
	}

	print_subject(subjects);

}
 

void for_every_subject(std::map<int, SStudData, std::greater<int>>& mp) {

	size_t sz = mp.size();

	std::map<std::string, double> for_ever;

	for (auto&& [key, value] : mp) {
		for (auto&& x : value.marks) {
			for_ever.insert(std::make_pair((x.subject), 0));
		}
	}

	for (auto&& [key, value] : mp) {
		for (auto&& x : value.marks) {
			for_ever.find(x.subject)->second += x.mark;
		}
	}

	for (auto&& [key, value] : for_ever) {
		std::cout << key << ":" << value / sz << "\n";
	}

}


void student_with_max(std::vector<std::pair<int, SStudData>>& stud) {

	double max = 0;

	for (auto&& [key, value] : stud) {
		if (value.average > max) {
			max = value.average;
		}
	}

	for (auto&& [key, value] : stud) {
		if (value.average == max) {
			std::cout << max << " -> " << value.name;
		}
	}

}


void students_with_low(std::vector<std::pair<int, SStudData>>& stud) {
	for (auto&& [key, value] : stud) {
		for (auto&& x : value.marks) {
			if (x.mark < 4) {
				std::cout << "Вот же он: " << value.name << "\n";
			}
		}
	}
}


void menu() {
	try
	{
		system("cls");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		int x, y;

		std::fstream file;
		std::string filePath = "text.txt";
		std::vector<SStudData> vec;
		std::regex regular("([\\D]+);([0-9]+);([\\D]+)\\s([0-9]+),([\\D]+)\\s([0-9]+),([\\D]+)\\s([0-9]+)");

		std::map<int, SStudData, std::greater<int>> mp;
		std::map<std::string, int> subjects;
		std::vector<std::pair<int, SStudData>> stud;

		std::cout << "\t\t\t\t\tЧто вы хотите выбрать?\n";
		std::cout << "Пункт 1: Проверка файла.\n";
		std::cout << "Пункт 2: Вывод данных.\n";
		std::cout << "Пункт 3: Список всех студентов номер по порядку, фамилия, номер зачетки и тд.\n";
		std::cout << "Пункт 4: Диапазон.\n";
		std::cout << "Пункт 5: Список студентов которые сдавали заданный предмет.\n";
		std::cout << "Пункт 6: Определить, сколько студентов сдавало каждый предмет.\n";
		std::cout << "Пункт 7: Для каждого предмета определить средний балл, и вывести предметы и баллы в порядке убывания баллов.\n";
		std::cout << "Пункт 8: Найти всех студентов с максимальной суммой баллов.\n";
		std::cout << "Пункт 9: Найти всех студентов с неудовлетворительными оценками(1,2,3).\n";

		parse_all(file, filePath, regular, mp);
		_emplace(mp, stud);


		switch (_getch())
		{
		case '1':
			system("cls");
			check_file(file, filePath);
			std::cout << "\n\nЖелаете продолжить? Если да,то нажмите 1\n\n";
			switch (_getch())
			{
			case '1':
				menu();
				break;
			default:
				system("cls");
				std::cout << "Бай-бай.\n";
				break;
			}
			break;
		case '2':
			system("cls");
			print_map(mp);
			std::cout << "\n\nЖелаете продолжить? Если да,то нажмите 1\n\n";
			switch (_getch())
			{
			case '1':
				menu();
				break;
			default:
				system("cls");
				std::cout << "Бай-бай.\n";
				break;
			}
			break;
		case '3':
			system("cls");
			print_by_number(stud);
			std::cout << "\n\nЖелаете продолжить? Если да,то нажмите 1\n\n";
			switch (_getch())
			{
			case '1':
				menu();
				break;
			default:
				system("cls");
				std::cout << "Бай-бай.\n";
				break;
			}
			break;
		case '4':
			system("cls");
			input_range(x, y);
			print_by_range(x, y, stud);
			std::cout << "\n\nЖелаете продолжить? Если да,то нажмите 1\n\n";
			switch (_getch())
			{
			case '1':
				menu();
				break;
			default:
				system("cls");
				std::cout << "Бай-бай.\n";
				break;
			}
			break;
		case '5':
			system("cls");
			print_by_subject(mp);
			std::cout << "\n\nЖелаете продолжить? Если да,то нажмите 1\n\n";
			switch (_getch())
			{
			case '1':
				menu();
				break;
			default:
				system("cls");
				std::cout << "Бай-бай.\n";
				break;
			}
			break;
		case '6':
			system("cls");
			all_subjects(mp, subjects);
			std::cout << "\n\nЖелаете продолжить? Если да,то нажмите 1\n\n";
			switch (_getch())
			{
			case '1':
				menu();
				break;
			default:
				system("cls");
				std::cout << "Бай-бай.\n";
				break;
			}
			break;
		case '7':
			system("cls");
			for_every_subject(mp);
			std::cout << "\n\nЖелаете продолжить? Если да,то нажмите 1\n\n";
			switch (_getch())
			{
			case '1':
				menu();
				break;
			default:
				system("cls");
				std::cout << "Бай-бай.\n";
				break;
			}
			break;
		case '8':
			system("cls");
			student_with_max(stud);
			std::cout << "\n\nЖелаете продолжить? Если да,то нажмите 1\n\n";
			switch (_getch())
			{
			case '1':
				menu();
				break;
			default:
				system("cls");
				std::cout << "Бай-бай.\n";
				break;
			}
			break;
		case '9':
			system("cls");
			students_with_low(stud);
			std::cout << "\n\nЖелаете продолжить? Если да,то нажмите 1\n\n";
			switch (_getch())
			{
			case '1':
				menu();
				break;
			default:
				system("cls");
				std::cout << "Бай-бай.\n";
				break;
			}
			break;
		default:
			system("cls");
			std::cout << "Попробуйте снова\n";
			Sleep(4000);
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


	std::cout << "\n";
	system("pause");
	return EXIT_SUCCESS;
}