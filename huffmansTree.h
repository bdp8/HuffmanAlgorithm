#ifndef HUFFMANSTREE_H_
#define HUFFMANSTREE_H_

#include "frequencyTable.h"
#include <queue>
using std::queue;


struct treeNode
{
	char val;
	int weight;

	treeNode *left, *right;

	treeNode(int weight = 0, treeNode* left = nullptr, treeNode* right = nullptr, const char val = '#') :
		weight(weight), left(left), right(right), val(val) {}

	void print()
	{
		cout << weight << " " << val << endl;
	}

};

class HuffmanTree
{
private:
	treeNode * root;

	void deleteTree(treeNode*& tree);
	treeNode* copyTree(treeNode* from);

public:

	HuffmanTree(int data = 0, treeNode *left = nullptr, treeNode *right = nullptr, char symbol = '#')
	{
		this->root = new treeNode(data, copyTree(left), copyTree(right), symbol);
	}

	HuffmanTree(HuffmanTree const& other);
	HuffmanTree& operator=(HuffmanTree const& other);
	~HuffmanTree();


	void printNode(treeNode* tree, std::ostream& os);
	treeNode* getRoot() { return this->root; }

	HuffmanTree makeTree(FrequencyTable t);

	queue<HuffmanTree> addElementToQueue(queue<HuffmanTree>& qu, HuffmanTree tree);

};

std::ostream& operator<<(std::ostream& out, HuffmanTree& t);
#endif HUFFMANSTREE_H_
#pragma once
