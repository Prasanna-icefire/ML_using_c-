//this container will holde each line item,the feature vector,the label,the enumerated value
#ifndef __DATA_H
#define __DATA_H
#include<vector>
#include"stdio.h"
#include"stdint.h"

class data
{
    std::vector<uint8_t> * feature_vector;//uint8 data type contrains whole numbers from 0 to 255. 
    uint8_t label;//actual class,like class names can be A,B,C,D.........
    int enum_label;//this stores up labels for classes,like A -> 1,B->2 and so on........
    double distance;

    public:
    data();
    ~data();
    void set_feature_vector(std::vector<uint8_t> *);
    void append_to_feature_vector(uint8_t);
    void set_label(uint8_t);
    void set_enumerated_label(int);
    int get_feature_vector_size();
    void set_distance(double val);

    uint8_t get_label();
    uint8_t get_enumerated_label();

    std::vector<uint8_t> * get_feature_vector();
    double get_distance();
};
#endif