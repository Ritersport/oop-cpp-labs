#include "DumpBlock.h"

static BlockMaker<DumpBlock> dumpBlockMaker("dump");

void DumpBlock::work(std::vector <std::string> arguments, std::string* text)
{
    std::ofstream out(arguments[1]); //arguments[1] == "filename.txt"
    if (!out)
        throw(std::exception("Dump block error: file is not opened"));
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


