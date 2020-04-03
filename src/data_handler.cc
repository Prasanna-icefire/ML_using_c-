#include "../include/data.hpp"
#include "../include/data_handler.hpp"
data_handler::data_handler()//constructor
{
    data_array = new std::vector<data *>;
    test_data = new std::vector<data *>;
    training_data = new std::vector<data *>;
    validation_data = new std::vector<data *>;  
}
data_handler::~data_handler()
{
     //free
}
  
void data_handler::read_feature_vector(std::string path)//this function read data file
{
    uint32_t header[4];//MAGIC|NUM IMAGES|ROWSIZE|COLSIZE
    unsigned char bytes[4];
    FILE *f=fopen(path.c_str(),"r");
    if(f)
    {
        for(int i=0;i<4;i++)//header contains 4 items thats y 4
        {
            if(fread(bytes,sizeof(bytes),1,f))
            {
                header[i]=convert_to_little_endian(bytes);
            }
        }
      printf("Done getting file header.\n");
      int image_size =  header[2]*header[3];
      for(int i=0;i<header[1];i++)
      {
          data *d = new data();
          uint8_t element[1];
          for(int j=0;j<image_size;j++)
          {
              if(fread(element,sizeof(element),1,f))
              {
                  d->append_to_feature_vector(element[0]);
              }
              else
              {
                  printf("Error reading from file.\n");
                  exit(1);
              }
              
          }
          data_array->push_back(d);
      }
      printf("Successfully read and stored %lu feature vectors\n",data_array->size());
    }
    else
    {
        printf("Could not find find file.\n");
        exit(1);
    }
    
}
void data_handler::read_feature_labels(std::string path)
{
    uint32_t header[2];//MAGIC|NUM IMAGES
    unsigned char bytes[4];
    FILE *f=fopen(path.c_str(),"r");
    if(f)
    {
        for(int i=0;i<2;i++)
        {
            if(fread(bytes,sizeof(bytes),1,f))
            {
                header[i]=convert_to_little_endian(bytes);
            }
        }
      printf("Done getting label file header.\n");
      for(int i=0;i<header[1];i++)
      {
          uint8_t element[1];
              if(fread(element,sizeof(element),1,f))
              {
                  data_array->at(i)->set_label(element[0]);
              }
              else
              {
                  printf("Error reading from file.\n");
                  exit(1);
              }                    
      }
      printf("Successfully read and stored %lu labels.\n",data_array->size());
    }
    else
    {
        printf("Could not find find file.\n");
        exit(1);
    }    

}
void data_handler::split_data()
{
    std::unordered_set<int> used_indexes;
    int train_size = data_array->size() * TRAIN_SET_PERCENT;
    int test_size = data_array->size() * TEST_SET_PERCENT;
    int validate_size = data_array->size() * VALIDATION_PERCENT;

    //Training Data

    int Count = 0;
    while(Count < train_size)
    {
        int rand_index = rand() % data_array->size();//generates a random number from 0 to arraysize -1
        if(used_indexes.find(rand_index) == used_indexes.end())//the iterator has reached the end and did not find the value
        {
          training_data->push_back(data_array->at(rand_index));
          used_indexes.insert(rand_index);
          Count++;
        }

    }

    //Test data

        Count = 0;
    while(Count < test_size)
    {
        int rand_index = rand() % data_array->size();//generates a random number from 0 to arraysize -1
        if(used_indexes.find(rand_index) == used_indexes.end())//the iterator has reached the end and did not find the value
        {
          test_data->push_back(data_array->at(rand_index));
          used_indexes.insert(rand_index);
          Count++;
        }

    }

    //Validation data

        Count = 0;
    while(Count < validate_size)
    {
        int rand_index = rand() % data_array->size();//generates a random number from 0 to arraysize -1
        if(used_indexes.find(rand_index) == used_indexes.end())//the iterator has reached the end and did not find the value
        {
          validation_data->push_back(data_array->at(rand_index));
          used_indexes.insert(rand_index);
          Count++;
        }

    }
    printf("Training data size %lu.\n ",training_data->size());
    printf("Test data size %lu.\n ",test_data->size());
    printf("Validation data size %lu.\n ",validation_data->size());

}
void data_handler::count_classes()
{
    int Count=0;
    for(unsigned i=0;i<data_array->size();i++)
    {
      if(class_map.find(data_array->at(i)->get_label()) == class_map.end())  
      {
          class_map[data_array->at(i)->get_label()]=Count;
          data_array->at(i)->set_enumerated_label(Count);
          Count++;
      }
    }
    num_classes=Count;
    printf("Successfully %d unique classes.\n",num_classes);

}
uint32_t data_handler::convert_to_little_endian(const unsigned char * bytes)
{
  return (uint32_t)((bytes[0]<<24)|(bytes[1]<<16)|(bytes[2]<<8)|(bytes[3]));
}
std::vector<data *> * data_handler::get_training_data()
{
    return training_data;
}
std::vector<data *> * data_handler::get_test_data()
{
    return test_data;
}
std::vector<data *> * data_handler::get_validation_data()
{
    return validation_data;
}
/*
int main()
{
    data_handler *dh = new data_handler();
    dh->read_feature_vector("train-images-idx3-ubyte");
    dh->read_feature_labels("train-labels-idx1-ubyte");
    dh->split_data();
    dh->count_classes();   
}*/