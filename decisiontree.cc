#include "decisiontree.hh"

template <class T>
T Pig4::max(T a, T b)
{
    if (a > b)
        return a;
    return b;
}
double Pig4::log2(double p)
{
    if (!p)
        return 0;
    return std::log(p) / std::log(2);
}

/***********************************Class_node***********************************/
// node of the tree

Pig4::node::node() {}
Pig4::node::~node() {}
Pig4::node::node(MATRIX records, std::vector<std::string> feature_names, std::string pre_index, bool is_left) : is_left(is_left), left(nullptr), right(nullptr), feature_names(feature_names)
{

    if (this->is_left)
        this->index = pre_index + "1";
    else
        this->index = pre_index + "0";

    for (auto record : records)
        (this->samples).push_back(sample(record)); // samples initiation

    // features initiation
    records = Pig4::transpose(records);
    for (int i = 0; i < records.size() - 1; i++)
        (this->features).push_back(feature(feature_names[i], records[i]));

    this->size = (this->samples).size();
    double count = 0;
    for (auto x : samples)
        if (x.tag == 1 /*(this->samples)[0].tag*/)
            count++;

    this->purity = count * 1.0 / size; // what if size == 0 ????

    this->entropy = -this->purity * log2(this->purity) - (1 - this->purity) * log2(1 - this->purity);
}
double Pig4::node::get_the_most()
{
    if (this->purity > 0.5)
        return 1;
    return 0;
}

void Pig4::node::show()
{
    if (this->left != nullptr)
        left->show();

    std::cout << this->index;
    if (this->is_left)
        std::cout << ". " << this->identity_feature << " > " << this->identity_record << std::endl;
    else
        std::cout << ". " << this->identity_feature << " <= " << this->identity_record << std::endl;

    // std::cout<<this->entropy<<" ";

    if (this->right != nullptr)
        right->show();
}

void Pig4::node::train()
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
            if (RIGHT.size() != 0 && LEFT.size() != 0)
            {
                if (this->left == nullptr && this->right == nullptr)
                {
                    this->left = new node(LEFT, this->feature_names, this->index, true);
                    (this->left)->identity_feature = (this->features)[j].name;
                    (this->left)->identity_record = key;

                    this->right = new node(RIGHT, this->feature_names, this->index, false);
                    (this->right)->identity_feature = (this->features)[j].name;
                    (this->right)->identity_record = key;
                    (this->right)->is_left = false;
                }

                LEFT_IG = this->entropy - (this->left)->entropy;
                RIGHT_IG = this->entropy - (this->right)->entropy;

                if (max(LEFT_IG, RIGHT_IG) > IG)
                {
                    this->left = new node(LEFT, this->feature_names, this->index, true);
                    (this->left)->identity_feature = (this->features)[j].name;
                    (this->left)->identity_record = key;

                    this->right = new node(RIGHT, this->feature_names, this->index, false);
                    (this->right)->identity_feature = (this->features)[j].name;
                    (this->right)->identity_record = key;
                    (this->right)->is_left = false;

                    IG = max(LEFT_IG, RIGHT_IG);
                }
            }
        }
    }
}

/***********************************Class_model***********************************/
// the decision tree

Pig4::model::model() {}
Pig4::model::~model() {}
Pig4::model::model(Pig4::dataset &data) : data(data)
{
    std::string root_index = "";
    this->root = new node(data.records, data.feature_names, root_index, true);
}

void Pig4::model::train_model(node *current)
{
    if (current->entropy > __ENTROPY__)
        current->train();
    else
        return;
    train_model(current->left);
    train_model(current->right);
}
void Pig4::model::show()
{
    if (this->root != nullptr)
        (this->root)->show();
}

double Pig4::model::predict(std::vector<double> &test, node *current)
{
    if (current->left != nullptr && current->right != nullptr)
    {
        unsigned int i = 0;
        for (; i < (this->data).feature_names.size(); i++)
            if ((this->data).feature_names[i] == current->left->identity_feature)
                break;

        if (test[i] > current->left->identity_record)
            predict(test, current->left);
        else
            predict(test, current->right);
    }
    else
        return current->get_the_most();
}
