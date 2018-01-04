// Adam Gulliver and Blake Johnson

#include <boost/algorithm/string.hpp>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstdlib>
#include "bag.h"
#include <random>

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

Bag::Bag() {
  head_ptr = NULL;
}

Bag::~Bag() {
  while(head_ptr != NULL) {
    newWordNode* temp = head_ptr;
    head_ptr = head_ptr -> nextw();
    newFileNode* head2 = temp -> listpointer();
    while(head2 != NULL) {
      newFileNode* temp2 = head2;
      head2 = head2 -> getlink();
      delete temp2;
      
    }
    delete head2;
    delete temp;
  }
  delete head_ptr;
}

void Bag::insert(const string& word, const string& fileName, int count) {
 
  newFileNode* newFile = new newFileNode;
  newFile -> value(fileName, count);

  newWordNode* newWord = new newWordNode(word);
  newWord-> insert(newFile);

  int acc = 0;

  if(head_ptr == NULL) {
    head_ptr = newWord;
  }
  else {
    newWordNode* temp = head_ptr;
    while(temp != NULL) {
      if(boost::iequals(temp -> Word(), word)) {
	temp -> insert(newFile);
	acc++;
      }
      temp = temp -> nextw();
    }
    if(acc == 0) {
      temp = head_ptr;
	  while (temp->nextw() != NULL) {
		  temp = temp->nextw();
	  }
      temp -> setN(newWord);
    }
    
  }
}

pair<string,int> Bag::lookupFirst(const string& word) {

  pair<string,int> p;
  p.first = "";
  p.second = 0;
  
  newWordNode* temp = head_ptr;
  
  while(temp != NULL) {
    if(boost::iequals(temp -> Word(), word)) {
      newFileNode* top = temp -> listpointer();
	  pair<string, int> d; (top->file(), top->num());
	  d.first = top->file();
	  d.second = top->num();
      return d;
    }
    temp = temp -> nextw();
  }

  return p;
}

pair<string,int> Bag::lookupRandom(const string& word) {
	pair<string, int> p;
	p.first = "";
	p.second = 0;
	vector<pair<string, int> > v;
  
	newWordNode* temp = head_ptr;
	while(temp != NULL) {
		if(boost::iequals(temp->Word(), word)) {
				newFileNode* temp2 = temp -> listpointer();
				while (temp2 != NULL) {
					pair<string, int> value(temp2->file(), temp2->num());
					v.push_back(value);
					temp2 = temp2->getlink();
				}
		}
    temp = temp -> nextw();
  }

  if(v.size() == 0) {
	  return p;
  }
  else {
	  //default_random_engine generator;
	 // uniform_int_distribution<int> distribution(0, (v.size() - 1));

	  //int index = distribution(generator);
	 // distribution.reset();

	  //return v[index];
	  int index = rand() % v.size();
	  return v[index];
  }
  
}

void Bag::lookupAll(const string& word, vector<pair<string,int> >& items) {

  newWordNode* temp = head_ptr;
  while(temp != NULL) {
    if(boost::iequals(temp->Word(), word)) {
      newFileNode* temp2 = temp -> listpointer();
      while(temp2 != NULL){
	pair<string,int> value (temp2 -> file(), temp2 -> num());
	items.push_back(value);
	temp2 = temp2 -> getlink();
      }
    }
    temp = temp -> nextw();
  }
}

void Bag::lookupAllOR(const vector<string>& wordvec, vector<string>& filesvec){
	for (int i = 0; i < wordvec.size(); i++) {
		newWordNode* temp = head_ptr;
		while (temp != NULL) {
			if (boost::iequals(temp->Word(), wordvec[i])) {
				newFileNode* temp2 = temp->listpointer();
				while (temp2 != NULL) {
					if (find(filesvec.begin(), filesvec.end(), temp2->file()) != filesvec.end()) {
						continue;
					}
					else {
						filesvec.push_back(temp2->file());
					}

					temp2 = temp2->getlink();
				}
			}
			temp = temp->nextw();
		}
	}
}

void Bag::lookupAllAND(const vector<string>& wordvec, vector<string>& filesvec) {
  vector<pair<string,int>> v;
  newWordNode* temp = head_ptr;
  while(temp != NULL) {
    if(boost::iequals(temp -> Word(), wordvec[0])) {
		newFileNode* temp2 = temp -> listpointer();
		while(temp2 != NULL) {
			pair<string, int> value;
			value.first = temp2->file();
			value.second = 1;
			v.push_back(value);
			temp2 = temp2 -> getlink();
      }
    }
    temp = temp -> nextw();
  }
  
  for(int i=1; i < wordvec.size(); i++) {
    newWordNode* temp = head_ptr;
    while(temp != NULL) {
      if(boost::iequals(temp -> Word(), wordvec[i])) {
	newFileNode* temp2 = temp -> listpointer();
	while(temp2 != NULL) {
	  for(int j=0; j < v.size(); j++) {
	    if(temp2 -> file() == lower(v[j].first))
	      v[j].second++;
	    
	  }
	  temp2 = temp2 -> getlink();
	}
	
      }
      temp = temp -> nextw();
    }
  }
  for(int i=0; i < v.size(); i++) {
    if(v[i].second == wordvec.size()) {
      filesvec.push_back(v[i].first);
      
    }
  }
}
