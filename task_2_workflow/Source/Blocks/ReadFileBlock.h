#pragma once

#include <fstream>

#include "BlockMaker.h"

class ReadFileBlock : public Worker
{
public:
	virtual void work(std::vector <std::string> arguments, std::string* text);

	virtual int getNumOfParams();

	virtual BLOCK_TYPE getTypeOfBlock();
};

