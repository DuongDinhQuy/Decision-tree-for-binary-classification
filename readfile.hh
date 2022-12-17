#pragma once
#include <fstream>
#include <vector>
#include <string.h>

#define STRING_MATRIX std::vector<std::vector<std::string>>

namespace QUANG
{
    std::vector<std::string> remove_comma(char *str);
    void nhap(STRING_MATRIX &datasheet, std::ifstream *datafile);
    STRING_MATRIX transpose(STRING_MATRIX &datasheet);
}