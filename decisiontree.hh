#pragma once
#include "fileIO.hh"
#include "container.hh"
#include <math.h>
#include <iostream>

#define __ENTROPY__ 0.1

namespace F4HUSTER
{
    // return max of a and b
    template <class T>
    T max(T a, T b);

    // return the base-2 logarit of p
    double log2(double p);

    /***********************************Class_node***********************************/
    // node of the tree
    class node
    {
    public:
        node();
        ~node();
        node *left;
        node *right;
        std::string index;

        std::string identity_feature;
        double identity_record;
        bool is_left = true;

        std::vector<sample> samples;
        double purity; // if full of 1 then purity = 1
        double entropy;
        double size;
        std::vector<feature> features;
        std::vector<std::string> feature_names;

        node(MATRIX records, std::vector<std::string> feature_names, std::string pre_index, bool is_left);
        double get_the_most();
        void show();
        void train();
    };

    /***********************************Class_model***********************************/
    // the decision tree
    class model
    {
    public:
        model();
        ~model();
        F4HUSTER::dataset data;
        node *root;
        model(F4HUSTER::dataset &data);
        void train_model(node *current);
        void show();
        double predict(std::vector<double> &test, node *current);
    };

}