#pragma once
#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#define MATRIX std::vector<std::vector<double>>

namespace Pig4
{
    std::vector<std::string> remove_comma(char *str);
    double arrayToNumber(char *s);
    std::vector<double> STR_TO_DOUBLE(std::vector<std::string> input);
    MATRIX transpose(MATRIX &records);
    void _throw(char* exe_name, int argc);
}

