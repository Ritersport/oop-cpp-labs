#pragma once

#include "SortBlock.h"

class ReplaceBlock : public IWorker
{
public:
	virtual void work(std::vector <std::string> arguments, std::string* text);

	virtual int getNumOfParams();

	virtual BLOCK_TYPE getTypeOfBlock();

	virtual ~ReplaceBlock() = default;
};

