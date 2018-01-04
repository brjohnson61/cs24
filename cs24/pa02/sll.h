#ifndef SLL_H
#define SLL_H
#include <vector>
#include <string>
#include <utility>
using namespace std;

struct Node {
	pair<pair<string, string>, int> data;
	Node* next;
};

class pairlist {
public:
	pairlist();
	virtual ~pairlist();
	void insertPair(const string& word, const string& fileName, int count);
	pair<string, int> findPair(const string& word);
	pair<string, int> randoPair(const string& word);
	void findAll(const string& word, vector<pair<string, int>>& items);

private:
	Node* first;
};

#endif