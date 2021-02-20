#pragma once
#include "WriteFileBlock.h"

class GrepBlock : public Worker
{
public:
	virtual void work(std::vector <std::string> arguments, std::string* text);

	virtual int getNumOfParams();

	virtual BLOCK_TYPE getTypeOfBlock();
};

