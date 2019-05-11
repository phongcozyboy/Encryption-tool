#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>

class Huffman
{
private:
	class Node
	{
	public:
		char data;
		int freq;
		Node *left, *right;
		Node(char data, int freq)
		{
			this->data = data;
			this->freq = freq;
			this->left = this->right = nullptr;
		}
	};
	typedef class Node* Tree;

	class Compare
	{
	public:
		bool operator()(Node *left, Node *right)
		{
			return left->freq > right->freq;
		}
	};

	std::string pathStr, encodeString, decodeString;
	std::map<char, int> freq;
	std::map<char, std::string> codes;
	std::priority_queue<Node *, std::vector<Node *>, Compare> minHeap;

	void countFreq()
	{
		for (int i = 0; i < this->pathStr.size(); i++)
			this->freq[this->pathStr[i]]++;
	}

	void storeCodes(Tree root, std::string str)
	{
		if (root == nullptr) return;

		if (root->freq != '$') this->codes[root->data] = str;
		storeCodes(root->left, str + "0");
		storeCodes(root->right, str + "1");
	}

	void huffman()
	{
		Node *left, *right, *top;
		for (auto i = freq.begin(); i != freq.end(); i++) this->minHeap.push(new Node(i->first, i->second));

		while (this->minHeap.size() != 1)
		{
			left = this->minHeap.top(); this->minHeap.pop();
			right = this->minHeap.top(); this->minHeap.pop();
			top = new Node('$', left->freq + right->freq);
			top->left = left;
			top->right = right;
			this->minHeap.push(top);
		}
		storeCodes(this->minHeap.top(), "");
	}

public:
	Huffman();
	Huffman(std::string str);
	~Huffman();

	std::string getEncode();
	std::string getDecode();
};

