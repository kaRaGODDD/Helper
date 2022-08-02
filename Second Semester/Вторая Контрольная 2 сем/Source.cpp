#include "Driver.h"

void check_file(std::fstream& file, const std::string& filePath) {
	file.open(filePath, std::ios::in);

	if (file.is_open()) {
		std::cout << "���� ������" << "\n";
	}
	else
	{
		throw std::exception("���� �� ��� ������");
	}
	if (file.peek() != EOF) {
		std::cout << "���� �� ����" << "\n";
	}
	else
	{
		throw std::exception("���� ����");
	}
	if (file.bad() == false) {
		std::cout << "���� ����������" << "\n";
	}
	else
	{
		throw std::exception("���� �� ����������");
	}
	file.close();
}

void print_driver(std::list<Driver>& driver) {
	for (auto&& x : driver) {
		std::cout << "����� ��������: " << x.number_of_marsh << "\n" << x;
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
		std::cout << "����� ��������: " << key << "\n";
		std::cout << "��������: " << value.name << "\n";
		std::cout << "����� ��������: " << value.number_of_bus << "\n";
		std::cout << "�����: " << value.mark << "\n";
		std::cout << "\n\n";
	}
}

void print_list_marsh(std::map<int,Driver>& mp) {
	std::cout << "������� �������:\n";

	bool flag = false;

	int marsh;

	std::cin >> marsh;

	if (marsh <= 0) {
		throw std::exception("��� �� ����� ���� ������� ��������");
	}

	std::cout << "\n�����:\n";
	for (auto&& [key, value] : mp) {
		if (key == marsh) {
			std::cout << value.mark;
			flag = true;
		}
	}

	if (flag == false) {
		throw std::exception("� �� �����");
	}

}

void print_for_driver(std::map<int, Driver>& mp) {
	std::cout << "������� �������:\n";

	bool flag = false;

	int marsh;

	std::cin >> marsh;

	if (marsh <= 0) {
		throw std::exception("��� �� ����� ���� ������� ��������");
	}

	std::cout << "\n��������:\n";
	for (auto&& [key, value] : mp) {
		if (key == marsh) {
			std::cout << value.name;
			flag = true;
		}
	}
	if (flag == false) {
		throw std::exception("� �� �����");
	}
}

void replace_driver(std::map<int, Driver>& mp) {
	bool flag = false;
	std::cout << "���� ������:\n"; // ��� � ����� ������
	std::string first_name;
	std::cin >> first_name;
	std::cout << "�� ���� ������\n";
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
		throw std::exception("� �� �����");
	}
}


void find_the_marsh_by_driver(std::map<int, Driver>& mp) {
	bool flag = false;
	std::cout << "������� ��� ��������\n";
	std::string name_of_the_driver;
	std::cin >> name_of_the_driver;
	
	for (auto&& [key, value] : mp) {
		if (value.name == name_of_the_driver) {
			std::cout <<"����� �������� : " << key;
			flag = true;
		}
	}
	if (flag == false) {
		throw std::exception("� �� �����");
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
		std::cout << "\t\t\t\t��� �� ��������?\n";
		std::cout << "����� 1: �������� �����\n";
		std::cout << "����� 2: ���������� �� ������ �������� � �� ������ ��������\n";
		std::cout << "����� 3: ������ � map\n";
		std::cout << "����� 4: ������� ������ ���� ����� ��������� ���������� ��������\n";
		std::cout << "����� 5: ������� ������ ���� ��������� ���������� ��������\n";
		std::cout << "����� 6: ����������� ����������� ���������� (������ ��������)\n";
		std::cout << "����� 7: ����� �������, �� ������� �������� ��������� ��������\n";

		switch (_getch())
		{
		case '1':
			system("cls");
			check_file(file, filePath);
			std::cout << "\n\n������� ����������? ���� ��,�� ������� 1\n\n";
			switch (_getch())
			{
			case '1':
				menu();
				break;
			default:
				system("cls");
				std::cout << "���-���.\n";
				break;
			}
			break;
		case '2':
			system("cls");
			sorted_in_order(driver);
			print_driver(driver);
			std::cout << "\n\n������� ����������? ���� ��,�� ������� 1\n\n";
			switch (_getch())
			{
			case '1':
				menu();
				break;
			default:
				system("cls");
				std::cout << "���-���.\n";
				break;
			}
			break;
		case '3':
			system("cls");
			print_map(mp);
			std::cout << "\n\n������� ����������? ���� ��,�� ������� 1\n\n";
			switch (_getch())
			{
			case '1':
				menu();
				break;
			default:
				system("cls");
				std::cout << "���-���.\n";
				break;
			}
			break;
		case '4':
			system("cls");
			print_list_marsh(mp);
			std::cout << "\n\n������� ����������? ���� ��,�� ������� 1\n\n";
			switch (_getch())
			{
			case '1':
				menu();
				break;
			default:
				system("cls");
				std::cout << "���-���.\n";
				break;
			}
			break;
		case '5':
			system("cls");
			print_for_driver(mp);
			std::cout << "\n\n������� ����������? ���� ��,�� ������� 1\n\n";
			switch (_getch())
			{
			case '1':
				menu();
				break;
			default:
				system("cls");
				std::cout << "���-���.\n";
				break;
			}
			break;
		case '6':
			system("cls");
			replace_driver(mp);
			std::cout << "\n\n������� ����������? ���� ��,�� ������� 1\n\n";
			switch (_getch())
			{
			case '1':
				menu();
				break;
			default:
				system("cls");
				std::cout << "���-���.\n";
				break;
			}
			break;
		case '7':
			system("cls");
			find_the_marsh_by_driver(mp);
			break;
		default:
			system("cls");
			std::cout << "���������� �����\n";
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