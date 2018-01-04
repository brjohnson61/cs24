//Adam Gulliver and Blake Johnson


#ifndef LOL_H_
#define LOL_H_
#include <utility>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <boost/algorithm/string.hpp>

using namespace std;

class newFileNode {
 public:
  newFileNode(const pair<string,int>& mydata = pair<string,int>(), newFileNode* mylink = NULL);
  void value(const string& word, const int& count);
  void set(newFileNode* mylink);
  string file() const;
  int num() const;
  newFileNode* getlink();
 private:
  pair<string,int> info;
  newFileNode* next;
};

class newWordNode {
 public:
  newWordNode(const string& mydata = string(), newFileNode* head_list1 = NULL, newWordNode* next_word = NULL);
  void setW(const string& myword);
  void setN(newWordNode* mylink);
  void insert(newFileNode* mylink);
  string Word() const;
  newWordNode* nextw();
  newFileNode* listpointer();
 private:
  string wordName;
  newWordNode* nextNode;
  newFileNode* head_list;
  
};

#endif
