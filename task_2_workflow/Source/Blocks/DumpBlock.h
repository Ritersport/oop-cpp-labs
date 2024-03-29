#pragma once

#include <fstream>

#include "ReplaceBlock.h"

class DumpBlock : public IWorker
{
public:
	virtual void work(std::vector <std::string> arguments, std::string* text);

	virtual int getNumOfParams();

	virtual BLOCK_TYPE getTypeOfBlock();

	virtual ~DumpBlock() = default;
};

