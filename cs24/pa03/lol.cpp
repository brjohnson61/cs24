//Adam Gulliver and Blake Johnson

#include "lol.h"
#include <string>
#include <utility>
#include <algorithm>
#include <boost/algorithm/string.hpp>

newFileNode::newFileNode(const pair<string,int>& mydata, newFileNode* mylink) {
  info.first = mydata.first;
  info.second = mydata.second;
  next = mylink;
}

void newFileNode::value(const string& word, const int& count) {
  info.first = word;
  info.second = count;
}

void newFileNode::set(newFileNode* mylink) {
  next = mylink;
}

string newFileNode::file() const {
  return info.first;
}

int newFileNode::num() const {
  return info.second;
}

newFileNode* newFileNode::getlink() {
  return next;
}

newWordNode::newWordNode(const string& mydata, newFileNode* head_list1, newWordNode* next_word) {
  wordName = mydata;
  head_list = head_list1;
  nextNode = next_word;
}

void newWordNode::setW(const string& myword) {
  wordName = myword;
}

void newWordNode::setN(newWordNode* myLink) {
  nextNode = myLink;
}

void newWordNode::insert(newFileNode* myLink) {
  if(head_list == NULL)
    head_list = myLink;
  else {
    newFileNode* temp = head_list;
    while(temp -> getlink() != NULL)
      temp = temp -> getlink();
    temp -> set(myLink);
  }
}

string newWordNode::Word() const {
  return wordName;
}

newWordNode* newWordNode::nextw(){
  return nextNode;
}

newFileNode* newWordNode::listpointer() {
  return head_list;
}
