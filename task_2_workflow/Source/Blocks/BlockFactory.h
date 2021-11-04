#pragma once

#include "IBlockMaker.h"

#include <map>


class BlockFactory {
private:
	static BlockFactory* _instance;

	std::map <std::string, IBlockMaker*> blocks;

	BlockFactory() {

	}

public:
	static BlockFactory* Instance() {
		if (_instance == nullptr) {
			_instance = new BlockFactory;
		}
		return _instance;
	}

	void registr(std::string blockName, IBlockMaker* maker);

	IWorker* createBlock(std::string blockName);
};

