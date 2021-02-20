#include "WriteFileBlock.h"

static BlockMaker<WriteFileBlock> writeFileBlockMaker("writefile");

void WriteFileBlock::work(std::vector <std::string> arguments, std::string* text)
{
    std::ofstream out(arguments[1]);
    out << *text;
}

int WriteFileBlock::getNumOfParams()
{
    return 1;
}

BLOCK_TYPE WriteFileBlock::getTypeOfBlock()
{
    return OUT;
}
