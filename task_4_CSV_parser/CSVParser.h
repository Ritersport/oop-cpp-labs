#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <tuple>
#include <algorithm>

#include "TupleReader.h"

template<typename... Args>
class CSVParser
{
private:
	size_t skip;
	std::ifstream& in;
	std::streampos readBeginning;
	char columnDelim;
	char lineDelim;

	void skipLines(size_t skip);
public:
	CSVParser <Args...>(std::ifstream& ifstream, size_t skip = 0, char columnDelim = ',', char lineDelim = '\n')
		: skip(skip), in(ifstream), columnDelim(columnDelim), lineDelim(lineDelim)
	{
		skipLines(skip);
		readBeginning = in.tellg();
	}

	class TupleIterator {

	private:
		std::tuple<Args...>* p_tuple;
		std::streampos curr_pos;
		bool isEOF;
		std::ifstream& in;
		char columnDelim;
		char lineDelim;
		int row;

	public:
		TupleIterator(std::streampos pos, bool isEOF, std::ifstream& in, char columnDelim, char lineDelim, int row)
			: isEOF(isEOF), curr_pos(pos), in(in), columnDelim(columnDelim), lineDelim(lineDelim), row(row) {
			p_tuple = new std::tuple<Args...>;
			if (isEOF)
				return;
			readTuple();
		}

		~TupleIterator() {
			delete p_tuple;
		}

		TupleIterator& operator++() {
			readTuple();
			return *this;
		}

		TupleIterator operator++(int) {
			TupleIterator old = *this;
			readTuple();
			return old;
		}

		bool operator!=(const TupleIterator& second) {
			if (second.isEOF && this->isEOF)
				return false;
			return (second.p_tuple != this->p_tuple);
		}

		bool operator==(const TupleIterator& second) {
			if (second.isEOF && this->isEOF)
				return true;
			return (second.p_tuple == this->p_tuple);
		}

		std::tuple<Args...> &operator*() const {
			return *p_tuple;
		}

		void readTuple();
	};

	TupleIterator begin() {
		return TupleIterator(readBeginning, false, in, columnDelim, lineDelim, skip + 1);
	}

	TupleIterator end() {
		return TupleIterator(EOF, true, in, columnDelim, lineDelim, 0);
	}

	class NewCT : public std::ctype<char> {
	private:
		mask ch[table_size];

	public:
		explicit NewCT(char delimiter, size_t refs = 0)
			: std::ctype<char>(&ch[0], false, refs)
		{
			std::copy_n(classic_table(), table_size, ch);
			ch[' '] &= ~space;
			ch[delimiter] = space;
		}
	};
};

template<typename ...Args>
inline void CSVParser<Args...>::skipLines(size_t skip)
{
	std::string skipLine = "";
	for (size_t i = 0; i < skip; i++) {
		std::getline(in, skipLine, '\n');
	}
}

template<typename ...Args>
inline void CSVParser<Args...>::TupleIterator::readTuple()
{
		if (curr_pos == EOF) {
			isEOF = true;
			return;
		}
		in.seekg(curr_pos);
		std::string currLine;
		std::getline(in, currLine, lineDelim);

		curr_pos = in.tellg();

		std::istringstream lineStream(currLine);
		lineStream.imbue(std::locale( std::locale::classic(), new NewCT(columnDelim)));
		*p_tuple = TupleReader<sizeof...(Args), Args...>::read(lineStream, row);
		row++;
}