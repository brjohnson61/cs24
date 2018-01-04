#pragma once

#ifndef BAG_H_
//Adam Gulliver & Blake Johnson

#define BAG_H_

#include <string>
#include <vector>

using namespace std;

class Bag
{
public:
	Bag(int max_num_words = 10000);
	virtual ~Bag();
	void insert(const string& word, const string& fileName, int count);
	pair<string, int> lookupFirst(const string& word);
	pair<string, int> lookupRandom(const string& word);
	void lookupAll(const string& word, vector<pair<string, int> >& items);

	// don't change anything before here
private:
	// add your private functions declaration here

private:
	// add your private members here
	pair<pair<string, string>, int> *files;
	int used;
	int capacity;

};

#endif

