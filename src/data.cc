//getting and setting values
#include "../include/data.hpp"
data::data()
{
feature_vector=new std::vector<uint8_t>;
}
data::~data()
{

}
 void data::set_feature_vector(std::vector<uint8_t> *vect)
 {
    feature_vector=vect;  
 }
 void data::append_to_feature_vector(uint8_t val)
 {
     feature_vector->push_back(val);//push_back is a function of vectors to append the given vector
 }
 void data::set_label(uint8_t val)
 {
     label=val;
 }
 void data::set_enumerated_label(int val)
 {
     enum_label=val;
 }
 void data::set_distance(double val)
 {
     distance = val;
 }

 int data::get_feature_vector_size()
 {
     return feature_vector->size();
 }
 uint8_t data::get_label()
 {
     return label;
 }
 uint8_t data::get_enumerated_label()
 {
     return enum_label;
 }
 std::vector<uint8_t> * data::get_feature_vector()
 {
     return feature_vector;
 } 
 double data::get_distance()
 {
     return distance;
 }