#include "readfile.hh"
#include <iostream>
int main(int argc, char *argv[])
{
    std::ifstream datafile(argv[1]);

    QUANG::dataset database1(&datafile);

    for (auto name : database1.feature_names)
        std::cout << name;
    std::cout << std::endl;

    for (auto trainingExample : database1.records)
    {
        for (auto x : trainingExample)
            std::cout << x << " ";
        std::cout << std::endl;
    }

    MATRIX tranposed = QUANG::transpose(database1.records);
    for (auto x : tranposed)
    {
        for (auto y : x)
            std::cout << y << " ";
        std::cout << std::endl;
    }
}
