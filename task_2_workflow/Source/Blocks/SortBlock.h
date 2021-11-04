#pragma once

#include <algorithm>

#include "GrepBlock.h"

class SortBlock : public IWorker
{
public:
	virtual void work(std::vector <std::string> arguments, std::string* text);

	virtual int getNumOfParams();

	virtual BLOCK_TYPE getTypeOfBlock();
};

