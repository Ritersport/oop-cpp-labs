#include "Parser.h"

std::map <int, std::vector <std::string>> Parser::parse(std::string schemeFilename)
{
	std::map <int, std::vector <std::string>> blocks;
	std::ifstream schemeFile(schemeFilename);
	
	std::string strInput = "";
	while (strInput != "desc") {
		schemeFile >> strInput;
	}

	while (strInput != "csed") {
		std::string id;
		std::string trash;
		schemeFile >> id;

		if (id != "csed") {
			schemeFile >> trash;
			std::getline(schemeFile, strInput);
			strInput.erase(0, 1);

			std::stringstream ss(strInput);
			std::string word;
			std::vector <std::string> stringVector;
			while (ss >> word)
				stringVector.push_back(word);

			int idOfBlock = std::stoi(id, 0, 10);
			blocks.insert(std::pair <int, std::vector <std::string>>(idOfBlock, stringVector));
		}

		else
			strInput = id;

	}

	return blocks;
}