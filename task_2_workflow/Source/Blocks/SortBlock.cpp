#include "SortBlock.h"

static BlockMaker<SortBlock> sortBlockMaker("sort");

void SortBlock::work(std::vector <std::string> arguments, std::string* text)
{
    std::vector <std::string> strs;
    std::string* newText = new std::string;
    *newText = "";
    int strBeginning = 0;
    int strEnding = 0;
    strEnding = text->find_first_of('\n', strBeginning);

    while ((strBeginning != strEnding + 1) && (strEnding != -1))
    {
        int length = strEnding - strBeginning + 1;
        strs.push_back(text->substr(strBeginning, length));
        strBeginning = strEnding + 1;
        strEnding = text->find_first_of('\n', strBeginning);
    }
    std::sort(strs.begin(), strs.end());
    for (auto i = 0; i != strs.size(); i++) {
        *newText = *newText + strs[i];
    }
    *text = *newText;
}

int SortBlock::getNumOfParams()
{
    return 0;
}

BLOCK_TYPE SortBlock::getTypeOfBlock()
{
    return INOUT;
}
