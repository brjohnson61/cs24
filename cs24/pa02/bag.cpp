#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <random>
#include <string>
#include "bag.h"


Bag::Bag() {
	pairlist list;

}

Bag::~Bag() {
	list.~pairlist();
}

void Bag::insert(const string& word, const string& fileName, int count) {
	list.insertPair(word, fileName, count);
	return;
}

pair<string, int> Bag::lookupFirst(const string& word) {
	return list.findPair(word);
}

pair<string, int> Bag::lookupRandom(const string& word) {
	return list.randoPair(word);
}

void Bag::lookupAll(const string& word, vector<pair<string, int> >& items) {
	list.findAll(word, items);	
	return;

}