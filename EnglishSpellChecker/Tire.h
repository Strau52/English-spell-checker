#pragma once
#include "Node.h"
#include <string>

class Trie
{
public:
	Trie();
	void Insert(const std::string word);
	bool ChechIfCorrectWord(const std::string word) const;
private:
	std::shared_ptr<Node> mHead;
};