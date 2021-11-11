#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <exception>


enum BLOCK_TYPE { IN, OUT, INOUT };

class IWorker
{
public:
	virtual void work(std::vector <std::string> arguments, std::string* text) = 0;

	virtual int getNumOfParams() = 0;

	virtual BLOCK_TYPE getTypeOfBlock() = 0;

	virtual ~IWorker() = default;
	
};

