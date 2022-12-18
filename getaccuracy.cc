#include "decisiontree.hh"
#include "fileIO.hh"
#include "container.hh"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    if(argc != 3){
        F4HUSTER::_throw(argv[0], 3);
    }
    else{
    std::ifstream trainfile(argv[1]);
    std::ifstream validationfile(argv[2]);
    // std::ifstream testfile(argv[3]);

    F4HUSTER::dataset trainset(&trainfile);
    F4HUSTER::dataset validationset(&validationfile);
    // F4HUSTER::dataset testset(&testfile);

    // train model
    F4HUSTER::model diabetes(trainset);
    diabetes.train_model(diabetes.root);

    // diabetes.show();

    std::vector<double>
        predicts;
    for (auto test : validationset.records)
        predicts.push_back(diabetes.predict(test, diabetes.root));

    // for (auto x : predicts)
    //     std::cout << x << std::endl;

    MATRIX val = F4HUSTER::transpose(validationset.records);
    std::vector<double> outcomes = val[val.size() - 1];
    unsigned int count = 0;
    for (int i = 0; i < predicts.size(); i++)
    {
        if (predicts[i] == outcomes[i])
            count++;
    }

    double accuracy = count * 1.0 / predicts.size();
    std::cout << "Accuracy: " << accuracy << std::endl;
}
}