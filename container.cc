#include "container.hh"

/***********************************Class_dataset***********************************/
// use to contain datasheet

F4HUSTER::dataset::dataset() {}
F4HUSTER::dataset::~dataset() {}
F4HUSTER::dataset::dataset(std::ifstream *datafile)
{
    std::string line;
    getline(*datafile, line);
    this->feature_names = remove_comma(&line[0]);
    while (getline(*datafile, line))
        (this->records).push_back(STR_TO_DOUBLE(remove_comma(&line[0])));
}

/***********************************Class_feature***********************************/
// use to contain a dataset's single-featured data and the feature's name

F4HUSTER::feature::feature() {}
F4HUSTER::feature::~feature() {}
F4HUSTER::feature::feature(std::string name, std::vector<double> &input /*col*/) : name(name)
{
    for (int i = 0; i < input.size(); i++)
        (this->threshold).insert(input[i]);
}

/***********************************Class_sample***********************************/
// use to contain data of one example/sample

F4HUSTER::sample::sample() {}
F4HUSTER::sample::~sample() {}
F4HUSTER::sample::sample(std::vector<double> &input) : full_info(input)
{
    for (int i = 0; i < input.size() - 1; i++) // not taking last arg
        this->properties.push_back(input[i] /*property(input[i], feature_name[i])*/);
    this->tag = input[input.size() - 1];
}