//this is going to implement the logic to count the classes,read the classes process the classes and so on
#ifndef __DATA_HANDLER_H
#define __DATA_HANDLER_H
#include<fstream>//to read from files
#include"stdint.h"//for the uint8 datatype
#include"data.hpp"
#include<vector>//for dynamic array
#include<string>
#include<map>//to map a class label to enumerated value
#include<unordered_set>//to keep a track of indexes when data is split into training data and testing data and such

class data_handler
{
  std::vector<data *> * data_array;//All of the data pre-split
  std::vector<data *> * training_data;
  std::vector<data *> * test_data;
  std::vector<data *> * validation_data;

  int num_classes;//counts the number of classes
  int feature_vector_size;
  std::map<uint8_t,int> class_map;

  const double TRAIN_SET_PERCENT=0.75;
  const double TEST_SET_PERCENT=0.20;
  const double VALIDATION_PERCENT=0.05;

  public:
  data_handler();
  ~data_handler();
  
 void read_feature_vector(std::string path);//these 2 functions read data file and label file separately
 void read_feature_labels(std::string path);
 void split_data();
 void count_classes();

 uint32_t convert_to_little_endian(const unsigned char * bytes);
 std::vector<data *> * get_training_data();
 std::vector<data *> * get_test_data();
 std::vector<data *> * get_validation_data();
};
#endif