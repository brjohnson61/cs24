//Adam Gulliver and Blake Johnson


#ifndef BAG_H_
#define BAG_H_
#include "lol.h"
#include <string>
#include <vector>
#include <algorithm>
#include <boost/algorithm/string.hpp>

using namespace std;

class Bag
{
 public:
  Bag ();
  virtual ~Bag ();
  void insert(const string& word, const string& fileName, int count);
  pair<string, int> lookupFirst(const string& word);
  pair<string, int> lookupRandom(const string& word);
  void lookupAll(const string& word, vector<pair<string, int> >& items);
  void lookupAllOR(const vector<string>& wordvec, vector<string>& filesvec);
  void lookupAllAND(const vector<string>& wordvec, vector<string>& filesvec);

  // don't change anything before here
 private:
  newWordNode* head_ptr;
 // add your private functions declaration here
};

#endif /* end of include guard: BAG_H_ */
