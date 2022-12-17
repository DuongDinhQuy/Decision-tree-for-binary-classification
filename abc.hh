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
        std::set<std::string> keys;
        feature(std::vector<std::string> &input) : name(input[0])
        {
            for (int i = 1; i < input.size(); i++)
                (this->keys).insert(input[i]);
        }
    };

    class property
    {
    public:
        std::string name;
        std::string record;
        property() {}
        ~property() {}
        property(std::string &record, std::string &name) : record(record), name(name){};
    };

    class sample
    {
    public:
        std::string tag;                  // Cat, Dog
        std::vector<property> properties; // fetch, grumpy, favor food
        sample() {}
        ~sample() {}
        sample(std::vector<std::string> &input, std::vector<std::string> &feature_name /*row[0]*/)
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
    //     dataset(STRING_MATRIX); //
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
        // samples[0].properties[0].record() == "Yes"

        model() {}
        ~model() {}
        STRING_MATRIX data;
        std::vector<sample> root_samples;
        node *root;
        model(STRING_MATRIX &data) : data(data)
        {
            for (int i = 0; i < data.size(); i++)
                (this->root_samples).push_back(sample(data[i], data[0]));
            this->root = new node(root_samples);
        }
        void train_model(){
            for(int i=0;i<;i++){
                for(int j=0;j<;j++){
                    
                }
            }
        }
    };

}
