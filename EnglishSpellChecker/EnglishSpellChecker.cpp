#include <iostream>
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
    std::cout << "Hello World!\n";
}