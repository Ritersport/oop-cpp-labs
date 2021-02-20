#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

#include "Blocks\BlockFactory.h"


class Validator
{
public:
	std::vector <int> chain;

	void getChain(std::string schemeFilename);

	bool check(std::map<int, std::vector <std::string>> blocks, BlockFactory *factory);

private:
	bool checkIdExists(std::map<int, std::vector <std::string>> blocks);

	bool checkUniqueness();

	bool checkArguments(std::map<int, std::vector<std::string>> blocks, BlockFactory* factory);

	bool checkFirstLast(std::map<int, std::vector<std::string>> blocks, BlockFactory* factory);

	bool checkCorrectTypes(std::map<int, std::vector<std::string>> blocks, BlockFactory* factory);
	
};
