#include "decisiontree.hh"
#include "fileIO.hh"
#include "container.hh"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        Pig4::_throw(argv[0], 3);
    }
    else
    {
        std::ifstream trainfile(argv[1]);
        std::ifstream validationfile(argv[2]);
        // std::ifstream testfile(argv[3]);

        Pig4::dataset trainset(&trainfile);
        Pig4::dataset validationset(&validationfile);
        // Pig4::dataset testset(&testfile);

        // train model
        Pig4::model diabetes(trainset);
        diabetes.train_model(diabetes.root);

        // diabetes.show();

        std::vector<double>
            predicts;
        for (auto test : validationset.records)
            predicts.push_back(diabetes.predict(test, diabetes.root));

        /******write results******/
        std::ofstream result("Diabetes/result.txt");
        int id = 1;
        for (auto x : predicts)
            result << "Id " << id++ << ". " << x << std::endl;

        // for (auto x : predicts)
        //     std::cout << x << std::endl;

        /******evaluate result******/
        // accuracy

        MATRIX val = Pig4::transpose(validationset.records);
        std::vector<double> outcomes = val[val.size() - 1];
        unsigned int count = 0;
        for (int i = 0; i < predicts.size(); i++)
        {
            if (predicts[i] == outcomes[i])
                count++;
        }
        double accuracy = count * 1.0 / predicts.size();
        std::cout << "Accuracy: " << accuracy << std::endl;

        // precision
        
    }
}