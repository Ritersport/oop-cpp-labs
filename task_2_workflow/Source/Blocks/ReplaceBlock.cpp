#include "ReplaceBlock.h"

static BlockMaker<ReplaceBlock> replaceBlockMaker("replace");

void ReplaceBlock::work(std::vector <std::string> arguments, std::string* text)
{

    std::string* newText = new std::string;
    *newText = *text;
    int word1Len = arguments[1].size();
    int word2Len = arguments[2].size();
    int wordBeginning = newText->find(arguments[1]);

    while (wordBeginning != -1) {

        newText->replace(wordBeginning, word1Len, arguments[2]);
        
        wordBeginning = newText->find(arguments[1], wordBeginning + word2Len);

    }
    *text = *newText;
}

int ReplaceBlock::getNumOfParams()
{
    return 2;
}

BLOCK_TYPE ReplaceBlock::getTypeOfBlock()
{
    return INOUT;
}
