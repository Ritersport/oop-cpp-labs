#pragma once
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <sstream>




class Parser
{
public:
	std::map <int, std::vector <std::string>> blocks;

	std::map <int, std::vector <std::string>> parse(std::string schemeFilename);

};

