#pragma once
#include <fstream>
#include <vector>
#include <string.h>

#define MATRIX std::vector<std::vector<double>>

namespace QUANG
{
    class dataset
    {
    public:
        dataset();
        ~dataset();
        std::vector<std::string> feature_names;
        MATRIX records;
        dataset(std::ifstream *datafile);
    };
    std::vector<std::string> remove_comma(char *str);
    double arrayToNumber(char *s);
    std::vector<double> STR_TO_DOUBLE(std::vector<std::string> input);
    MATRIX transpose(MATRIX &records);
}

