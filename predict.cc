#include "decisiontree.hh"
#include "fileIO.hh"
#include "container.hh"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2){
        Pig4::_throw(argv[0], 2);
    }
    else
    {
        std::ifstream trainfile(argv[1]);

        Pig4::dataset trainset(&trainfile);

        // train model
        Pig4::model diabetes(trainset);
        diabetes.train_model(diabetes.root);
        
        std::vector<double> input;
        double x;
        for (int i = 0; i < trainset.feature_names.size() - 1; i++)
        {
            std::cout << trainset.feature_names[i] << " (eg. " << trainset.records[0][i] << "): ";
            std::cin >> x;
            input.push_back(x);
        }
        if (diabetes.predict(input, diabetes.root))
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
    }
}