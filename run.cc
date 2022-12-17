#include "readfile.hh"
#include <iostream>
int main(int argc, char *argv[])
{
    std::ifstream datafile(argv[1]);
    
    STRING_MATRIX datasheet;
    QUANG::nhap(datasheet, &datafile);
    datasheet = QUANG::transpose(datasheet);
    for (auto trainingExample : datasheet)
    {
        for (auto x : trainingExample)
            std::cout << x << " ";
        std::cout << std::endl;
    }
}

















