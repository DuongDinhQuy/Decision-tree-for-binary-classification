#pragma once
#include "readfile.hh"
#include <math.h>
#include <set>

namespace QUANG
{
    double log2(double p)
    {
        if (!p)
            return 0;
        return std::log(p) / std::log(2);
    }

    class feature
    {
    public:
        feature() {}
        ~feature() {}
        std::string name;
        std::set<double> threshold;
        feature(std::string name, std::vector<double> &input /*col*/) : name(name)
        {
            for (int i = 0; i < input.size(); i++)
                (this->threshold).insert(input[i]);
        }
    };

    class property
    {
    public:
        std::string name;
        double record;
        property() {}
        ~property() {}
        property(double &record, std::string &name) : record(record), name(name){};
    };

    class sample
    {
    public:
        double tag;                       // Cat, Dog (0,1)
        std::vector<property> properties; // fetch, grumpy, favor food
        sample() {}
        ~sample() {}
        sample(std::vector<double> &input, std::vector<std::string> &feature_name /*row[0]*/)
        {
            for (int i = 0; i < input.size() - 1; i++)
                this->properties.push_back(property(input[i], feature_name[i]));
            this->tag = input[input.size() - 1];
        }
    };

    // class dataset
    // {
    // public:
    //     std::vector<sample> samples; // rows

    //     dataset();
    //     ~dataset();
    //     dataset(QUANG::dataset); //
    // };

    class node
    {
    public:
        node() {}
        ~node() {}
        node *left;
        node *right;

        std::vector<sample> samples;
        double purity; // if full cat or dog then purity = 1 or 0
        double entropy;
        uint size;

        node(std::vector<sample> &samples) : samples(samples), size(samples.size())
        {
            uint count = 0;
            for (auto x : samples)
                if (x.tag == (this->samples)[0].tag)
                    count++;
            this->purity = count * 1.0 / size;

            this->entropy = -this->purity * log2(this->purity) - (1 - this->purity) * log2(1 - this->purity);
        }
    };

    class model
    {
        // samples[i].properties[j].record() > features[j].threshold[k]
        // i from 0 -> number rows-1, j from 0 to number cols -2, k from 0 -> number threshold - 1
        model() {}
        ~model() {}
        QUANG::dataset data;
        std::vector<sample> root_samples;
        node *root;
        model(QUANG::dataset &data) : data(data)
        {
            for (int i = 0; i < data.records.size(); i++)
                (this->root_samples).push_back(sample(data.records[i], data.feature_names));
            this->root = new node(root_samples);
        }

        void train_model()
        {
            for (int i = 0; i < (this->data).records.size(); i++) // diabetes i : 0 -> 769
            {
                for (int j = 0; j < (this->data).feature_names.size() - 1; j++) // diabetes j : 0 -> 7
                {
                    for(int k = 0; k<)
                }
            }
        }
    };

}
