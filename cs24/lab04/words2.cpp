//Blake Johnson and Adam Gulliver
// words1.cpp - implements class Words
// (fixed size array version)

#include <string>
#include "words2.h"

using std::string;

namespace lab04_2
{
    Words::Words(unsigned int initial_capacity) {
	capacity = initial_capacity;
	data= new std::string[capacity];
        used = 0;
    }

    Words::Words(const Words &source){
	this-> used=source.used;
	this -> capacity=source.capacity;
	this -> data= new std::string[capacity];
	for(int i=0; i<capacity; i++){
		this -> data[i]=source.data[i];
	}
	}


    Words::~Words() {
	delete [] data;
	}

    
    void Words::append(string word) {
        if(used != capacity){
        	data[used] = word;
        	++used;
	}
	else{
		std::string *data1 = new std::string[used];
		for(int i=0; i<(used); i++){
			data1[i]=data[i];
		}
		delete [] data;
		capacity=capacity*2;
		data= new std::string[capacity];
		for(int i=0; i< capacity/2 ; i++){
			data[i]=data1[i];
		}
		delete [] data1;

		data[used]=word;
		++used;
				
    }

    }
    
    string& Words::operator[](unsigned int index) {
        if(index < used){
        return data[index];
	}
    }
    
    unsigned int Words::size() const {
        return used;
    }

    void Words::operator =(const Words &source){
	if(this==&source){
		return;
	}
	else if(this-> capacity != source.capacity){
		this -> capacity = source.capacity;
		delete [] data;
		this -> data =new std::string[capacity];
	}
	for(int i=0; i<capacity; i++){
		this -> data[i]= source.data[i];
	}
	this -> used =source.used;
	return;
    }

    
    unsigned int Words::get_capacity() const {
        return capacity;
    }
    
    string Words::operator[] (unsigned int index) const {
        if(index < used){
        	return data[index];
	}
    }
    
}
