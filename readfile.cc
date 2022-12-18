#include "readfile.hh"
#include <stdlib.h>

    QUANG::dataset::dataset() {}
    QUANG::dataset::~dataset() {}
    QUANG::dataset::dataset(std::ifstream *datafile)
    {
        std::string line;
        getline(*datafile, line);
        this->feature_names = remove_comma(&line[0]);
        while (getline(*datafile, line))
            (this->records).push_back(STR_TO_DOUBLE(remove_comma(&line[0])));
    }


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

double QUANG::arrayToNumber(char *s)
{
    int a = 0;
    int b = 0;
    for (char *p = s; char digit = *p; p++)
    {
        if (digit == '.')
        {
            b = 1;
            continue;
        }
        a = a * 10 + digit - '0';
        if (b)
            b *= 10;
    }
    return (b > 1 ? (double)a / b : a);
}

std::vector<double> QUANG::STR_TO_DOUBLE(std::vector<std::string> input)
{
    std::vector<double> output;
    for (auto word : input)
        output.push_back(arrayToNumber(&word[0]));
    return output;
}


MATRIX QUANG::transpose(MATRIX &records)
{
    if(records.size() == 0) return records;
    MATRIX trans;
    std::vector<double> *feature = new std::vector<double>(records.size());

    for (int j = 0; j < records[0].size(); j++)
    {
        for (int i = 0; i < records.size(); i++)
        {
            (*feature)[i] = records[i][j];
        }
        trans.push_back(*feature);
    }
    return trans;
}