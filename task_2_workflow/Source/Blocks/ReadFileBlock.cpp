#include "ReadFileBlock.h"

static BlockMaker<ReadFileBlock> readFileBlockMaker("readfile");

void ReadFileBlock::work(std::vector <std::string> arguments, std::string* text)
{
    //arguments[1] == "filename.txt"

    std::ifstream in(arguments[1]);
    in.seekg(0, std::ios::end);
    size_t size = in.tellg();
    std::string fileContent(size, ' ');
    in.seekg(0);
    in.read(&fileContent[0], size);
    *text = fileContent;
}

int ReadFileBlock::getNumOfParams()
{
    return 1;
}

BLOCK_TYPE ReadFileBlock::getTypeOfBlock()
{
    return IN;
}
