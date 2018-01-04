#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <cstdlib>
#include <random>
#include "sll.h"

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

pairlist::pairlist(){
	first = NULL;
}

pairlist::~pairlist() {
	Node* garbage;
	while (first != NULL) {
		garbage = first;
		first = first->next;
		delete garbage;
	}
	delete first;
}

void pairlist::insertPair(const string& word, const string& fileName, int count){
	Node* tempNode = first;
	Node* myNode = new Node;
	myNode->data.first.first = fileName;
	myNode->data.first.second = lower(word);
	myNode->data.second = count;
	myNode->next = NULL;
	bool b = true;
	if (first == NULL) {
		first = myNode;
	}
	else {
		while (tempNode->next != NULL) {
			tempNode = tempNode->next;
			if (((tempNode->data.first.second).compare(lower(word)) == 0) && ((tempNode->data.first.second).compare(fileName) == 0)) {
				tempNode->data.second++;
				b = false;
			}
		}
		if (b) {
			tempNode->next = myNode;
		}
	}
	return;
}

pair<string, int> pairlist::findPair(const string& word) {
	Node* temp = first;
	pair<string, int> p ("", 0);
	while (temp != NULL) {
		if ((temp->data.first.second).compare(lower(word))==0) {
			p.first = temp->data.first.first;
			p.second = temp->data.second;
			return p;
		}
		temp = temp->next;
	}
	
	return p;
}

pair<string, int> pairlist::randoPair(const string& word) {
	Node* temp = first;
	pair<string, int> p;
	string myword = lower(word);
	int acc = 0;
	pair<string, int> *pairs = new pair<string, int>[10000];
	while(temp!= NULL) {
		if ((temp->data.first.second).compare(myword) == 0) {
			pairs[acc].first = temp->data.first.first;
			pairs[acc].second = temp->data.second;
			acc++;
		}
		temp = temp->next;
	}

	if (acc == 0) {
		pair<string, int> p;
		p.first = "";
		p.second = 0;
		return p;
	}

	/*random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, acc);

	int index = dis(gen);*/
	int index = rand() % acc;

	return pairs[index];
}
	/*while (temp != NULL) {
		if ((temp->data.first.second).compare(lower(word))==0) {
			acc = acc + 1;
			p.first = temp->data.first.first;
			p.second = temp->data.second;
			v.push_back(p);
		}
		temp = temp->next;
	}

	if (v.size() == 0) {
		p.first = "";
		p.second = 0;
		return p;
	}

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, v.size());

	int index = dis(gen);

	return v[index];
}*/

void pairlist::findAll(const string& word, vector<pair<string, int>>& items) {
	Node* temp = first;
	pair<string, int> p;
	while (temp != NULL) {
		if ((temp->data.first.second).compare(lower(word))==0) {
			p.first = temp->data.first.first;
			p.second = temp->data.second;
			items.push_back(p);
		}
		temp = temp->next;
	}
	return;
}