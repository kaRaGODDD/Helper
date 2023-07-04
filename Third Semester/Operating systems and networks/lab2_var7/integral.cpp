#include "Integral.h"

Integral::Integral() :
	_eps(0.001), _number_of_partitions(4), _a(3), _b(7), _calc_result(0)
{}

Integral::Integral(int _a, int b_, long double eps) : _a(_a), _b(_b), _eps(_eps)
{

	if (eps <= 0 || eps >= 1) {
		throw std::runtime_error("Wrong value for epsilon");
	}

	if (_a > _b) {
		std::swap(_a, _b);
	}

}

Integral::Integral(const Integral& right) : _eps(right._eps), _number_of_partitions(right._number_of_partitions),
_a(right._a), _b(right._b), _calc_result(right._calc_result)
{}

long double Integral::calculation__of_the_integral() noexcept
{

	long double h = 0.0, sum1 = 0.0, sum2 = 0.0;
	h = (2 - 1) / static_cast<long double>(_number_of_partitions);
	sum2 = static_cast<long double>(h * ((function_for_calculating_integral(1) + function_for_calculating_integral(2)) / 2.0));
	for (int step = 1; step < _number_of_partitions; step++)
	{
		sum2 += h * function_for_calculating_integral(1 + h * step);
	}

	while (fabs(sum1 - sum2) > _eps)
	{
		sum1 = sum2;
		_number_of_partitions *= 2; h /= 2;
		sum2 = static_cast<long double>(h * ((function_for_calculating_integral(1) + function_for_calculating_integral(2)) / 2.0));
		for (int step = 1; step < _number_of_partitions; step++)
		{
			sum2 += h * function_for_calculating_integral(1 + h * step);
		}
	}
	this->_calc_result = std::move(sum2);

	return _calc_result;
}


void Integral::generate_task_count(const std::size_t& task_count, std::vector<Integral>& vector_of_the_integrals) noexcept
{
	for (std::uint_fast32_t i = 0; i < task_count; ++i) {
		(*this).generate_parameters();
		vector_of_the_integrals.push_back(*this);
	}
}

void Integral::_doing(const std::size_t& task_count, const std::size_t& thread_count, std::vector<Integral>& vector_of_the_integrals, Integral& object,
	Stats& _statistic, std::vector<Stats>& _vec_of_stat, std::vector<std::future<void>>& _future_vec, std::uint_fast32_t& completed_tasks) noexcept
{

	int _real_thread = thread_count + 1;
	if (thread_count != 0) {
		for (std::uint_fast32_t i{}; i < task_count; ++i) {
			_future_vec[i % thread_count] = std::async(std::launch::async, std::bind(&Integral::one_for_all, *this, std::ref(task_count), std::ref(vector_of_the_integrals[i]), std::ref(_vec_of_stat[i % _real_thread]),
				std::ref(completed_tasks)));
		}
	}
	else {
		for (int i = 0; i < task_count; ++i) {
			std::async(std::launch::async, std::bind(&Integral::one_for_all, *this, std::ref(task_count), std::ref(vector_of_the_integrals[i]), std::ref(_vec_of_stat[i % _real_thread]),
				std::ref(completed_tasks)));
		}
	}

	for (auto&& x : _future_vec) {
		if (x.valid()) {
			x.get();
		}
	}

}

void Integral::one_for_all(const std::size_t& task_count, Integral& integral, Stats& _statistics, std::uint_fast32_t& _completed_tasks)
{
	std::mutex mtx;
	std::unique_lock<std::mutex> ulm(mtx);
	std::ofstream file("thread_param.txt", std::ios::app);
	std::this_thread::sleep_for(std::chrono::milliseconds(5));

	std::thread::id threadId = std::this_thread::get_id();

	std::size_t _identifier = *static_cast<unsigned int*>(static_cast<void*>(&threadId));

	auto _time_start = std::chrono::high_resolution_clock::now();
	integral.calculation__of_the_integral();
	auto _time_end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> _duration = _time_end - _time_start;

	auto _time_start1 = std::chrono::high_resolution_clock::now();
	file << "\n" << "eps " << integral.get_eps() << "\n" << "a " << integral.get_a() << "\n" << "b " << integral.get_b() << "\n" << "partition " << integral.get_numbers_of_partitions() << "\n" << "calc res " << integral.get_calc_result() << "\n\n";
	auto _time_end1 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> _duration1 = _time_end - _time_start;

	_statistics.thread_id = _identifier;
	_statistics._duration += _duration.count();
	_statistics.error = 0;
	_statistics.no_solution = 0;
	_statistics.amount_of_task++;
	_statistics.time.push_back(_duration.count());
	_statistics._to_file = _duration1.count();

	file.close();
}


void Integral::task_b(const std::size_t& task_count, const std::size_t& thread_count)
{

	int _real_thread = thread_count + 1;
	std::vector<Integral> vector_of_the_integrals{};
	std::vector<std::future<void>>	_future_vec(thread_count);
	Stats _statistic;
	std::vector<Stats> _statistics(_real_thread);
	Integral obj{};
	Stats	_example{};
	std::uint_fast32_t	completed_tasks{};
	std::ofstream file("thread_param.txt");
	(*this).generate_task_count(task_count, vector_of_the_integrals);
	(*this)._doing(task_count, thread_count, vector_of_the_integrals, obj, _statistic, _statistics, _future_vec, completed_tasks);
	(*this).show_statistics(_statistics, file, completed_tasks, task_count);

}

void Integral::run()
{
	std::cout << "1 - First task\n2 - Second task\n";
	try {
		switch (_getch())
		{
		case '1':
		{

			system("cls");

			std::fstream config;
			std::string config_path = "config.txt";
			std::fstream output;
			std::string  output_path = "output.txt";

			(*this).check(config,config_path);

			std::thread first_task([&, this]() {
				(*this).task_a(config, config_path, output, output_path);
			});
			if (first_task.joinable()) {
				first_task.join();
			}
			break;
		}
		case '2':
		{
			system("cls");

			std::size_t task_count{};
			std::size_t thread_count{};
			std::cout << "Input task count\n";
			std::cin >> task_count;
			if (task_count <= 0) {
				exit(1);
				throw std::exception("invalid param");
			}
			std::cout << "Input thread count\n";
			std::cin >> thread_count;
			if (thread_count <= 0) {
				throw std::exception("invalid param");
			}
			system("cls");
			--thread_count;
			(*this).task_b(task_count, thread_count);
			break;
		}
		
		default:
			system("cls");
			std::cout << "Invalid choose try again\n";
			break;
		}
	}
	catch (const std::exception& ex) {
		std::cout << ex.what();
	}
}

void Integral::task_a(std::fstream& config, const std::string& config_path, std::fstream& output, const std::string& output_path)
{
	timer t;
	config.open(config_path, std::ios::in);
	output.open(output_path, std::ios::out);

	config >> *this;

	(*this).calculation__of_the_integral();

	output << *this;

	std::cout << "\nThe result of calculation of the integral is -> " << (*this)._calc_result << "\n";

	output.close();
	config.close();

}



void Integral::show_statistics(std::vector<Stats>& _vec_of_stat, std::ofstream& file, std::uint_fast32_t& _completed_tasks, const std::size_t& task_count) noexcept
{

	for (int i = 0; i < _vec_of_stat.size(); ++i) {
		if (_vec_of_stat[i].time.size() != 0) {
			std::cout << "\nThread id: -> " << _vec_of_stat[i].thread_id << "\n" << "solve -> " << _vec_of_stat[i].amount_of_task << "\nno solution: " << _vec_of_stat[i].no_solution << "\nerror " << _vec_of_stat[i].error << "\n"
				<< "max time: " << *std::max_element(_vec_of_stat[i].time.begin(), _vec_of_stat[i].time.end()) << "\n" << "min time " << *std::min_element(_vec_of_stat[i].time.begin(), _vec_of_stat[i].time.end()) << "\n";
		}
	}

	int all{};
	for (const auto& x : _vec_of_stat) {
		all += x.amount_of_task;
	}
	float to_file{};
	std::cout << "\n\nTask solved -> " << all << "\n\n";
	for (const auto& x : _vec_of_stat) {

		to_file += x._to_file;
	}
	std::cout << "to file " << to_file << "s" << "\n";
}

double Integral::function_for_calculating_integral(double x) noexcept
{
	return _a * cos(x) / (_b * std::pow(x, 2));
}

void Integral::generate_parameters() noexcept
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(-500, 500);
	_a = dist(rd);
	_b = dist(rd);
	if (_a > _b) {
		std::swap(_a, _b);
	}
	std::uniform_real_distribution<double> _distribution(0, 1);
	_eps = _distribution(rd);

}


long double Integral::get_eps() const noexcept
{
	return _eps;
}

long long Integral::get_numbers_of_partitions() const noexcept
{
	return _number_of_partitions;
}

int Integral::get_a() const noexcept
{
	return _a;
}

int Integral::get_b() const noexcept
{
	return _b;
}

long double Integral::get_calc_result() const noexcept
{
	return _calc_result;
}

void Integral::check(std::fstream& config, const std::string& config_path)
{
	config.open(config_path,std::ios::in);
	Integral _integral;
	config >> _integral;
	config.close();
}



std::ostream& operator<<(std::ostream& out, const Integral& right)
{

	out << "\n\t-------RESULT-------\n";
	out << "\n\n\tvalue of epsilon " << right._eps << "\n";
	out << "\tfrom " << right._a << "\n";
	out << "\tto   " << right._b << "\n";
	out << "\n\n\tNumber of partitions " << right._number_of_partitions << "\n";
	out << "\tresult " << right._calc_result << "\n";
	out << "\n\n";
	return out;

}

std::istream& operator>>(std::istream& in, Integral& right)
{
	in >> right._a;
	in >> right._b;
	if (right._a > right._b) {
		std::swap(right._a, right._b);
	}
	in >> right._eps;
	if (right._eps <= 0 || right._eps >= 1) {
		throw std::runtime_error("Wrong value for epsilon");
	}
	return in;
}

