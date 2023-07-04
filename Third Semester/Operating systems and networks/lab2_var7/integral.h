#pragma once

#ifndef _INTEGRAL_H
#define _INTEGRAL_H

#include "lib.h"

#define TEST



struct Stats
{
	std::size_t amount_of_task{};
	std::size_t error{};
	std::size_t no_solution{};
	std::size_t thread_id{};
	float _duration{};
	float _to_file{};
	std::vector<float> time{};

};

class Integral
{
private:
	
	long double _eps{};
	long long _number_of_partitions{};
	int _a{},
		_b{};
	long double _calc_result{};
	std::size_t _completed_tasks{};
public:
	Integral();
	Integral(int _a, int b_, long double eps);
	Integral(const Integral&);
	~Integral() = default;
private:
	void show_statistics(std::vector<Stats>& _statistics,std::ofstream& file, std::uint_fast32_t& _completed_tasks, const std::size_t& task_count) noexcept;
	double function_for_calculating_integral(double x) noexcept;
	void generate_parameters() noexcept;
	void generate_task_count(const std::size_t& task_count,std::vector<Integral>& vector_of_the_integrals) noexcept;
	void _doing(const std::size_t& task_count, const std::size_t& thread_count, std::vector<Integral>& vector_of_the_integrals, Integral& object,
		Stats& _statistic,std::vector<Stats>& _vec_of_stat, std::vector<std::future<void>>& _future_vec, std::uint_fast32_t& completed_tasks) noexcept;
	void one_for_all(const std::size_t& task_count, Integral& integral,Stats& _statistics,std::uint_fast32_t& completed_tasks);
	long double calculation__of_the_integral() noexcept;
	long double get_eps() const noexcept;
	long long get_numbers_of_partitions() const noexcept;
	int get_a() const noexcept;
	int get_b() const noexcept;
	long double get_calc_result() const noexcept;
	void check(std::fstream& config, const std::string& config_path);
	void task_a(std::fstream& config, const std::string& config_path, std::fstream& output, const std::string& output_path);
	void task_b(const std::size_t& task_count, const std::size_t& thread_count);
public:
	void run();
public:
	friend std::ostream& operator << (std::ostream& out, const Integral&);
	friend std::istream& operator >> (std::istream& in, Integral&);
};

#endif
