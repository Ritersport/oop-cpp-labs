#include "Parser.h"

std::map <int, std::vector <std::string>> Parser::parse(std::string schemeFilename)
{
	std::map <int, std::vector <std::string>> blocks;
	std::ifstream schemeFile(schemeFilename);
	
	if (!schemeFile)
		throw(std::exception("Error: scheme-file is not opened"));

	std::string text = "";

	bool isWordFound = false;

	while (!schemeFile.eof()) {
		schemeFile >> text;
		int wordBeginning = text.find("desc");
		if (wordBeginning != -1) {
			isWordFound = true;
			break;
		}
	}
	if (!isWordFound)
		throw(std::exception("Error: key word desc is not found"));
	schemeFile.seekg(0);

	isWordFound = false;

	while (!schemeFile.eof()) {
		schemeFile >> text;
		int wordBeginning = text.find("csed");
		if (wordBeginning != -1) {
			isWordFound = true;
			break;
		}
	}
	if (!isWordFound)
		throw(std::exception("Error: key word csed is not found"));
	schemeFile.seekg(0);


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
				stringVector.push_back(word);  //pushing command in vector word by word

			int idOfBlock = std::stoi(id, 0, 10);
			blocks.insert(std::pair <int, std::vector <std::string>>(idOfBlock, stringVector));
		}

		else
			strInput = id;

	}

	return blocks;
}