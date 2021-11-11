#include "ReadFileBlock.h"

static BlockMaker<ReadFileBlock> readFileBlockMaker("readfile");

void ReadFileBlock::work(std::vector <std::string> arguments, std::string* text)
{
    std::ifstream in(arguments[1]); //arguments[1] == "filename.txt"
    if (!in)
        throw(std::exception("ReadFile block error: text-file is not opened"));
    in.seekg(0, std::ios::end);
    size_t size = in.tellg();
    char* fileContent = new char[size];
    in.seekg(0);
    in.read(fileContent, size);
    *text = fileContent; 
    delete fileContent;
}

int ReadFileBlock::getNumOfParams()
{
    return 1;
}

BLOCK_TYPE ReadFileBlock::getTypeOfBlock()
{
    return IN;
}
