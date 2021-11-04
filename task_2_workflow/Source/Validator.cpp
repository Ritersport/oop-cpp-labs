#include "Validator.h"


void Validator::getChain(std::string schemeFilename)
{
	std::ifstream schemeFile(schemeFilename);
	std::string strInput = "";

	while (strInput != "csed") {

		std::getline(schemeFile, strInput);
	}
	std::vector<int> chain;

	while (schemeFile) {

		std::string id;
		std::string trash;
		schemeFile >> id;
		if (id == "")
			throw(std::exception("Error: no scheme in file"));
		int id_int = std::stoi(id, 0, 10);
		chain.push_back(id_int);
		schemeFile >> trash;
		if (trash != "->" && trash != "")
			throw(std::exception("Error: invalid scheme format"));
	}
	this->chain = chain;
}

bool Validator::check(std::map<int, std::vector <std::string>> blocks, BlockFactory *factory)
{
	if (!(this->checkIdExists(blocks)))
		throw(std::exception("Error: wrong ID in scheme"));

	if (!(this->checkUniqueness()))
		throw(std::exception("Error: block ID are not unique"));
	
	if (!(this->checkArguments(blocks, factory)))
		throw(std::exception("Error: wrong amount of parametrs"));

	if (!(this->checkFirstLast(blocks, factory)))
		throw(std::exception("Error: wrong type of the first or of the last block"));

	if (!(this->checkCorrectTypes(blocks, factory)))
		throw(std::exception("Error: wrong type of block"));
		
	return true;
}

bool Validator::checkIdExists(std::map<int, std::vector <std::string>> blocks)
{
	int N = this->chain.capacity();

	for (int i = 0; i < N; i++) {

		if (blocks.find(this->chain[i]) == blocks.end())
			return false;
	}
	return true;
}

bool Validator::checkUniqueness()
{
	std::vector <int> sortChain = this->chain;
	sort(sortChain.begin(), sortChain.end());
	int N = sortChain.capacity();

	for (int i = 0; i < N - 1; i++) {

		if (sortChain[i] == sortChain[i + 1])
			return false;
	}
	return true;
}

bool Validator::checkArguments(std::map<int, std::vector <std::string>> blocks, BlockFactory *factory)
{
	for (auto i = blocks.begin(); i != blocks.end(); i++) {

		IWorker* block = factory->createBlock(i->second[0]);
		if (i->second.size() - 1 != block->getNumOfParams())
			return false;
	}
	return true;
}

bool Validator::checkFirstLast(std::map<int, std::vector <std::string>> blocks, BlockFactory* factory)
{

	IWorker* block = factory->createBlock(blocks.at(this->chain[0])[0]);
	if (block->getTypeOfBlock() != IN)
		return false;
	block = factory->createBlock(blocks.at(this->chain[this->chain.capacity() - 1])[0]);
	if (block->getTypeOfBlock() != OUT)
		return false;

	return true;
}

bool Validator::checkCorrectTypes(std::map<int, std::vector <std::string>> blocks, BlockFactory* factory)
{
	int N = this->chain.size();

	for (auto i = 1; i != N - 1; i++) {

		IWorker* block = factory->createBlock(blocks.at(this->chain[i])[0]);
		if (block->getTypeOfBlock() != INOUT)
			return false;
		
	}
	return true;
}
