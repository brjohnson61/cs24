#include <string>
#include <vector>
#include <array>
#include <stdio.h>
#include <utility>
#include <random>
#include <ctime>
#include <ctype.h>
#include <cstdlib>
//Adam Gulliver & Blake Johnson

#include <iostream>
#include <fstream>
#include <sstream>

#include "bag.h"

using namespace std;

string lower(string word) {
	string u = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", l = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < word.length(); i++) {
		for (int j = 0; j < 26; j++) {
			if (word[i] == u[j]) {
				word[i] = l[j];
			}
		}
	}
	return word;
}

Bag::Bag(int max_num_words) {
	capacity = max_num_words;
	used = 0;
	files = new pair<pair<string, string>, int>[capacity];
	//	srand(time(0)); ??
}

Bag::~Bag() {
	delete[] files;
}

void Bag::insert(const string& word, const string& fileName, int count) {
	string myword = lower(word);
	bool a = false;
	for (int i = 0; i < used; i++) {
		if (((files[i].first).first == fileName) && ((files[i].first).second == myword)) {
			files[i].second = files[i].second + count;
			a = true;
		}
	}

	if (a == false) {
		pair<pair<string, string>, int> tuple;
		(tuple.first).first = fileName;
		(tuple.first).second = myword;
		tuple.second = count;
		files[used] = tuple;
		used++;
	}
	return;
}

pair<string, int> Bag::lookupFirst(const string& word) {
	string myword = lower(word);
	pair<string, int> a;
	a.first = "";
	a.second = 0;

	for (int x = 0; x <= used; x++) {
		if ((files[x].first).second == myword) {
			a.first = (files[x].first).first;
			a.second = files[x].second;
			break;
		}

	}
	return a;
}

pair<string, int> Bag::lookupRandom(const string& word) {
	
	/*string myword = lower(word);
	vector <string> v;
	pair<string, int> p;
	for (int i = 0; i < used; i++) {
		if (((files[i].first).second).compare(myword)==0) {
			v.push_back((files[i].first).first);
		}

	}
	if (v.size() == 0) {
		p.first = "";
		p.second = 0;
		return p;
	}

	default_random_engine generator;
	uniform_int_distribution<int> distribution(0, (v.size()-1));

	int index = distribution(generator);

	distribution.reset();

	for (int i = 0; i < used; i++) {
		if ((v[index] == (files[i].first).first) && ((files[i].first).second == myword)) {
			p.second = (files[i].second);
		}

	}
	p.first = v[index];
	return p;*/

	string myword = lower(word);
	int acc = 0;
	pair<string, int> *pairs= new pair<string, int>[10000];
	for (int i = 0; i < used; i++) {
		if (((files[i].first).second).compare(myword)==0) {
			pairs[acc].first = (files[i].first).first;
			pairs[acc].second = (files[i].second);
			acc++;
		}
	}

	if (acc == 0) {
		pair<string, int> p;
		p.first = "";
		p.second = 0;
		return p;
	}

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, acc);
	
	int index = dis(gen);
	
	return pairs[index];
}

void Bag::lookupAll(const string& word, vector<pair<string, int> >& items) {
	pair<string, int> a;
	string myword = lower(word);

	for (int x = 0; x <= used; x++) {
		if ((files[x].first).second == myword) {
			a.first = (files[x].first).first;
			a.second = files[x].second;
			items.push_back(a);
		}

	}
	return;

}


