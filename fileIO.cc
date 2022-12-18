#include "fileIO.hh"

std::vector<std::string> F4HUSTER::remove_comma(char *str)
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

double F4HUSTER::arrayToNumber(char *s)
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

std::vector<double> F4HUSTER::STR_TO_DOUBLE(std::vector<std::string> input)
{
    std::vector<double> output;
    for (auto word : input)
        output.push_back(arrayToNumber(&word[0]));
    return output;
}

MATRIX F4HUSTER::transpose(MATRIX &records)
{
    if (records.size() == 0)
        return records;
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

void F4HUSTER::_throw(char *exe_name, int argc)
{
    std::cout << "Usage: "<<exe_name<<" ";
    for (int i = 0; i < argc - 1; i++)
        std::cout << "<Diabetes/xyz.csv> ";
    std::cout << std::endl;
}