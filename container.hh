#pragma once
#include "readfile.hh"
#include <set>

namespace QUANG
{
    /***********************************Class_dataset***********************************/
    // use to contain datasheet
    class dataset
    {
    public:
        dataset();
        ~dataset();
        std::vector<std::string> feature_names;
        MATRIX records;
        dataset(std::ifstream *datafile);
    };
    /***********************************Class_feature***********************************/
    // use to contain a dataset's single-featured data and the feature's name
    class feature
    {
    public:
        feature();
        ~feature();
        std::set<double> threshold;
        std::string name;
        feature(std::string name, std::vector<double> &input);
    };
    /***********************************Class_sample***********************************/
    // use to contain data of one example/sample
    class sample
    {
    public:
        double tag;                     // Cat, Dog (0,1)
        std::vector<double> properties; // fetch, grumpy, favor food
        std::vector<double> full_info;
        sample();
        ~sample();
        sample(std::vector<double> &input);
    };
}