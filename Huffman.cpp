#include "Huffman.h"


Huffman::Huffman()
{

}

Huffman::Huffman(std::string str)
{
	this->pathStr = str;
}


Huffman::~Huffman()
{
}

std::string Huffman::getDecode()
{
	Node *cur = this->minHeap.top();

	for (int i = 0; i < this->encodeString.size(); i++)
	{
		if (this->encodeString[i] == '0') cur = cur->left;
		else cur = cur->right;

		if (cur->left == nullptr && cur->right == nullptr)
		{
			this->decodeString += cur->data;
			cur = this->minHeap.top();
		}
	}
	return this->decodeString + '\0';
}

std::string Huffman::getEncode()
{
	this->countFreq();
	this->huffman();

	for (auto i : this->pathStr) this->encodeString += this->codes[i];
	return this->encodeString;
}