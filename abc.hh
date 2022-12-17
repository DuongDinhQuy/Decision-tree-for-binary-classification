#pragma once
#include "readfile.hh"
#include <math.h>
#include <set>
#include <iostream>

#define __ENTROPY__ 0.1

uint COUNT_Q = 1;

namespace QUANG
{
    template <class T>
    T max(T a, T b)
    {
        if (a > b)
            return a;
        return b;
    }

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
        std::set<double> threshold;
        std::string name;
        feature(std::string name, std::vector<double> &input /*col*/) : name(name)
        {
            for (int i = 0; i < input.size(); i++)
                (this->threshold).insert(input[i]);
        }
    };

    // class property
    // {
    // public:
    //     std::string name;
    //     double record;
    //     property() {}
    //     ~property() {}
    //     property(double &record, std::string &name) : record(record), name(name){};
    // };

    class sample
    {
    public:
        double tag;                                  // Cat, Dog (0,1)
        std::vector<double /*property*/> properties; // fetch, grumpy, favor food
        std::vector<double> full_info;
        sample() {}
        ~sample() {}
        sample(std::vector<double> &input /*row[i]*/ /*, std::vector<std::string> &feature_name row[0] _ both with output tag*/) : full_info(input)
        {
            for (int i = 0; i < input.size() - 1; i++) // not taking last arg
                this->properties.push_back(input[i] /*property(input[i], feature_name[i])*/);
            this->tag = input[input.size() - 1];
        }
    };

    class node
    {
    public:
        node() {}
        ~node() {}
        node *left;
        node *right;

        std::string identity_feature;
        double identity_record;
        bool is_left = true;

        std::vector<sample> samples;
        double purity; // if full cat or dog then purity = 1 or 0
        double entropy;
        uint size;
        std::vector<feature> features;
        std::vector<std::string> feature_names;

        node(MATRIX records, std::vector<std::string> feature_names) : left(nullptr), right(nullptr), feature_names(feature_names)
        {
            for (auto record : records)
                (this->samples).push_back(sample(record)); // samples initiation

            // features initiation
            records = QUANG::transpose(records);
            for (int i = 0; i < records.size() - 1; i++)
                (this->features).push_back(feature(feature_names[i], records[i]));

            this->size = (this->samples).size();
            uint count = 0;
            for (auto x : samples)
                if (x.tag == (this->samples)[0].tag)
                    count++;

            this->purity = count * 1.0 / size; // what if size == 0 ????

            this->entropy = -this->purity * log2(this->purity) - (1 - this->purity) * log2(1 - this->purity);
        }

        void show()
        {
            if (this->is_left)
                std::cout << COUNT_Q++ << ". " << this->identity_feature << " > " << this->identity_record << std::endl;
            else
                std::cout << COUNT_Q++ << ". " << this->identity_feature << " <= " << this->identity_record << std::endl;

            // std::cout<<this->entropy<<" ";
            if (this->left != nullptr)
                left->show();

            if (this->right != nullptr)
                right->show();
        }

        void train()
        {
            double LEFT_IG = 0, RIGHT_IG = 0, IG = 0;
            for (int j = 0; j < (this->features).size(); j++) // diabetes j : 0 -> 7
            {
                for (auto &key : (this->features)[j].threshold)
                {
                    MATRIX LEFT, RIGHT;
                    for (int i = 0; i < (this->samples).size(); i++) // diabetes i : 0 -> 769
                    {
                        if ((this->samples)[i].properties[j] > key)
                        {
                            LEFT.push_back((this->samples)[i].full_info);
                        }
                        else
                            RIGHT.push_back((this->samples)[i].full_info);
                    }

                    if (this->left == nullptr && this->right == nullptr)
                    {
                        this->left = new node(LEFT, this->feature_names);
                        (this->left)->identity_feature = (this->features)[j].name;
                        (this->left)->identity_record = key;

                        this->right = new node(RIGHT, this->feature_names);
                        (this->right)->identity_feature = (this->features)[j].name;
                        (this->right)->identity_record = key;
                        (this->right)->is_left = false;
                    }

                    LEFT_IG = this->entropy - (this->left)->entropy;
                    RIGHT_IG = this->entropy - (this->right)->entropy;

                    if (max(LEFT_IG, RIGHT_IG) > IG)
                    {
                        this->left = new node(LEFT, this->feature_names);
                        (this->left)->identity_feature = (this->features)[j].name;
                        (this->left)->identity_record = key;

                        this->right = new node(RIGHT, this->feature_names);
                        (this->right)->identity_feature = (this->features)[j].name;
                        (this->right)->identity_record = key;
                        (this->right)->is_left = false;

                        IG = max(LEFT_IG, RIGHT_IG);
                    }
                }
            }
        }
    };

    class model
    {
    public:
        // samples[i].properties[j].record() > features[j].threshold[k]
        // i from 0 -> number rows-1, j from 0 to number cols -2, k from 0 -> number threshold - 1
        model() {}
        ~model() {}
        QUANG::dataset data;
        node *root;
        node *iterator;
        model(QUANG::dataset &data) : data(data)
        {
            this->root = new node(data.records, data.feature_names);
            this->iterator = this->root;
        }

        void train_model(node *current)
        {
            if (current->entropy > __ENTROPY__)
            {
                current->train();
            }
            else
                return;
            train_model(current->left);
            train_model(current->right);
        }
        void show()
        {
            if (this->root != nullptr)
                (this->root)->show();
        }
    };
}