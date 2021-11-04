#include "GrepBlock.h"

static BlockMaker <GrepBlock> grepBlockMaker("grep"); 

void GrepBlock::work(std::vector <std::string> arguments, std::string* text)
{
    //arguments[1] == word

    std::string* newText = new std::string;
    *newText = "";
    int strBeginning = 0;
    int strEnding = 0;
    int wordBeginning = text->find(arguments[1]);
    int localWordCount = 0; //amount of "word" in current string

    strEnding = text->find_first_of('\n', strBeginning);

    while ((strBeginning != strEnding + 1) && (wordBeginning != -1) && (strEnding != -1))
    {

        if ((wordBeginning >= strBeginning) && (wordBeginning < strEnding)) {

            localWordCount++;
            int length = strEnding - strBeginning + 1;
            if (localWordCount == 1)
                *newText += text->substr(strBeginning, length);
            wordBeginning = text->find(arguments[1], wordBeginning + 1);

        }
        else {

            localWordCount = 0;
            strBeginning = strEnding + 1;
            strEnding = text->find_first_of('\n', strBeginning);

        }
    }
    *text = *newText;
}

int GrepBlock::getNumOfParams()
{
    return 1;
}

BLOCK_TYPE GrepBlock::getTypeOfBlock()
{
    return INOUT;
}
