#include "Driver.h"

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

void print_driver(std::list<Driver>& driver) {
	for (auto&& x : driver) {
		std::cout << "Номер маршрута: " << x.number_of_marsh << "\n" << x;
	}
}

void data(std::fstream& file,const std::string& filePath, std::list<Driver>& driver) {
	file.open(filePath, std::ios::in);
	
	Driver obj;

	while (file >> obj) {
		driver.push_back(obj);
	}

	file.close();
		
}


void sorted_in_order(std::list<Driver>& driver) {

	auto cmp = [](const Driver& lhs, const Driver& rhs) {
		if (lhs.number_of_bus == rhs.number_of_bus) {
			return lhs.number_of_marsh < rhs.number_of_marsh;
		}
		else {
			return lhs.number_of_bus < rhs.number_of_bus;
		}
	};
	driver.sort(cmp);

}


void parse_list(std::list<Driver>& driver,std::map<int, Driver>& mp) {

	for (auto&& x : driver) {
		mp.insert(std::make_pair(x.number_of_marsh,Driver(x.name,x.number_of_bus,x.mark)));
	}
	
}

void print_map(const std::map<int,Driver>& mp) {
	for (auto&& [key, value] : mp) {
		std::cout << "Номер маршрута: " << key << "\n";
		std::cout << "Водитель: " << value.name << "\n";
		std::cout << "Номер автобуса: " << value.number_of_bus << "\n";
		std::cout << "Марка: " << value.mark << "\n";
		std::cout << "\n\n";
	}
}

void print_list_marsh(std::map<int,Driver>& mp) {
	std::cout << "Введите маршрут:\n";

	bool flag = false;

	int marsh;

	std::cin >> marsh;

	if (marsh <= 0) {
		throw std::exception("Это не может быть номером маршрута");
	}

	std::cout << "\nМарки:\n";
	for (auto&& [key, value] : mp) {
		if (key == marsh) {
			std::cout << value.mark;
			flag = true;
		}
	}

	if (flag == false) {
		throw std::exception("Я не нашел");
	}

}

void print_for_driver(std::map<int, Driver>& mp) {
	std::cout << "Введите маршрут:\n";

	bool flag = false;

	int marsh;

	std::cin >> marsh;

	if (marsh <= 0) {
		throw std::exception("Это не может быть номером маршрута");
	}

	std::cout << "\nВодитель:\n";
	for (auto&& [key, value] : mp) {
		if (key == marsh) {
			std::cout << value.name;
			flag = true;
		}
	}
	if (flag == false) {
		throw std::exception("Я не нашел");
	}
}

void replace_driver(std::map<int, Driver>& mp) {
	bool flag = false;
	std::cout << "Кого меняем:\n"; // как я понял одного
	std::string first_name;
	std::cin >> first_name;
	std::cout << "На кого меняем\n";
	std::string second_name;
	std::cin >> second_name;
	
	for (auto&& [key, value] : mp) {
		if (value.name == first_name) {
			value.name = second_name;
			flag = true;
		}
	}
	std::cout << "\n";
	for (auto&& [key, value] : mp) {
		std::cout << value;
	}
	if (flag == false) {
		throw std::exception("Я не нашел");
	}
}


void find_the_marsh_by_driver(std::map<int, Driver>& mp) {
	bool flag = false;
	std::cout << "Введите имя водителя\n";
	std::string name_of_the_driver;
	std::cin >> name_of_the_driver;
	
	for (auto&& [key, value] : mp) {
		if (value.name == name_of_the_driver) {
			std::cout <<"Номер маршрута : " << key;
			flag = true;
		}
	}
	if (flag == false) {
		throw std::exception("Я не нашел");
	}

}


void menu() {
	try
	{
		system("cls");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		std::fstream file;
		std::string filePath = "text.txt";
		std::list<Driver> driver;
		std::map<int, Driver> mp;

		data(file, filePath, driver);
		parse_list(driver, mp);
		std::cout << "\t\t\t\tЧто вы выберете?\n";
		std::cout << "Пункт 1: Проверка файла\n";
		std::cout << "Пункт 2: Сортировка по номеру автобуса и по номеру маршрута\n";
		std::cout << "Пункт 3: Данные в map\n";
		std::cout << "Пункт 4: Вывести список всех марок автобусов указанного маршрута\n";
		std::cout << "Пункт 5: Вывести список всех водителей указанного маршрута\n";
		std::cout << "Пункт 6: Реализовать модификацию информации (меняем водителя)\n";
		std::cout << "Пункт 7: Найти маршрут, на котором работает указанный водитель\n";

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
			sorted_in_order(driver);
			print_driver(driver);
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
		case '4':
			system("cls");
			print_list_marsh(mp);
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
			print_for_driver(mp);
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
			replace_driver(mp);
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
			find_the_marsh_by_driver(mp);
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