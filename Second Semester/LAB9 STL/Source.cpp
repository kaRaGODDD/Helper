#include "Flower.h"


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


void parse_all(std::fstream& file, const std::string& filePath, std::fstream& flowers, const std::string& flowersPath, std::string& str, std::regex e, std::string& noname, std::vector<Flower>& flow, std::map<std::string, int>& mp) {
	file.open(filePath, std::ios::in);
	
	Flower fl;

	int number{};

	std::string form{};

	while (std::getline(file, str)) {
		std::sregex_iterator pos(str.cbegin(), str.cend(), e);
		std::sregex_iterator end;
		for (; pos != end; ++pos) {
			std::string flower = pos->str(3);
			std::replace(flower.begin(), flower.end(), ',', ' ');
			number = stoi(pos->str(1));
			form = pos->str(2);
			std::list<std::string> lst;
			lst.push_back(flower);
			fl.setFlowers(lst);
			fl.setForm(form);
			fl.setNumber(number);
			mp.insert(std::make_pair(flower, number));
		}
		flow.push_back(fl);
	}

	file.close();
	flowers.close();
}

void print_vector_of_flowers(std::vector<Flower>& flow) {
	std::copy(flow.begin(), flow.end(), std::ostream_iterator<Flower>(std::cout, " "));
}

void sorted_by_geometrical_shape(std::vector<Flower>& flow) {
	std::sort(flow.begin(), flow.end(), [](const Flower& a, const Flower& b) {
		if (a.getForm() != b.getForm()) {
			std::string str1 = a.getForm();
			std::string str2 = b.getForm();
			std::transform(str1.begin(), str1.end(), str1.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c); });
			std::transform(str2.begin(), str2.end(), str2.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c); });
			return str1 < str2;
		}
		else {
			return a.getNumber() < b.getNumber();
		}
		});
}


void without_repeats(std::map<std::string, int>& mp) {
	std::cout << "Без повторов и в отсортированном порядке:\n\n";
	for (const auto& x : mp) {
		std::cout << x.first << "\n";
	}
}


void print_map(std::map<std::string, int>& mp) {
	std::cout << "Список цветов:\n\n";
	for (auto&& [key, value] : mp) {
		std::cout << "Клумба c цветком -> " << key << " ее номер: " << value << "\n";
	}
	std::cout << "\n\n";
}



void find_the_garden(std::map<std::string, int>& mp, std::vector<Flower>& flow) {

	std::string flower;
	std::cout << "Введите название цветка для поиска: ";
	std::cin >> flower;
	std::cout << "\nКлумбы, на которых нет " << flower << ": \n\n";
	bool flag = false;

	for (const auto& i : flow)
	{
		auto flowers = i.getFlowers();
		if (find_if(flowers.begin(), flowers.end(), [&](const std::string& _flower) {
			return _flower == flower;
			}
		) == flowers.end())
		{
			flag = true;
			std::cout << '\n' << i;
		}
	}
	if (!flag)
	{
		std::cout << "Отсутствуют";
	}
}

void count_diff_flowers(std::vector<Flower>& flow) {
	std::cout << "Введите количество различных цветов\n";
	int n;
	std::cin >> n;
	std::cout << "Различные виды цветов: " << std::count_if(flow.begin(), flow.end(), [&n](const Flower& clumb) {
		return clumb.getFlowers().size() == n;
	}) << "\n";
}

void replace_by_flower(std::map<std::string, int>& mp, std::vector<Flower>& flow) {

	std::cout << "Что меняем?\n";
	std::string old;
	std::cin >> old;
	
	std::cout << "\nНа что меняем?\n";
	std::string news;
	std::cin >> news;
	

	std::cout << "\nСтарый список цветов\n";

	for (const auto& x : flow) {
		std::list<std::string> temp = x.getFlowers();
		for (auto&& y : temp) {
			std::cout << y << "\n";
		}
	}

	std::list<std::string> st;
	std::cout << "\nНовый список цветов\n";

	for (int i = 0; i < flow.size(); ++i) {
		st = flow[i].getFlowers();
		for (int j = 0; j < st.size(); ++j) {
			std::replace(st.begin(), st.end(), old, news);
		}
		for (const auto& k : st) {
			std::cout << k << "\n";
		}
	}


}

void _all_of(std::vector<Flower>& flow) {

	std::set<std::string, std::less<std::string>> flowers;
	std::list<std::string> temp_flowers;

	for (auto& i : flow) {
		for (auto& j : i.getFlowers()) {
			flowers.insert(j);
		}
	}

	std::cout << "Список всех цветов : \n";
	for (auto& i : flowers) {
		std::cout << i << " ";
	}

	bool flag = false, found = false;

	
	for (auto& x : flowers)
	{
		if (all_of(flow.begin(), flow.end(), [&](const Flower& clumb) {
			flag = false;
			for (const auto& k : clumb.getFlowers())
			{
				if (k == x)
				{
					flag = true;
				}
			}
			return flag;
			}
		)) {
			std::cout << x << " Растут на всех клумбах\n";
			found = true;
		}
	}
	if (!found)
	{
		std::cout << "\nНет цветов, которые растут на всех клумбах!\n" ;
	}
}


void menu() {
	try
	{
		system("cls");

		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		std::regex e("([0-9]+);([\\D]+);([\\D]+)");
	

		std::fstream file;
		std::string filePath = "text.txt";

		std::fstream flowers;
		std::string flowersPath = "flowers.txt";

		std::string str;
		std::string noname;

		std::vector<Flower> flow;

		std::map<std::string, int> mp;


		//get_list_of_flowers(file, filePath, flowers, flowersPath, str, e);
		parse_all(file, filePath, flowers, flowersPath, str, e, noname, flow, mp);


		std::cout << "\t\t\t\t Что вы хотите выбрать?\n";
		std::cout << "Пункт 1: Проверка файла.\n";
		std::cout << "Пункт 2: Сортировка по геометрической форме и вывод.\n";
		std::cout << "Пункт 3: Вывод списка цветов без повторов.\n";
		std::cout << "Пункт 4: Поиск клумбы, на которой нет заданного цветка.\n";
		std::cout << "Пункт 5: Найти цветок растущий на всех клумбах.\n";
		std::cout << "Пункт 6: Подсчет числа клумб, на которых растет заданное число различных цветов.\n";
		std::cout << "Пункт 7: Замена указанного цветка на другой цветок.\n";
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
			sorted_by_geometrical_shape(flow);
			print_vector_of_flowers(flow);
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
			without_repeats(mp);
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
			find_the_garden(mp, flow);
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
			_all_of(flow);
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
			count_diff_flowers(flow);
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
			replace_by_flower(mp, flow);
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
	system("cls");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::regex e("([0-9]+);([\\D]+);([\\D]+)");
	std::regex regular("([\\D]+)\\s([\\D]+)\\s([\\D]+)");

	std::fstream file;
	std::string filePath = "text.txt";

	std::fstream flowers;
	std::string flowersPath = "flowers.txt";

	std::string str;
	std::string noname;

	std::vector<Flower> flow;

	std::map<std::string, int> mp;

	
	
	
	//parse_all(file, filePath, flowers, flowersPath, str, e, noname, flow, regular, mp);
	parse_all(file, filePath, flowers, flowersPath, str, e, noname, flow, mp);
	//print_vector_of_flowers(flow);
	menu();

	std::cout << "\n";
	system("pause");
	return EXIT_SUCCESS;
}