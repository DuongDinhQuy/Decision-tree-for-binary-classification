#include "readfile.hh"

std::vector<std::string> QUANG::remove_comma(char *str)
{
    std::vector<std::string> words;

    char *token = strtok(str, ",");
    while (token != NULL)
    {
        words.push_back(token);
        token = strtok(NULL, ",");
    }
    return words;
}

void QUANG::nhap(STRING_MATRIX &datasheet, std::ifstream *datafile)
{
    std::string line;
    while (getline(*datafile, line))
        datasheet.push_back(remove_comma(&line[0]));
}
STRING_MATRIX QUANG::transpose(STRING_MATRIX &datasheet)
{
    STRING_MATRIX trans;
    std::vector<std::string> *feature = new std::vector<std::string>(datasheet.size());

    for (int j = 0; j < datasheet[0].size(); j++)
    {
        for (int i = 0; i < datasheet.size(); i++)
        {
            (*feature)[i] = datasheet[i][j];
        }
        trans.push_back(*feature);
    }
    return trans;
}


