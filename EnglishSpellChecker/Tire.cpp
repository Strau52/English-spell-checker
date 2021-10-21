#include "Tire.h"

Trie::Trie()
{
	mHead = std::make_shared<Node>();
}

// Note: 'a' ASCII => 97
void Trie::Insert(const std::string word)
{
	auto head = mHead;
	for (char c : word)
	{
		int number = int(c) - 97;
		if (number >= 0 && number < 26)
		{
			(head->mChildren[number] == NULL) ? head->mChildren[number] = std::make_shared<Node>(), head = head->mChildren[number] : head = head->mChildren[number];
		}
	}
	head->mWordEnded = true;
}

bool Trie::ChechIfCorrectWord(const std::string word) const
{
	auto head = mHead;

	int idx = 0;
	int charValue = int(word.at(idx)) - 97;

	while (charValue < 26 && charValue >= 0 && idx < word.length() && head->mChildren[charValue] != NULL)
	{
		head = head->mChildren[charValue];
		idx++;
		if (idx != word.length())
			charValue = int(word.at(idx)) - 97;

	}
	return (idx == word.length() && head->mWordEnded);
}
