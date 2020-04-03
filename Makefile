CC=g++
INCLUDE_DIR := $(PROJECT_ROOT)/include
SRC := $(PROJECT_ROOT)/src
CFLAGS := -shared -std=c++11 -g
LIB_DATA := libdata.so

all : $(LIB_DATA)

$(LIB_DATA) : libdir objdir obj/data_handler.o obj/data.o
	$(CC) $(CFLAGS) -o $(PROJECT_ROOT)/lib/$(LIB_DATA) obj/*.o
	rm -r $(PROJECT_ROOT)/obj

libdir :
	mkdir -p $(PROJECT_ROOT)/lib

objdir :
	mkdir -p $(PROJECT_ROOT)/obj

obj/data_handler.o : $(SRC)/data_handler.cc
	$(CC) -fPIC $(CFLAGS) -o obj/data_handler.o -I$(INCLUDE_DIR) -c $(SRC)/data_handler.cc

obj/data.o : $(SRC)/data.cc
	$(CC) -fPIC $(CFLAGS) -o obj/data.o -I$(INCLUDE_DIR) -c $(SRC)/data.cc

clean:
	rm -r $(PROJECT_ROOT)/lib
	rm -r $(PROJECT_ROOT)/obj 