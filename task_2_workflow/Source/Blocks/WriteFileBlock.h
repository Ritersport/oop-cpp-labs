#pragma once

#include <fstream>

#include "ReadFileBlock.h"

class WriteFileBlock : public Worker
{
	virtual void work(std::vector <std::string> arguments, std::string* text);

	virtual int getNumOfParams();

	virtual BLOCK_TYPE getTypeOfBlock();
};

