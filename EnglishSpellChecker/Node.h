#pragma once
#include <vector>
#include <memory>

class Node
{
public:
	Node();
	bool mWordEnded;
	std::vector<std::shared_ptr<Node>> mChildren; //komment
};

