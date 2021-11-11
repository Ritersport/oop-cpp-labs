#include "Workflow.h"


void Executor::execute(std::string schemeFilename)
{

	//creating map "id - block"
	Parser parser;
	std::map <int, std::vector <std::string>> blocks = parser.parse(schemeFilename);

	//creating chain of blocks
	Validator validator;
	validator.getChain(schemeFilename);

	BlockFactory* factory = BlockFactory::Instance();

	//checking the chain and blocks
	if (validator.check(blocks, factory)) {
	
		std::string* text = new std::string; 

		for (auto i = 0; i < validator.chain.size(); i++) {
			
			IWorker* block = factory->createBlock(blocks[validator.chain[i]][0]);
			block->work(blocks[validator.chain[i]], text);
		}
		delete text;
	}
}
