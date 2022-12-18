
#include "abc.hh"

int main(int argc, char *argv[])
{
    std::ifstream trainfile(argv[1]);
    std::ifstream validationfile(argv[2]);
    // std::ifstream testfile(argv[3]);

    QUANG::dataset trainset(&trainfile);
    QUANG::dataset validationset(&validationfile);
    // QUANG::dataset testset(&testfile);

    // train model
    QUANG::model diabetes(trainset);
    diabetes.train_model(diabetes.root);

    // diabetes.show();

    std::vector<double>
        predicts;
    for (auto test : validationset.records)
        predicts.push_back(diabetes.predict(test, diabetes.root));

    // for (auto x : predicts)
    //     std::cout << x << std::endl;


    MATRIX val = QUANG::transpose(validationset.records);
    std::vector<double> outcomes = val[val.size()-1];
    uint count = 0;
    for(int i=0;i<predicts.size();i++){
        if(predicts[i] == outcomes[i]) count++;
    }
    std::cout<<count<<"/"<<predicts.size()<<std::endl;
}