CC=g++
SRC := $(PWD)/src
CFLAGS := -std=c++11 -DEUCLID
INCLUDE_DIR := $(PWD)/include/*

all: main

main : $(SRC)/knn.cc
	$(CC) $(CFLAGS) $(SRC)/knn.cc -o main -L$(PROJECT_ROOT)/lib/ -I$(INCLUDE_DIR) \
	-I$(PROJECT_ROOT)/include -ldata

clean:
	rm main