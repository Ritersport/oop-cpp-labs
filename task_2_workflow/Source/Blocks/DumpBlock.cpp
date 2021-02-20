#include "DumpBlock.h"

static BlockMaker<DumpBlock> dumpBlockMaker("dump");

void DumpBlock::work(std::vector <std::string> arguments, std::string* text)
{
    //arguments[1] == "filename.txt"
    std::ofstream out(arguments[1]);
    if (out)
        out << *text;
}

int DumpBlock::getNumOfParams()
{
    return 1;
}

BLOCK_TYPE DumpBlock::getTypeOfBlock()
{
    return INOUT;
}


