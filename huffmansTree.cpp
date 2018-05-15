#include "huffmansTree.h"

void HuffmanTree::deleteTree(treeNode*& tree)
{
	if (!tree)
	{
		deleteTree(tree->left);
		deleteTree(tree->right);
		delete tree;
	}
}


void HuffmanTree::printNode(treeNode* tree, std::ostream& os)
{
	if (tree != nullptr)
	{
		if (tree->left != nullptr)
		{
			os << (tree->weight) << " " << (tree->left->weight) << " " << tree->left->val << endl;
		}

		if (tree->right != nullptr)
		{
			os << (tree->weight) << " " << (tree->right->weight) << " " << tree->right->val << endl;
		}

		if (tree->left != nullptr)
			printNode(tree->left, os);
		if (tree->right != nullptr)
			printNode(tree->right, os);
	}


}


treeNode* HuffmanTree::copyTree(treeNode* from)
{
	if (from == nullptr)
		return nullptr;

	return new treeNode(from->weight, copyTree(from->left), copyTree(from->right), from->val);
}

HuffmanTree::HuffmanTree(HuffmanTree const& other)
{
	root = copyTree(other.root);
}


HuffmanTree& HuffmanTree::operator=(HuffmanTree const& other)
{
	if (this != &other)
	{
		deleteTree(root);
		root = copyTree(other.root);
	}
	return *this;
}

HuffmanTree::~HuffmanTree()
{
	deleteTree(root);
}

HuffmanTree HuffmanTree::makeTree(FrequencyTable t)
{
	queue<HuffmanTree> trees;
	for (int i = 0; i<t.size(); i++)
	{
		trees.push(HuffmanTree(t[i].num, nullptr, nullptr, t[i].symbol));
	}

	while (trees.size() > 1)
	{

		HuffmanTree one = trees.front();
		trees.pop();

		HuffmanTree two = trees.front();
		trees.pop();


		HuffmanTree res(one.getRoot()->weight + two.getRoot()->weight, one.getRoot(), two.getRoot());
		trees = addElementToQueue(trees, res);
	}
	return trees.front();
}


queue<HuffmanTree> HuffmanTree::addElementToQueue(queue<HuffmanTree>& qu, HuffmanTree tree)
{
	queue<HuffmanTree> temp;
	while (!qu.empty() && tree.getRoot()->weight > qu.front().getRoot()->weight)
	{
		temp.push(qu.front());
		qu.pop();
	}

	temp.push(tree);

	while (!qu.empty())
	{
		temp.push(qu.front());
		qu.pop();
	}

	return temp;
}


std::ostream& operator<<(std::ostream& out, HuffmanTree& t)
{
	if (t.getRoot() == nullptr) return out;

	t.printNode(t.getRoot(), out);

	return out;
}
