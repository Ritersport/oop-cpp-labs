#pragma once
#include "WriteFileBlock.h"

class GrepBlock : public IWorker
{
public:
	virtual void work(std::vector <std::string> arguments, std::string* text);

	virtual int getNumOfParams();

	virtual BLOCK_TYPE getTypeOfBlock();

	virtual ~GrepBlock() = default;
};

