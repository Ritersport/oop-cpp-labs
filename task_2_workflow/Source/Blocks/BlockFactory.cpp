#include "BlockFactory.h"

BlockFactory* BlockFactory::_instance = nullptr;

void BlockFactory::registr(std::string blockName, IBlockMaker* maker) {

	this->blocks.insert(std::pair<std::string, IBlockMaker*>(blockName, maker));

}

Worker* BlockFactory::createBlock(std::string blockName)
{

	auto block = this->blocks.find(blockName);
	IBlockMaker* maker = block->second;
	return maker->create();

}
