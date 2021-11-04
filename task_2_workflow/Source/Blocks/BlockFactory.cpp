#include "BlockFactory.h"

BlockFactory* BlockFactory::_instance = nullptr;

void BlockFactory::registr(std::string blockName, IBlockMaker* maker) {

	this->blocks.insert(std::pair<std::string, IBlockMaker*>(blockName, maker));

}

IWorker* BlockFactory::createBlock(std::string blockName)
{

	auto block = this->blocks.find(blockName);
	if (block == this->blocks.end())
		throw(std::exception("Error: block does not exist"));
	IBlockMaker* maker = block->second;
	return maker->create();

}
