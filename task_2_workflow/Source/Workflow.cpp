#include "Workflow.h"


void Executor::execute(std::string schemeFilename)
{
	const char* c = schemeFilename.c_str();
	FILE* file;
	fopen_s(&file, c, "rb");
	if (file == NULL)
	{
		throw(std::exception("Error: scheme-file is not opened. Write the filename as a parameter"));
	}
	fclose(file);

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
	}
}
