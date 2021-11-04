#include "ReadFileBlock.h"

static BlockMaker<ReadFileBlock> readFileBlockMaker("readfile");

void ReadFileBlock::work(std::vector <std::string> arguments, std::string* text)
{
    const char* c = arguments[1].c_str();
    FILE* file;
    fopen_s(&file, c, "rb");
    if (file == NULL)
    {
        throw(std::exception("ReadFile block error: text-file is not opened"));
    }
    fclose(file);
    std::ifstream in(arguments[1]); //arguments[1] == "filename.txt"
    in.seekg(0, std::ios::end);
    size_t size = in.tellg();
    char* fileContent = new char[size];
    in.seekg(0);
    in.read(fileContent, size);
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
