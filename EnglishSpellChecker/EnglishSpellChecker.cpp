#include "Node.h"
#include "Tire.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<std::string> SplitSentence(const std::string sentence)
{
	std::vector<std::string> words;
	std::string actWord = "";

	for (auto character : sentence)
		(character == ' ') ? words.push_back(actWord), actWord = "" : actWord += character;
	words.push_back(actWord);

	return words;
}

int main()
{
	Trie trieTree;
	std::ifstream inputFile("wordsEn.txt");


	if (inputFile.is_open())
	{
		std::string s;
		while (!inputFile.eof())
		{
			std::getline(inputFile, s);
			if (s.find('\'') == std::string::npos)
			{
				trieTree.Insert(s);
			}
		}
	}

	inputFile.close();
	std::cout << "Please give me the sentence you want to gramatically check: " << std::endl;
	std::string sentence;
	std::getline(std::cin, sentence);

	std::vector<std::string> words = SplitSentence(sentence);

	bool isCorrect = true;
	int index = 0;
	while (isCorrect == true && index < words.size())
	{
		isCorrect = trieTree.ChechIfCorrectWord(words[index]);
		index++;
	}

	isCorrect ? std::cout << "Your sentence is gramatically correct!" << std::endl : std::cout << "The sentence is gramatically not correct!" << std::endl;
}