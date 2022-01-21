#pragma once

#include <tuple>
#include <sstream>
#include <stdexcept>
#include <string>

template <size_t N, typename Head, typename ...Args>
class TupleReader
{
public:
	static std::tuple<Head, Args...> read(std::istringstream& in, int row) {
		if (in.eof())
			throw std::logic_error("Not enough arguments");

		Head data;
		in >> data;

		if (in.fail())
			throw std::logic_error("Wrong type of argument: row " + std::to_string(row));

		return std::tuple_cat(std::make_tuple(data), TupleReader<N - 1, Args...>::read(in, row));
	}
};

template <typename Head>
class TupleReader<1, Head> 
{
public:
	static std::tuple<Head> read(std::istringstream& in, int row) {
		if (in.eof())
			throw std::logic_error("Not enough arguments");

		Head data;
		in >> data;
	
		if (in.fail())
			throw std::logic_error("Wrong type of argument: row " + std::to_string(row));
		return std::make_tuple(data);
	}
};