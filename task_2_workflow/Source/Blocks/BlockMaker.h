#pragma once

#include "..\Validator.h"

template <typename T>

class BlockMaker : public IBlockMaker {
public:
	BlockMaker(std::string blockName) {
		BlockFactory::Instance()->registr(blockName, this);
	}

	virtual Worker* create() const{
		return new T();
	}


};

	
	
